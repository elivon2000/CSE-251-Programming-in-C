#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "input.h"

Event InputEvent()
{
  Event event;
  time_t date;
  InputDescription("What is the event: ", event.description, sizeof(event.description));
  date = InputDate("Event date: ");
  event.start = InputTime("Start time: ", date);
  event.end = InputTime("End time: ", date);
  return event;
}
void InputDescription(char *prompt, char desc[], int descLen)
{
  char buffer[100];
  do
  {
    printf("%s", prompt);
    fgets(buffer, sizeof(buffer), stdin);
    clearTail(buffer);
  } while (strlen(buffer) < 1);
  strncpy(desc, buffer, descLen);
  desc[descLen - 1] = '\0';
}

int InputOption(char *prompt)
{
  char buffer[100];
  int value = -1;
  int len;
  do
  {
    if (feof(stdin))
      return 0;
    printf("%s", prompt);
    fgets(buffer, sizeof(buffer), stdin);
    clearTail(buffer);
    sscanf(buffer, "%d", &value);
    len = strlen(buffer);
  } while (len != 1 || value < 0 || value >= 5);
  return value;
}
void clearTail(char buffer[])
{
  int end = strlen(buffer) - 1;
  while (end >= 0 && (buffer[end] == '\n' || buffer[end] == '\r'))
  {
    buffer[end] = '\0';
    end--;
  }
}

bool InputYesOrNo(char *prompt)
{
  char buffer[100];
  char choice = 'a';
  do
  {
    printf("%s", prompt);
    fgets(buffer, sizeof(buffer), stdin);
    clearTail(buffer);
    if (strlen(buffer) != 1)
      continue;
    choice = toupper(buffer[0]);
  } while (choice != 'Y' && choice != 'N');
  return choice == 'Y';
}

void InputAnything()
{
  char buffer[100];
  fgets(buffer, sizeof(buffer), stdin);
}

time_t InputDate(char *prompt)
{
  char buffer[100];
  char *result;
  struct tm date;
  do
  {
    printf("%s", prompt);
    fgets(buffer, sizeof(buffer), stdin);
    clearTail(buffer);
    result = strptime(buffer, "%m/%d/%Y", &date);
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
    clearTail(buffer);
    result = strptime(buffer, "%I:%M%p", &time);
  } while (result == NULL);
  return mktime(&time);
}
