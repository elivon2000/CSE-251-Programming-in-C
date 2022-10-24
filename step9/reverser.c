#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * Name : elivon
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
  while (!feof(inFile))
  {
    res = fgets(line, sizeof(line), inFile);
    if (res)
    {
      Reverse(line);
      fprintf(outFile, "%s", line);
    }
  }
  fclose(inFile);
  fclose(outFile);
}

void Reverse(char str[])
{
  int front = 0;
  int back = strlen(str) - 1;
  char t;
  // ignore '\n' and '\r' at the end
  while (back >= 0 && (str[back] == '\n' || str[back] == '\r'))
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
