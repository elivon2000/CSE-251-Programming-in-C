/*
 * Name:     GarageLib.h
 *
 *
 * Class:    GarageLib
 * Created : Mar 5, 2011
 * Author :  Charles B. Owen
 */

/** \file
 * \brief Garage Simulator library include file.
 *
 * This file is included to utilize the Garage Simulator.
 */

#pragma once
#ifndef GARAGELIB_H_
#define GARAGELIB_H_

#include <stdbool.h>
#include <unistd.h>

/**
 *  \mainpage Garage Simulator
 *
 * This is the documentation for the CSE 251 Garage Simulator.
 * This describes the function calls necessary to utilize the
 * simulator. The Garage Simulator is a graphical representation
 * of an elevator in a three story building. Support is provided for
 * motor control, position sensing, button support, and indicators.
 *
 * See the documentation for the GarageLib.h file for all of the
 * function documentation. Applications include this file to gain
 * access to the functions and link to the file libGarageLib.a.
 * A makefile is provided with the project.
 *
 * This documentation is generated from sources using Doxygen.
 */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Constants
 */


/** \brief Height of the door in meters.
 */
#define DoorHeight 2.13

/** \brief Tolerance for a safe door opening in meters.
 *
 * If the door is this close to open or closed we are happy.
 * We can't open past DoorHeight or close to less than 0.  2cm.
 */
#define DoorTolerance 0.02

/*
 * Management
 */

/** \brief Function to determine if the garage simulator is currently running. */
/**
 * This function should be called in a loop that exits when the garage is
 * no longer running. If the garage window is closed by the user, the calls
 * are not longer valid and should not be used (other than GarageShutdown).
 * \return true if the garage simulation is currently running.
 * \code
    while(IsGarageRunning())
    {

    }
 \endcode
 */
extern bool IsGarageRunning();

/** \brief Start the Garage Simulation.
 *
 * This function must be called before any other call can be made
 * to any Garage Simulator functions. It starts the garage simulator
 * in a new window.
 */
extern void GarageStartup();

/** \brief Shut down the Garage Simulation.
 *
 * This function should be called last in the program. If the simulator is
 * currently running, it shuts down the simulator and closes the window. Then
 * it releases any resources allocated to this program.
 */
extern void GarageShutdown();




/*
 * Button and beam management
 */

/** \brief Set a function to be called when the door button is pressed.
 *
 * This function installs a handler function that will be called when the
 * door button in the garage or in a car is pressed.
 *
 * There is no default behavior for this button.
 * \param handler A C function that will be called when the button is pressed.
 * \par Example of how to set the handler in code:
 * \code
     SetButtonHandler(OnButton);
 \endcode
 * \par Example handler function:
 * \code
void OnButton()
{
    printf("Button pressed\n");
}
\endcode
 */
extern void SetButtonHandler(void (*handler)());

/** \brief Determines of the button has been pressed.
 *
 * This function returns true if the button has been pressed. It resets so that
 * the next call will return false until the button is pressed again.
 * \return true if button was pressed.
 */
extern bool WasButtonPressed();

/** \brief Determines if the infrared beam at the bottom of door is broken.
 *
 * If the beam is broken, someone or something may be under the door, so
 * we can't close it on them.
 * \return true if beam is broken.
 */
extern bool IsBeamBroken();

/*
 * Motor control
 */

/** \brief Set the motor power.
 *
 * The door opener uses a DC motor. This function sets how much power is
 * provided to the motor. The values range from -1 to 1. A value of -1
 * means maximum velocity down. A value of 1 means maximum velocity up.
 * Values outside this range will be bounded to the range [-1, 1].
 * \param power The power setting in the range -1 to 1.
 * \code
      SetMotorPower(1);
 \endcode
 */
extern void SetMotorPower(double power);

/** \brief Set the maximum speed for the door.
 *
 * This function allows you to override the speed of the door
 * in the program. The default is 0.25 meters per second. Set a
 * larger number to make the door move faster, so avoid making this
 * number too large or the simulation may fail.
 * \param speed A speed in meters per second.
 */
extern void SetDoorSpeed(double speed);


/** \brief Get the position of the garage door in meters.
 *
 * This function returns the position of the door to the garage in
 * meters relative to closed. A value
 * of zero means the door is closed.
 * \return The current position in meters relative to closed.
 * \code
     if(GetDoorPosition() > DoorHeight - DoorTolerance)
     {
         printf("The garage door is open\n");
     }
\endcode
 */
extern double GetDoorPosition();


/*
 * Timer
 */

/** \brief Reset a timer available for program use.
 *
 * This function, when called, resets a timer to zero. It is equivalent to pressing
 * the reset button on a stopwatch. The stopwatch can then be read using the GetTimer
 * function. There is only one timer available to an application.
 */
extern void ResetTimer();

/** \brief Read the current value of the timer.
 *
 * This function read the current value of an available timer. The timer can be
 * reset using the ResetTimer call. The value read is in second and is a floating point
 * value.
 * \return Number of seconds since the last time ResetTimer was called.
 */
extern double GetTimer();


#ifdef __cplusplus
}
#endif

#endif /* ELEVATORLIB_H_ */
