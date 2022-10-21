#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "schedule.h"
#include "input.h"
#include "display.h"

void onInsertOption(Schedule *pschedule);
void onDeleteExpired(Schedule *pschedule);

int main(int argc, char **argv)
{
  enum OptionName
  {
    Exit = 0,
    Insert = 1,
    Display = 2,
    Now = 3,
    Delete = 4
  };
  int option;
  Schedule schedule = {.numEvents = 0, .events = NULL};
  LoadFile(&schedule);
  displayMenu();
  do
  {
    option = InputOption("Please select an option: ");
    switch (option)
    {
    case Exit:
      freeSchedule(&schedule);
      break;
    case Insert:
      onInsertOption(&schedule);
      break;
    case Display:
      DisplayEvents(&schedule);
      break;
    case Now:
      DisplayActiveEvents(&schedule);
      break;
    case Delete:
      onDeleteExpired(&schedule);
      break;
    }
  } while (option != Exit);
  return 0;
}

void onInsertOption(Schedule *pschedule)
{
  Event event;
  event = InputEvent();
  DisplayOverlap(pschedule, event);
  insertEventToSchedule(pschedule, event);
  SaveFile(pschedule);
}
void onDeleteExpired(Schedule *pschedule)
{
  int i, count = 0;
  time_t curTime = time(0);
  for (i = 0; i < pschedule->numEvents; i++)
  {
    if (pschedule->events[i].end <= curTime)
    {
      count++;
      printf("%s", "[Deleting]: ");
      DisplayEvent(&pschedule->events[i]);
      romoveEvent(pschedule, i);
      i--;
    }
  }
  if (count == 0)
  {
    printf("%s", "No expired events.\n");
  }
  else
  {
    SaveFile(pschedule);
  }
}
