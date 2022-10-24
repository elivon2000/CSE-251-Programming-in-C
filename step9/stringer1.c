#include <stdio.h>
#include <string.h>

/*
 * Name : elivon
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

  printf("Enter a word: ");
  scanf("%79s", myWord);
  myWord[79] = '\0';
  printf("The entered word is: %s\n", myWord);

  fgets(mySentence, 80, stdin);

  printf("Enter a sentence: ");
  fgets(mySentence, 80, stdin);
  len = strlen(mySentence);
  mySentence[len - 1] = '\0';
  printf("The entered sentence is: %s\n", mySentence);

  PrintLength(word);
  PrintLength(myWord);
  PrintLength(mySentence);
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