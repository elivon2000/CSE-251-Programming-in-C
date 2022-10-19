#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "schedule.h"
#include "io.h"
#include "display.h"

void InsertScheduleItem(Schedule *pschedule);
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
  displayMenu();
  do
  {
    option = InputOption("Please select an option: ");
    switch (option)
    {
    case Exit:
      break;
    case Insert:
      InsertScheduleItem(&schedule);
      break;
    case Now:
      break;
    case Delete:
      break;
    }
  } while (option != Exit);

  system("pause");
  return 0;
}

void InsertScheduleItem(Schedule *pschedule)
{
  Event event;
  int position;
  Event *newEvents;
  InputDescription("What is the event: ", event.description, sizeof(event.description));
  event.date = InputDate("Event date: ");
  event.start = InputTime("Start time: ", event.date);
  event.end = InputTime("End time: ", event.date);

  position = findPositionInList(pschedule, &event);

  if (pschedule->numEvents == 0)
  {
    newEvents = malloc(sizeof(Event));
  }
  else
  {
    newEvents = realloc(pschedule->events, sizeof(Event) * (pschedule->numEvents + 1));
  }
  if (newEvents)
  {
    pschedule->events = newEvents;
    pschedule->numEvents++;
    pschedule->events[pschedule->numEvents] = event;
  }
  else
  {
    printf("realloc fail!\n\n");
  }
}
