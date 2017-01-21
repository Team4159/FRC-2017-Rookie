#ifndef OI_H
#define OI_H

#include <Joystick.h>
class OI {
public:
	Joystick *leftStick = new Joystick(0);
	Joystick *rightStick = new Joystick(1);

	Joystick::AxisType LEFT_DRIVE_AXIS = Joystick::AxisType::kYAxis;
	double LEFT_DRIVE_MULTIPLIER = 1;

	Joystick::AxisType RIGHT_DRIVE_AXIS = Joystick::AxisType::kYAxis;
	double RIGHT_DRIVE_MULTIPLIER = 1;

	OI();
};

#endif  // OI_H
