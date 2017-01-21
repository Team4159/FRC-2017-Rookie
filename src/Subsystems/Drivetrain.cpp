#include "Drivetrain.h"
#include <Joystick.h>
#include <VictorSP.h>
#include "../RobotMap.h"

Drivetrain::Drivetrain() :
		frc::Subsystem("Drivetrain") {
	leftMotor = new VictorSP(leftDriveMotor);
	rightMotor = new VictorSP(rightDriveMotor);

}

void Drivetrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Drivetrain::set(Joystick leftStick, Joystick rightStick){
	double leftValue = leftStick.GetY();
	double rightValue = rightStick.GetY();
	
	leftMotor->Set(leftValue);
	rightMotor->Set(rightValue);
}

void Drivetrain::set(double leftValue, double rightValue){
	leftMotor->Set(leftValue);
	rightMotor->Set(rightValue);
	
}
