#include <stdio.h>
#include <stdlib.h>

/*
 * Name : elivon
 * Program to experiment with character arrays
 */

#define MaxWord 20

int main()
{
  char c;
  char str[MaxWord + 1];
  int len = 0;
  int lenthCount = 0;
  int wordsCount = 0;
  double aveLen;
  char longestWord[MaxWord + 1];
  int maxLen = 0, index;
  longestWord[0] = 0;

  puts("Enter text. Include a dot ('.') to end a sentence to exit:");
  do
  {
    c = getchar();
    if (c != ' ' && c != '.' && c != '\n' && c != '\r' && c != '\t' && len < MaxWord)
    {
      /* This is a character of a word */
      str[len] = c;
      len++;
    }
    else
    {
      /* The word is done */
      str[len] = 0;
      if (len > 0)
      {
        printf("%s\n", str);
        // 2)Count
        wordsCount += 1;
        lenthCount += len;
        // 3)Save the longest word
        if (len > maxLen)
        {
          maxLen = len;
          for (index = 0; index <= len; index++)
          { // copy the str and end with '\0'
            longestWord[index] = str[index];
          }
        }
      }
      len = 0;
      if (c != ' ' && c != '.' && c != '\n' && c != '\r' && c != '\t')
      {
        str[len] = c;
        len++;
      }
    }

  } while (c != '.');
  aveLen = (double)lenthCount / (double)wordsCount;
  printf("2)The average word length is %.2lf\n", aveLen);
  printf("3)The longest word entered is %s.\n", longestWord);
}