#include "Commands/GripPipeline.h"
#ifndef ROBOTMAP_H
#define ROBOTMAP_H

//set these to correct values after drivetrain fixed
constexpr int leftDriveMotor = 0;
constexpr int rightDriveMotor = 1
constexpr int flywheelPort = 0;
constexpr int cameraPortHigh = 0;
constexpr int cameraPortLow = 0;
//4 feet = height 121 for gear peg
//4 feet = height 39 for high goal 4 inch high tape

//24 in = 29.9375 in width

constexpr int shooterFlywheelMotor = 8;
/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int LEFTMOTOR = 1;
// constexpr int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int RANGE_FINDER_PORT = 1;
// constexpr int RANGE_FINDER_MODULE = 1;

#endif  // ROBOTMAP_H
