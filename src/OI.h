#ifndef OI_H
#define OI_H

#include <Joystick.h>
class OI {
public:
	std::unique_ptr<Joystick> leftStick = std::make_unique<Joystick>(0);
	std::unique_ptr<Joystick> rightStick = std::make_unique<Joystick>(1);

	Joystick::AxisType LEFT_DRIVE_AXIS = Joystick::AxisType::kYAxis;
	double LEFT_DRIVE_MULTIPLIER = 1;

	Joystick::AxisType RIGHT_DRIVE_AXIS = Joystick::AxisType::kYAxis;
	double RIGHT_DRIVE_MULTIPLIER = 1;

	OI();
	double getLeftDriveValue();
	double getRightDriveValue();
};

#endif  // OI_H
