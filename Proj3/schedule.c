#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "schedule.h"

void insertEventToSchedule(Schedule *pschedule, Event event)
{
  Event *newEvents;
  Event *events = pschedule->events;
  int num = pschedule->numEvents;
  int size = sizeof(Event) * (num + 1);
  int i;
  newEvents = (num == 0) ? malloc(size) : realloc(events, size);
  if (newEvents)
  {
    pschedule->events = newEvents;
    events = newEvents;
    pschedule->numEvents++;
    num++;
    // move and insert
    for (i = num - 1; i > 0 && events[i - 1].start > event.start; i--)
    {
      events[i] = events[i - 1];
    }
    events[i] = event;
  }
  else
  {
    printf("realloc fail!\n\n");
  }
}

void romoveEvent(Schedule *pschedule, int index)
{
  if (index < 0 || index >= pschedule->numEvents)
    return;
  pschedule->numEvents--;
  if (pschedule->numEvents == 0)
  {
    free(pschedule->events);
    return;
  }
  for (int i = index; i < pschedule->numEvents; i++)
  {
    pschedule->events[i] = pschedule->events[i + 1];
  }
}

void readLine(char buffer[], int maxsize, FILE *inFile)
{
  fgets(buffer, maxsize, inFile);
  int end = strlen(buffer) - 1;
  while (end >= 0 && (buffer[end] == '\n' || buffer[end] == '\r'))
  {
    buffer[end] = '\0';
    end--;
  }
}
void LoadFile(Schedule *pschedule)
{
  FILE *inFile;
  char buffer[100];
  int numEvents, i;
  Event event;
  struct tm tim;

  inFile = fopen(FileName, "r");
  if (inFile == NULL)
    return;

  readLine(buffer, sizeof(buffer), inFile);
  sscanf(buffer, "%d", &numEvents);
  if (numEvents <= 0)
  {
    fclose(inFile);
    return;
  }

  pschedule->numEvents = numEvents;
  pschedule->events = malloc(sizeof(Event) * numEvents);
  for (i = 0; i < numEvents && !feof(inFile); i++)
  {
    // description
    readLine(buffer, sizeof(buffer), inFile);
    strncpy(event.description, buffer, descriptionLength);
    event.description[descriptionLength - 1] = '\0';
    // start
    readLine(buffer, sizeof(buffer), inFile);
    strptime(buffer, "%a %b %d %H:%M:%S %Y", &tim);
    event.start = mktime(&tim);
    // end
    readLine(buffer, sizeof(buffer), inFile);
    strptime(buffer, "%a %b %d %H:%M:%S %Y", &tim);
    event.end = mktime(&tim);
    // store
    pschedule->events[i] = event;
  }
  fclose(inFile);
}
void SaveFile(Schedule *pschedule)
{
  if (pschedule->numEvents <= 0)
    return;
  FILE *outFile = fopen(FileNameOut, "w");
  int i;
  fprintf(outFile, "%d\n", pschedule->numEvents);
  for (i = 0; i < pschedule->numEvents; i++)
  {
    fprintf(outFile, "%s\n", pschedule->events[i].description);
    fprintf(outFile, "%s", ctime(&(pschedule->events[i].start)));
    fprintf(outFile, "%s", ctime(&(pschedule->events[i].end)));
  }
  fclose(outFile);
}

int findPosToInsert(Schedule *pschedule, Event *pevent)
{
  int numEvents = pschedule->numEvents;
  Event *events = pschedule->events;
  int begin = 0, end = numEvents;
  int position = (begin + end) / 2;
  while (begin < end)
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

void freeSchedule(Schedule *pschedule)
{
  if (pschedule->numEvents > 0)
    free(pschedule->events);
}