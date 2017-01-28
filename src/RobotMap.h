#include "Commands/GripPipeline.h"
#ifndef ROBOTMAP_H
#define ROBOTMAP_H

//set these to correct values after drivetrain fixed
constexpr int leftDriveMotor = 0;
constexpr int rightDriveMotor = 0;
constexpr int flywheelPort = 0;
constexpr int IMG_WIDTH = 640;
constexpr int IMG_HEIGHT = 480;
constexpr int TOLERANCE = 10; //obsolete
constexpr int cameraPortHigh = 0;
constexpr int cameraPortLow = 0;
constexpr int thresholdSize = 250; //obsolete
constexpr int sizeTolerance = 50;  //obsolete
constexpr int targetHeight4FeetFromHighGoal = 39;
constexpr int targetHeight4FeetFromGearPeg = 121;
constexpr double cameraWidth2Feet = 29.9375;
constexpr double pi = 3.1415926535898;
constexpr double radiansPerSec = 7.0; //Just a guess. The number of radians
									  //the robot can turn a second by doing
									  //drivetrain->set(1.0,-1.0) or vice versa
constexpr int bestDistFromHighGoal = 36; //this value may be off
constexpr double robotSpeed = 120; //inches per second, may be off

bool isAiming = false;


grip::GripPipeline gp;

//4 feet = height 121 for gear peg
//4 feet = height 39 for high goal 4 inch high tape

//24 in = 29.9375 in width

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
