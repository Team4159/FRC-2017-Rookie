#include "OI.h"

#include <WPILib.h>
#include <Buttons/JoystickButton.h>
#include "Commands/Shoot.h"

OI::OI() {
  leftStick = std::make_unique<frc::Joystick> ( 0 );
  rightStick = std::make_unique<frc::Joystick> ( 1 );
  secondaryStick = std::make_unique<frc::Joystick> ( 2 );
  
	//shootButton = new JoystickButton(rightStick.get(), 1);
	//shootButton->WhileHeld(new Shoot());
}

double OI::GetLeftDriveValue(){
	return leftStick->GetAxis(LEFT_DRIVE_AXIS) * LEFT_DRIVE_MULTIPLIER;
}

double OI::GetRightDriveValue(){
	return rightStick->GetAxis(RIGHT_DRIVE_AXIS) * RIGHT_DRIVE_MULTIPLIER;
}

bool OI::GetShooter(){
  if (secondaryStick->GetRawButton( 7 )){
    return true;
  }
}

//double OI::GetFlywheelValue(){
//	return FLYWHEEL_DEFAULT + (rightStick->GetAxis(FLYWHEEL_AXIS) * -1 * (-1 - FLYWHEEL_DEFAULT));
//}
