#ifndef OI_H
#define OI_H

#include <Joystick.h>
#include <Buttons/JoystickButton.h>
class OI {
public:
	std::unique_ptr<Joystick> leftStick = std::make_unique<Joystick>(0);
	std::unique_ptr<Joystick> rightStick = std::make_unique<Joystick>(1);

	JoystickButton *shootButton;

	Joystick::AxisType LEFT_DRIVE_AXIS = Joystick::AxisType::kYAxis;
	double LEFT_DRIVE_MULTIPLIER = 1;

	Joystick::AxisType RIGHT_DRIVE_AXIS = Joystick::AxisType::kYAxis;
	double RIGHT_DRIVE_MULTIPLIER = 1;

	Joystick::AxisType FLYWHEEL_AXIS = Joystick::AxisType::kYAxis;
	double FLYWHEEL_DEFAULT = -0.5;

	Joystick::AxisType SHOOTING_TURN_AXIS = Joystick::AxisType::kXAxis;
	double SHOOTING_TURN_MULTIPLIER = 0.5;
	int IMG_WIDTH = 640;
	int IMG_HEIGHT = 480;
	OI();
	double getLeftDriveValue();
	double getRightDriveValue();
	double getFlywheelValue();
	double getTurnValue();
};

#endif  // OI_H
