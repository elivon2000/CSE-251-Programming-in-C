#ifndef SCHEDULE_H
#define SCHEDULE_H

#define __USE_XOPEN
#include <time.h>

#define FileName "schedule.dat"
#define FileNameOut "schedule2.dat"
#define descriptionLength 51

typedef struct
{
  char description[descriptionLength];
  time_t start;
  time_t end;
} Event;

typedef struct
{
  int numEvents;
  Event *events;
} Schedule;

void insertEventToSchedule(Schedule *pschedule, Event event);
void romoveEvent(Schedule *pschedule, int index);
// void readLine(char *buffer, int maxsize, FILE *inFile);
void LoadFile(Schedule *pschedule);
void SaveFile(Schedule *pschedule);
void freeSchedule(Schedule *pschedule);

// function bellow is no use
int findPosToInsert(Schedule *pschedule, Event *pevent);

#endif