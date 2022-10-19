/*
 * Name:     ElevatorLib.h
 *
 *
 * Class:    ElevatorLib
 * Created : Mar 5, 2011
 * Author :  Charles B. Owen
 */

#pragma once
#ifndef ELEVATORLIB_H_
#define ELEVATORLIB_H_

#include <stdbool.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C"
{
#endif

  /*
   * Constants
   */

#define FloorSpacing 3.28

#define FloorTolerance 0.16

  /*
   * Management
   */

  extern bool IsElevatorRunning(void);

  extern void ElevatorStartup(void);

  extern void ElevatorShutdown(void);

  /*
   * Lights
   */

  extern void SetCloseDoorLight(bool s);

  extern bool GetCloseDoorLight(void);

  extern void SetOpenDoorLight(bool s);

  extern bool GetOpenDoorLight(void);

  extern void SetPanelFloorLight(int floor, bool s);

  extern bool GetPanelFloorLight(int floor);

  extern void SetCallLight(int floor, bool up, bool s);

  extern bool GetCallLight(int floor, bool up);

  extern void SetDoorIndicator(int floor, bool up, bool s);

  extern bool GetDoorIndicator(int floor, bool up);

  /*
   * Doors
   */

  extern void SetDoor(int floor, bool open);

  extern bool IsDoorOpen(int floor);

  extern bool IsDoorClosed(int floor);

  /*
   * Button callback management
   */

  extern void SetOpenDoorHandler(void (*handler)());

  extern void SetCloseDoorHandler(void (*handler)());

  extern void SetCallPressedHandler(void (*handler)(int floor, bool up));

  extern void SetFloorPressedHandler(void (*handler)(int floor));

  /*
   * Motor control
   */

  extern void SetBrake(bool b);

  extern void SetMotorPower(double power);

  extern double GetPosition(void);

  extern double GetVelocity(void);

  extern double GetFloor(void);

  extern int GetNearestFloor(void);

  extern void ChangeLoading(void);

  extern void SetLoading(int r);

  /*
   * Timer
   */

  extern void ResetTimer(void);

  extern double GetTimer(void);

  /*
   * Button testing help
   */

  extern int WhatFloorToGoTo(bool up);

  extern int WhatFloorToGoToInThisDirection(bool up);

#ifdef __cplusplus
}
#endif

#endif /* ELEVATORLIB_H_ */