/*
 * Name:     RobotLib.h
 *
 *
 * Class:    RobotLib
 * Created : April 17, 2011
 * Author :  Charles B. Owen
 */

/** \file
 * \brief Robot Scheduler Simulation library include file.
 *
 * This file is included to utilize the Robot Scheduler Simulator.
 */

#pragma once
#ifndef ROBOTLIB_H_
#define ROBOTLIB_H_

#include <stdbool.h>
#include <unistd.h>

/**
 *  \mainpage Robot Schdduler Simulator
 *
 * This is the documentation for the CSE 251 Robot Scheduler Simulator.
 * This describes the function calls necessary to utilize the
 * simulator.
 *
 * See the documentation for the RobotLib.h file for all of the
 * function documentation. Applications include this file to gain
 * access to the functions and link to the file libRobotLib.a.
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


/*
 * Management
 */

/** \brief Function to determine if the  simulator is currently running. */
/**
 * This function should be called in a loop that exists when the simulator is
 * no longer running. If the simulator window is closed by the user, the calls
 * are not longer valid and should not be used (other than SimulatorShutdown).
 * \return true if the simulation is currently running.
 * \code
    while(IsSimulatorRunning())
    {

    }
 \endcode
 */
extern bool IsSimulatorRunning(void);

/** \brief Start the Simulation.
 *
 * This function must be called before any other call can be made
 * to any Simulator functions. It starts the simulator
 * in a new window.
 */
extern void SimulatorStartup(void);

/** \brief Shut down the Simulation.
 *
 * This function should be called last in the program. If the simulator is
 * currently running, it shuts down the simulator and closes the window. Then
 * it releases any resources allocated to this program.
 */
extern void SimulatorShutdown(void);

/** \brief Order the robot to go to a given machine.
 *
 * This function is called to tell the robot to immediately go to a given
 * machine.
 */
extern void RobotGoTo(int machine);


/** \brief Set the handler function
 *
 * This function installs a handler function that will be called when a
 * machine requests service from the robot.
 *
 * There is no default behavior for the request.
 * \param handler A C function that will be called when a machine requests the robot.
 * \param machine The machine number 1 - 6
 * \par Example of how to set the handler in code:
 * \code
     SetMachineRequestHandler(OnMachineRequest);
 \endcode
 * \par Example handler function:
 * \code
void OnMachineRequest(int machine)
{
    printf("Request from machine %d\n", machine);
}
\endcode
 */
extern void SetMachineRequestHandler(void (*handler)(int machine));

/** \brief Determine if the robot is busy (moving)
 *
 * This function returns true if the robot is currently moving.
 * \return ture if the robot is moving
 */
extern bool IsRobotBusy(void);


/*
 * Timer
 */

/** \brief Reset a timer available for program use.
 *
 * This function, when called, resets a timer to zero. It is equivalent to pressing
 * the reset button on a stopwatch. The stopwatch can then be read using the GetTimer
 * function. There is only one timer available to an application.
 */
extern void ResetTimer(void);

/** \brief Read the current value of the timer.
 *
 * This function read the current value of an available timer. The timer can be
 * reset using the ResetTimer call. The value read is in second and is a floating point
 * value.
 * \return Number of seconds since the last time ResetTimer was called.
 */
extern double GetTimer(void);



#ifdef __cplusplus
}
#endif

#endif /* ROBOTLIB_H_ */
