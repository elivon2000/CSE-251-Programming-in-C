#ifndef DISPLAY_H
#define DISPLAY_H

#include "schedule.h"

void displayMenu();
void DisplayString(char *str);
void DisplayEvents(Schedule *pschedule);
void DisplayEvent(Event *pevent);
void DisplayActiveEvents(Schedule *pschedule);
void DisplayOverlap(Schedule *pschedule, Event event);

#endif
