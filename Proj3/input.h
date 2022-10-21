#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>

#include "schedule.h"

void clearTail(char buffer[]);
void InputDescription(char *prompt, char desc[], int descLen);
int InputOption(char *prompt);
bool InputYesOrNo(char *prompt);
void InputAnything();
time_t InputDate(char *prompt);
time_t InputTime(char *prompt, time_t date);
Event InputEvent();

#endif