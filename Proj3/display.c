#include <stdio.h>
#include <stdlib.h>

#include "display.h"

void displayMenu()
{
  printf("1 - Insert a new event\n");
  printf("2 - Display all events\n");
  printf("3 - Now?\n");
  printf("4 - Delete expired\n");
  printf("0 - Exit\n");
}

void DisplayEvents(Schedule *pschedule)
{
  int i;
  printf("\nSchedule:\n");
  for (i = 0; i < pschedule->numEvents; i++)
  {
    DisplayEvent(&pschedule->events[i]);
  }
  printf("\n");
}

void DisplayActiveEvents(Schedule *pschedule)
{
  int i;
  int count = 0;
  time_t curTime = time(0);
  printf("%s", "Currently active events: \n");
  for (i = 0; i < pschedule->numEvents; i++)
  {
    if (curTime >= pschedule->events[i].start && curTime <= pschedule->events[i].end)
    {
      count++;
      DisplayEvent(&pschedule->events[i]);
    }
  }
  if (count == 0)
  {
    printf("%s", "No Currently active events.\n");
  }
}

void DisplayEvent(Event *pevent)
{
  struct tm *pTM;
  char buffer[80];
  pTM = localtime(&pevent->start);
  strftime(buffer, 80, "%m/%d/%Y %I:%M%p", pTM);
  printf("%s", buffer);
  pTM = localtime(&pevent->end);
  strftime(buffer, 80, " - %I:%M%p", pTM);
  printf("%s", buffer);
  printf(" %s\n", pevent->description);
}
void DisplayString(char *str)
{
  printf("%s", str);
}

void DisplayOverlap(Schedule *pschedule, Event event)
{
  int i;
  for (i = 0; i < pschedule->numEvents; i++)
  {
    // not overlap if A ends before B starts or A starts after B ends.
    if (event.end > pschedule->events[i].start && event.start < pschedule->events[i].end)
    {
      printf("%s", "[Warning, this event overlaps]: ");
      DisplayEvent(&pschedule->events[i]);
    }
  }
}