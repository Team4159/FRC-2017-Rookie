#include "Drivetrain.h"
#include <Joystick.h>
#include <VictorSP.h>
#include "../RobotMap.h"
#include "../Commands/Shoot.h"
Drivetrain::Drivetrain() :
		frc::Subsystem("Drivetrain") {
	leftMotor = new VictorSP(leftDriveMotor);
	rightMotor = new VictorSP(rightDriveMotor);
	leftMotor->SetInverted(true);
}

void Drivetrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new Shoot());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Drivetrain::set(double leftValue, double rightValue){
	leftMotor->Set(leftValue);
	rightMotor->Set(rightValue);
	
}
