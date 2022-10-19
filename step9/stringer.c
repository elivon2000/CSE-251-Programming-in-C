#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Name : <Insert name>
 * Program to experiment with strings
 */

int StringLength(char str[]);
void PrintLength(char str[]);

int main()
{
  char word[] = "chudge";
  char myWord[80];
  char mySentence[80];
  int i;
  int len;
  char buff;

  printf("Enter a word: ");
  scanf("%79s", myWord);
  printf("The entered word is: %s\n", myWord);
  do
  {
    buff = getchar();
  } while (buff != '\n');

  printf("Enter a sentence: ");
  fgets(mySentence, 80, stdin);
  len = strlen(mySentence);
  mySentence[len - 1] = '\0';
  printf("The entered sentence is: %s\n", mySentence);

  PrintLength(word);
  PrintLength(myWord);
  PrintLength(mySentence);

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
  printf("The string %s is %d characters long\n", str, strlen(str));
}