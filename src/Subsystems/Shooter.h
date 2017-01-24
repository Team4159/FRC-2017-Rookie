#ifndef Shooter_H
#define Shooter_H

#include <Commands/Subsystem.h>
#include <VictorSP.h>
class Shooter : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	VictorSP* flywheelMotor;// = new Victor(3);
	Shooter();
	void InitDefaultCommand();
	void SetFlywheel(double value);
};

#endif  // Shooter_H
