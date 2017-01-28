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
void Drivetrain::set(double leftValue, double rightValue){
	leftMotor->Set(leftValue);
	rightMotor->Set(rightValue);
}

void Drivetrain::drive(double inches) {
    if(inches>0.0) {Drivetrain::set(1.0,1.0);}
    else {Drivetrain::set(-1.0,-1.0);}
    Wait(inches/robotSpeed);
    Drivetrain::set(0.0,0.0);
}
