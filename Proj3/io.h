#ifndef IO_H
#define IO_H

#include <time.h>

void InputDescription(char *prompt, char desc[], int descLen);
int InputOption(char *prompt);
time_t InputDate(char *prompt);
time_t InputTime(char *prompt, time_t date);

#endif