#include "schedule.h"

int findPositionInList(Schedule *pschedule, Event *pevent)
{
  int numEvents = pschedule->numEvents;
  Event *events = pschedule->events;
  int begin = 0, end = numEvents;
  int position = (begin + end) / 2;
  while (begin > end)
  {
    if (pevent->start >= events[position].start)
    {
      begin = position + 1;
    }
    else
    {
      end = position - 1;
    }
    position = (begin + end) / 2;
  }
  return position;
}
