#include "OI.h"

#include <WPILib.h>
#include <Buttons/JoystickButton.h>
#include "Commands/Shoot.h"
OI::OI() {
	// Fill in correct joystick mapping
	shootButton = new JoystickButton(rightStick.get(), 1);
	//shootButton->WhileHeld(new Shoot());
}

double OI::getLeftDriveValue(){
	return leftStick->GetAxis(LEFT_DRIVE_AXIS) * LEFT_DRIVE_MULTIPLIER;
}

double OI::getRightDriveValue(){
	return rightStick->GetAxis(RIGHT_DRIVE_AXIS) * RIGHT_DRIVE_MULTIPLIER;
}
