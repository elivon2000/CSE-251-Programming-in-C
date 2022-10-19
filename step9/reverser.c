#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * Name : <Insert name>
 * Program to experiment with files
 */
void Reverse(char str[]);
void read_file1();

int main(int argc, char *argv[])
{
  FILE *inFile;
  FILE *outFile;
  char line[120];
  char *res;
  int i, len;
  if (argc < 3)
  {
    printf("Insufficient arguments\n");
    return 1;
  }
  printf("Copy from file: %s\n", argv[1]);
  printf("Copy to file: %s\n", argv[2]);

  inFile = fopen(argv[1], "r");
  if (inFile == NULL)
  {
    printf("Unable to open file %s\n", argv[1]);
    return 1;
  }
  outFile = fopen(argv[2], "w");
  if (outFile == NULL)
  {
    printf("Unable to open file %s\n", argv[2]);
    return 1;
  }
  /* While we are not at the end of the file */
  while (!feof(inFile))
  {
    /* Read a line of text from the file */
    res = fgets(line, sizeof(line), inFile);
    if (res == NULL)
      break;
    Reverse(line);
    fprintf(outFile, "%s", line);
  }
  fclose(inFile);
  fclose(outFile);

  system("pause");
}

void Reverse(char str[])
{
  int front = 0;
  int back = strlen(str) - 1;
  char t; /* A temporary place to put a character */
  //最后的回车符不要reverse
  if (str[back] == '\n')
    back--;

  while (front < back)
  {
    t = str[front];
    str[front] = str[back];
    str[back] = t;
    front++;
    back--;
  }
}

// char *fgets(char *s, int n, FILE *stream)
// { //结束条件：读够字符数、读取不到、读到回车符
//   register int c;
//   register char *cs;
//   cs = s;
//   while (--n > 0 && (c = getc(stream)) != EOF)
//   {
//     if ((*cs++ = c) == '\n')
//       break;
//   }
//   *cs = '\0';
//   return (c == EOF && cs == s) ? NULL : s;
// }
