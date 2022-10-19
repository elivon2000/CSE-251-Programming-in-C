#include <stdio.h>
#include <stdlib.h>

#include "RobotLib.h"

/*
 * Name :        elivon
 * Description : Robot scheduler program
 */

// #define Home 0
// #define Working 1
// #define Idle 2

// int state = Home;
struct Request
{
  int machine;
  struct Request *next;
};
struct Request *firstInLine = NULL;
struct Request *lastInLine = NULL;

void OnMachineRequest(int machine);
int CountRequests();

int main()
{
  enum State
  {
    Home,
    Working,
    Idle
  } state = Home;
  int currMachine = 0;

  printf("Robot System Startup\n");
  SimulatorStartup();

  SetMachineRequestHandler(OnMachineRequest);

  /*
   * This loop runs until we shut the simulator down
   * by closing the window it runs in.
   */
  while (IsSimulatorRunning())
  {
    switch (state)
    {
    case Home:
      if (firstInLine != NULL)
      {
        state = Working;
      }
      break;
    case Idle:
      if (firstInLine != NULL)
      {
        state = Working;
      }
      else if (GetTimer() > 3)
      {
        state = Home;
        RobotGoTo(0);
        currMachine = 0;
      }
      break;
    case Working:
      if ((currMachine == 0 || !IsRobotBusy()) && firstInLine != NULL)
      {
        RobotGoTo(firstInLine->machine);
        currMachine = firstInLine->machine;
        /* Remove the first item from the queue */
        struct Request *wasFirst = firstInLine;
        firstInLine = firstInLine->next;
        free(wasFirst);
        /* Handle an empty queue */
        if (firstInLine == NULL)
        {
          lastInLine = NULL;
        }
      }
      if (!IsRobotBusy() && firstInLine == NULL)
      {
        state = Idle;
        ResetTimer();
      }
      break;
    }
  }
  /*
   * This call shuts down the elevator system
   */
  printf("Robot System Shutdown\n");
  SimulatorShutdown();
  return 0;
}

void OnMachineRequest(int machine)
{
  printf("Robot request from machine %d\n", machine);
  struct Request *newRequest = malloc(sizeof(struct Request));
  newRequest->machine = machine;
  newRequest->next = NULL;
  if (lastInLine != NULL)
  {
    /* This is the new last in the line */
    lastInLine->next = newRequest;
  }
  else
  {
    /* The queue is empty, make this the first request */
    firstInLine = newRequest;
  }

  /* The new request is already the last in line */
  lastInLine = newRequest;
  printf("There are %d pending requests\n", CountRequests());
}
int CountRequests()
{
  int cnt = 0;
  struct Request *request = firstInLine;
  while (request)
  {
    cnt++;
    request = request->next;
  }
  return cnt;
}
