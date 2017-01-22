#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <Commands/Subsystem.h>
#include <Joystick.h>
#include <VictorSP.h>
class Drivetrain: public frc::Subsystem {
public:
	Drivetrain();
	void InitDefaultCommand() override;
	void set(double leftValue, double rightValue);

private:
	VictorSP *leftMotor;
	VictorSP *rightMotor;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
};

#endif  // DRIVETRAIN_H
