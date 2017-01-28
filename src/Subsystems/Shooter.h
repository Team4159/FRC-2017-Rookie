#ifndef Shooter_H
#define Shooter_H

#include <Commands/Subsystem.h>

class Shooter : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	VictorSP* flywheelMotor;
	bool IsShooting;
public:
	Shooter();
	void InitDefaultCommand();
	void SetFlywheel(double value);
};

#endif  // Shooter_H
