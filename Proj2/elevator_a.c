#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "ElevatorLib.h"

/*
 * Name :        elivon
 * Description : Project 2 (part A) - The elevator controller
 */

#define N 200
#define FLOOR_MIN 1
#define FLOOR_MAX 3
#define stop_speed (FloorTolerance / (FloorSpacing / 2) / 10)
#define min_distance (FloorTolerance / FloorSpacing)

#define Idle 0
#define Moving 1
#define Stoping 2

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

// record
double Sup = 0, Sdown = 0, Smax = 0;
double numSup = 0, numSdown = 0;

void StateIdle_A();
void StateMoving_A();
void StateStoping();

void Init_PID_Ctrl();
void stop_PID_Ctrl();
void execute_PID_Ctrl();
void calcurateDesiredSpeed_A();
void recordSpeed();
void displayRecord();

int main()
{

  printf("Elevator Startup\n");
  ElevatorStartup();
  // First run
  state = Idle;
  SetCallLight(1, true, true);
  while (IsElevatorRunning())
  {
    switch (state)
    {
    case Idle:
      StateIdle_A();
      break;
    case Moving:
      recordSpeed();
      StateMoving_A();
      break;
    case Stoping:
      StateStoping();
      break;
    }
  }
  displayRecord();
  ElevatorShutdown();
  return 0;
}

void StateIdle_A()
{
  if (GetNearestFloor() == FLOOR_MIN && GetCallLight(FLOOR_MIN, true))
  {
    SetCallLight(FLOOR_MIN, true, false);
    state = Moving;
    goingUp = true;
    ChangeLoading();
    Init_PID_Ctrl();
  }
}
void StateMoving_A()
{
  // Where are we going?
  int gotoFloor = goingUp ? FLOOR_MAX : FLOOR_MIN;
  double distance = fabs(GetFloor() - gotoFloor);
  if (distance < min_distance && GetVelocity() < stop_speed)
  {
    // The alevator is arived.
    stop_PID_Ctrl();
    state = Stoping;
    ResetTimer();
  }
  else
  { // not arived
    calcurateDesiredSpeed_A();
    execute_PID_Ctrl();
  }
}
void StateStoping()
{
  if (GetTimer() >= 0.1)
  {

    if (GetNearestFloor() == FLOOR_MAX && goingUp)
    {
      state = Moving;
      goingUp = !goingUp;
      ChangeLoading();
      Init_PID_Ctrl();
    }
    else
    {
      state = Idle;
    }
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
void calcurateDesiredSpeed_A()
{
  int gotoFloor = goingUp ? FLOOR_MAX : FLOOR_MIN;
  int speedDirection = GetFloor() < gotoFloor ? 1 : -1;
  double distance = fabs(GetFloor() - gotoFloor);
  double fabsSpeed = distance >= 0.5 ? 1 : (distance / 0.5);
  desiredSpeed = speedDirection * fabsSpeed;
}

void recordSpeed()
{
  // Averaging - get the average speed before the elevator starts slowing down
  if (goingUp && GetPosition() < 1.5 * FloorSpacing && GetPosition() > .5 * FloorSpacing)
  {
    Sup += GetVelocity();
    numSup += 1;
  }
  else if (!goingUp && GetPosition() > .5 * FloorSpacing && GetPosition() < 1.5 * FloorSpacing)
  {
    Sdown += GetVelocity();
    numSdown += 1;
  }
  if (fabs(GetVelocity()) > fabs(Smax))
    Smax = GetVelocity();
}
void displayRecord()
{
  Sup /= numSup;
  Sdown /= numSdown;
  double maxAvgError = fmax(fabs(Sup - 1), fabs(Sdown + 1));
  double maxMaxError = fmax(fabs(Smax) - fabs(Sup), fabs(Smax) - fabs(Sdown));
  printf("Elevator Shutdown\n");
  printf("Average speed up: %lf\n", Sup);
  printf("Average speed down: %lf\n", Sdown);
  printf("Maximum speed: %lf\n", Smax);
  printf("Result: %lf\n", maxAvgError * maxMaxError);
}
