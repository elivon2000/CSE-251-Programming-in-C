#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "transistors.h"

struct Transistor InputTransistor()
{
  struct Transistor t1;
  InputString(t1.number, sizeof(t1.number));
  t1.type = InputTransistorType("Input type [1-NPN,2-PNP]: ");
  t1.caseStyle = InputCaseStyle("Input type [1-TO18,2-TO92A,3-TO92C,4-TO220,5-TO39]: ");
  t1.pmax = InputPositiveValue("Input pMax: ");
  t1.icmax = InputPositiveValue("Input icMax: ");
  return t1;
}

void DisplayTransistor(Tran tran)
{
  printf("Number: %s\n", tran.number);
  switch (tran.type)
  {
  case NPN:
    printf("Type: NPN\n");
    break;

  case PNP:
    printf("Type: PNP\n");
    break;
  }
  DisplayCaseStyle(tran.caseStyle);
  printf("pMax: %.3f\n", tran.pmax);
  printf("icMax: %.3f\n", tran.icmax);
}

void DisplayCaseStyle(int caseStyle)
{
  switch (caseStyle)
  {
  case TO18:
    printf("CaseStyle: TO18\n");
    break;
  case TO92A:
    printf("CaseStyle: TO92A\n");
    break;
  case TO92C:
    printf("CaseStyle: TO92C\n");
    break;
  case TO220:
    printf("CaseStyle: TO220\n");
    break;
  case TO39:
    printf("CaseStyle: TO39\n");
    break;
  default:
    printf("CaseStyle: unkown\n");
  }
}

void InputString(char *str, int max)
{
  char buffer[100];
  /* Get a line of up to 100 characters */
  printf("number: ");
  fgets(buffer, sizeof(buffer), stdin);
  /* Remove any stray newlines from the buffer */
  while (buffer[0] == '\n')
    fgets(buffer, sizeof(buffer), stdin);
  /* Remove any \n we may have input */
  if (strlen(buffer) > 0)
    buffer[strlen(buffer) - 1] = '\0';
  /* Copy up to max characters to our string */
  strncpy(str, buffer, max);
  str[max - 1] = '\0';
}

double InputPositiveValue(char *prompt)
{
  char buffer[100];
  double value = 0;
  do
  {
    printf("%s", prompt);

    /* Get a line of up to 100 characters */
    fgets(buffer, sizeof(buffer), stdin);

    /* Remove any \n we may have input */
    if (strlen(buffer) > 0)
      buffer[strlen(buffer) - 1] = '\0';

    sscanf(buffer, "%lf", &value);
  } while (value <= 0);

  return value;
}

int InputTransistorType(char *prompt)
{
  char buffer[100];
  int value = 0;
  do
  {
    printf("%s", prompt);
    /* Get a line of up to 100 characters */
    fgets(buffer, sizeof(buffer), stdin);
    /* Remove any \n we may have input */
    if (strlen(buffer) > 0)
      buffer[strlen(buffer) - 1] = '\0';
    sscanf(buffer, "%d", &value);
  } while (value != NPN && value != PNP);
  return value;
}

int InputCaseStyle(char *prompt)
{
  char buffer[100];
  int value = 0;
  do
  {
    printf("%s", prompt);
    /* Get a line of up to 100 characters */
    fgets(buffer, sizeof(buffer), stdin);
    /* Remove any \n we may have input */
    if (strlen(buffer) > 0)
      buffer[strlen(buffer) - 1] = '\0';
    sscanf(buffer, "%d", &value);
  } while (value < 1 || value > 5);
  return value;
}

bool InputYesOrNo(char *prompt)
{
  char buffer[100];
  char choice = 'a';
  do
  {
    printf("%s", prompt);
    /* Get a line of up to 100 characters */
    fgets(buffer, sizeof(buffer), stdin);
    /* Remove any \n we may have input */
    if (strlen(buffer) > 0)
      buffer[strlen(buffer) - 1] = '\0';
    if (strlen(buffer) != 1)
      continue;
    choice = toupper(buffer[0]);
  } while (choice != 'Y' && choice != 'N');
  return choice == 'Y';
}