#ifndef Climber_H
#define Climber_H

#include <Commands/Subsystem.h>
#include <VictorSP.h>
class Climber : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	VictorSP *climberMotor;
public:
	Climber();
	void InitDefaultCommand();
	void Set(double value);
};

#endif  // Climber_H
