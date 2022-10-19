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

void DisplayEvents(Schedule *schedule)
{
  int i;

  printf("\nSchedule:\n");
  for (i = 0; i < schedule->numEvents; i++)
  {
    // DisplayEvent(&schedule->events[i]);
  }

  printf("\n");
}
// void DisplayEvent()
// {
// }