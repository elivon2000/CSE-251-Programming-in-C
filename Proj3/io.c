#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "io.h"
#include "strptime_diy.h"

void InputDescription(char *prompt, char desc[], int descLen)
{
  char buffer[100];
  int len;
  do
  {
    printf("%s", prompt);
    fgets(buffer, sizeof(buffer), stdin);
    len = strlen(buffer);
    if (len > 0)
    {
      buffer[len - 1] = '\0';
      len--;
    }
  } while (len <= 0);
  strncpy(desc, buffer, descLen);
  desc[descLen - 1] = '\0';
}

int InputOption(char *prompt)
{
  char buffer[100];
  int value = -1;
  int len = 0;
  do
  {
    printf("%s", prompt);
    /* Get a line of up to 100 characters */
    fgets(buffer, sizeof(buffer), stdin);
    /* Remove any \n we may have input */
    len = strlen(buffer);
    if (strlen(buffer) > 0)
      buffer[strlen(buffer) - 1] = '\0';
    sscanf(buffer, "%d", &value);
  } while (value < 0 || value >= 5);
  return value;
}

time_t InputDate(char *prompt)
{
  char buffer[100];
  char *result;
  struct tm date;
  do
  {
    printf("%s", prompt);
    /* Get a line of up to 100 characters */
    fgets(buffer, sizeof(buffer), stdin);
    /* Remove any \n we may have input */
    if (strlen(buffer) > 0)
      buffer[strlen(buffer) - 1] = '\0';
    result = strptime_diy(buffer, "%m/%d/%Y", &date);
  } while (result == NULL);
  /* Convert to time_t format */
  date.tm_min = 0;
  date.tm_hour = 0;
  date.tm_sec = 0;
  date.tm_isdst = 1;
  return mktime(&date);
}

time_t InputTime(char *prompt, time_t date)
{
  char buffer[100];
  char *result;
  struct tm time;
  time = *localtime(&date);
  do
  {
    printf("%s", prompt);
    /* Get a line of up to 100 characters */
    fgets(buffer, sizeof(buffer), stdin);
    /* Remove any \n we may have input */
    if (strlen(buffer) > 0)
      buffer[strlen(buffer) - 1] = '\0';
    result = strptime_diy(buffer, "%I:%M%p", &time);
  } while (result == NULL);
  return mktime(&time);
}