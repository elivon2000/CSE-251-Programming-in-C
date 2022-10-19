#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <time.h>

typedef struct
{
  char description[51];
  time_t date;
  time_t start;
  time_t end;
} Event;

typedef struct
{
  int numEvents;
  Event *events;
} Schedule;

int findPositionInList(Schedule *pschedule, Event *pevent);

#endif