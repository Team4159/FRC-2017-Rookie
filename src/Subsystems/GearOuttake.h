#ifndef GearOuttake_H
#define GearOuttake_H

#include <Commands/Subsystem.h>

//When I find the pieces!

class GearOuttake : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	GearOuttake();
	void ReleaseGear();
};

#endif  // GearOuttake_H
