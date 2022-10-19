#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "ElevatorLib.h"

/*
 * Name :        elivon
 * Description : Project 2 (part B) - The elevator controller
 */

#define N 200
#define FLOOR_MIN 1
#define FLOOR_MAX 3
#define stop_speed (FloorTolerance / (FloorSpacing / 2) / 10)
#define min_distance (FloorTolerance / FloorSpacing)

#define Idle 0
#define Moving 1
#define OpenDoor 2
#define ClosingDoor 3

// PID Control
const double Kp = 5, Ki = 3, Kd = 3;
const double dt = 0.001;
double errors[N];
int errorLoc = -1;
double errorTotal = 0;
double desiredSpeed = 0;
bool brakeFlag = true;

// State
int state = Idle;
bool goingUp = true;
int print_count = 0;

void StateIdle();
void StateMoving();
void StateOpenDoor();
void StateClosingDoor();
void Init_PID_Ctrl();
void stop_PID_Ctrl();
bool checkGoForward(int floor);
void execute_PID_Ctrl();
void calcurateDesiredSpeed();
void onStopAtFloor(int floor);

int main()
{
  printf("Elevator Startup\n");
  ElevatorStartup();
  state = Idle;
  while (IsElevatorRunning())
  {
    switch (state)
    {
    case Idle:
      StateIdle();
      break;
    case Moving:
      StateMoving();
      break;
    case OpenDoor:
      StateOpenDoor();
      break;
    case ClosingDoor:
      StateClosingDoor();
      break;
    }
  }
  printf("Elevator Shutdown\n");
  ElevatorShutdown();
  return 0;
}

void StateIdle()
{
  int gotoFloor = WhatFloorToGoTo(goingUp);
  int curFloor = GetNearestFloor();
  printf("gotoFloor=%d curFloor=%d goingUp=%d\n", gotoFloor, curFloor, goingUp);
  if (gotoFloor >= FLOOR_MIN && gotoFloor <= FLOOR_MAX)
  {
    if (curFloor == gotoFloor)
    {
      onStopAtFloor(curFloor);
    }
    else
    {
      state = Moving;
      goingUp = (gotoFloor > curFloor);
      Init_PID_Ctrl();
    }
  }
}
void StateMoving()
{
  // Where are we going?
  int gotoFloor = WhatFloorToGoToInThisDirection(goingUp);
  double distance = fabs(GetFloor() - gotoFloor);
  if (distance < min_distance && GetVelocity() < stop_speed)
  {
    // The alevator is arived.
    stop_PID_Ctrl();
    onStopAtFloor(gotoFloor);
  }
  else
  { // not arived
    calcurateDesiredSpeed();
    execute_PID_Ctrl();
  }
}
void StateOpenDoor()
{
  if (GetTimer() >= 3)
  {
    state = ClosingDoor;
    SetDoor(GetNearestFloor(), false);
  }
}
void StateClosingDoor()
{
  int i;
  bool all_closed = true;
  for (i = FLOOR_MIN; i <= FLOOR_MAX; i++)
  {
    all_closed = all_closed && IsDoorClosed(i);
  }
  if (all_closed)
  {
    state = Idle;
  }
}

void Init_PID_Ctrl()
{
  int i;
  double power = 0;
  for (i = 0; i < N; i++)
    errors[i] = 0;
  errorLoc = -1;
  errorTotal = 0;
  desiredSpeed = 0;
  power = 0;
  brakeFlag = false;
  SetBrake(false);
  SetMotorPower(power);
}
void stop_PID_Ctrl()
{
  desiredSpeed = 0;
  brakeFlag = true;
  SetBrake(true);
  SetMotorPower(0);
}
void execute_PID_Ctrl()
{
  double error, delta_error, power;
  int lastLoc = errorLoc;
  error = desiredSpeed - GetVelocity();
  errorLoc = (errorLoc + 1) % N;
  errorTotal += error - errors[errorLoc];
  errors[errorLoc] = error;
  delta_error = (lastLoc == -1) ? 0 : (errors[errorLoc] - errors[lastLoc]);
  power = Kp * error + Ki * errorTotal * dt + Kd * delta_error / dt;
  SetMotorPower(power);
}
void calcurateDesiredSpeed()
{
  int gotoFloor = WhatFloorToGoToInThisDirection(goingUp);
  int speedDirection = GetFloor() < gotoFloor ? 1 : -1;
  double distance = fabs(GetFloor() - gotoFloor);
  double fabsSpeed = distance >= 0.5 ? 1 : (distance / 0.5);
  desiredSpeed = speedDirection * fabsSpeed;
}

void onStopAtFloor(int floor)
{
  SetPanelFloorLight(floor, false);
  if (GetCallLight(floor, goingUp))
  {
    SetCallLight(floor, goingUp, false);
  }
  else
  {
    if (GetCallLight(floor, !goingUp) && !checkGoForward(floor))
    {
      goingUp = !goingUp;
      SetCallLight(floor, goingUp, false);
    }
  }
  state = OpenDoor;
  SetDoor(floor, true);
  ResetTimer();
}
bool checkGoForward(int floor)
{
  bool foreward = GetCallLight(floor, goingUp);
  int i, step;
  step = goingUp ? 1 : -1;
  for (i = floor + step; i >= FLOOR_MIN && i <= FLOOR_MAX; i += step)
  {
    foreward = foreward || GetCallLight(i, true) || GetCallLight(i, false) || GetPanelFloorLight(i);
  }
  return foreward;
}
