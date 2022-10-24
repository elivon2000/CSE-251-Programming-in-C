#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * Name : elivon
 * Program to experiment with strings
 */

int StringLength(char str[]);
void PrintLength(char str[]);
void Reverse(char str[]);
int NumberOfSpaces(char str[]);
int NumberOfAppearances(char str[], char ch);

int main()
{
  char mySentence[80];
  int len;

  printf("Enter a sentence: ");
  fgets(mySentence, 80, stdin);
  len = strlen(mySentence);
  mySentence[len - 1] = '\0';
  printf("The entered sentence is: %s\n", mySentence);
  printf("The number of spaces is: %d\n", NumberOfSpaces(mySentence));
  printf("The number of 'i' is: %d\n", NumberOfAppearances(mySentence, 'i'));

  PrintLength(mySentence);
  Reverse(mySentence);
  printf("%s\n", mySentence);
}

void PrintLength(char str[])
{
  printf("The string %s is %lu characters long\n", str, strlen(str));
}

int StringLength(char str[])
{
  int numChars = 0;
  while (str[numChars] != '\0')
  {
    numChars++;
  }
  return numChars;
}

void Reverse(char str[])
{
  int front = 0;
  int back = strlen(str) - 1;
  char t; /* A temporary place to put a character */
  while (front < back)
  {
    // printf("front=%d back=%d\n", front, back);
    t = str[front];
    str[front] = str[back];
    str[back] = t;
    front++;
    back--;
  }
}

int NumberOfSpaces(char str[])
{
  int i;
  int numSpaces = 0;
  for (i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == ' ')
      numSpaces++;
  }
  return numSpaces;
}

int NumberOfAppearances(char str[], char ch)
{
  int i;
  int num = 0;
  int upper_ch = toupper(ch);
  for (i = 0; str[i] != '\0'; i++)
  {
    if (toupper(str[i]) == upper_ch)
      num++;
  }
  return num;
}