#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  /* Remove the newline at the end of the line */
  mySentence[len - 1] = '\0';
  printf("The entered sentence is: \"%s\"\n", mySentence);

  PrintLength(mySentence);
  Reverse(mySentence);
  printf("\"%s\"\n", mySentence);
  printf("The number of spaces is: %d\n", NumberOfSpaces(mySentence));
  printf("The number of 'i' is: %d\n", NumberOfAppearances(mySentence, 'i'));

  system("pause");
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
void PrintLength(char str[])
{
  printf("The string \"%s\" is %d characters long\n", str, strlen(str));
}

void Reverse(char str[])
{
  int front = 0;
  int back = strlen(str) - 1;
  char t; /* A temporary place to put a character */
  while (front < back)
  {
    t = str[front];
    str[front] = str[back];
    str[back] = t;
    front++;
    back--;
  }
}
int NumberOfSpaces(char str[])
{
  int i, num = 0;
  char ch = ' ';
  for (i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == ch)
      num++;
  }
  return num;
}

char lowerCase(char ch)
{ //把大写转成小写
  if (ch >= 'A' && ch <= 'Z')
  {
    ch += (int)'a' - (int)'A';
  }
  return ch;
}
int NumberOfAppearances(char str[], char ch)
{
  int i, num = 0;
  char lowerChar = lowerCase(ch);
  for (i = 0; str[i] != '\0'; i++)
  {
    if (lowerCase(str[i]) == lowerChar)
      num++;
  }
  return num;
}