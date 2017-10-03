#ifndef ROBOTMAP_H
#define ROBOTMAP_H

//set these to correct values after drivetrain fixed
constexpr int leftDriveMotor = 0;
constexpr int rightDriveMotor = 1;

constexpr int shooterFlywheelMotor = 8;

//Motor Ports
const int MOTOR_SHOOTER = 8;

//PDP Channels
const int SHOOTER_CHANNEL = 2;

//Encoder ports
const int ENCODER_SHOOTER_A=0;
const int ENCODER_SHOOTER_B=1;

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
