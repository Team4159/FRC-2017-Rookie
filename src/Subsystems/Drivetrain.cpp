#include "Drivetrain.h"
#include <Joystick.h>
#include <VictorSP.h>
#include "../RobotMap.h"
#include <SmartDashboard/SmartDashboard.h>

Drivetrain::Drivetrain() :
		frc::Subsystem("Drivetrain") {
	leftMotor = new VictorSP(leftDriveMotor);
	rightMotor = new VictorSP(rightDriveMotor);
	leftMotor->SetInverted(true);
}

void Drivetrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Drivetrain::Set(double leftValue, double rightValue){
	if (!IsEnabled){
		leftValue = 0;
		rightValue = 0;
	}
	leftMotor->Set(leftValue);
	rightMotor->Set(rightValue);
	frc::SmartDashboard::PutNumber("LeftMotor", leftValue);
	frc::SmartDashboard::PutNumber("RightMotor", rightValue);
	
}

void Drivetrain::Disable(){
	Set(0, 0);
	IsEnabled = false;
}

void Drivetrain::Enable(){
	IsEnabled = true;
}
