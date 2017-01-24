#include "test.h"
#include "../RobotMap.h"
#include <Victor.h>
test::test() : Subsystem("test") {
	victortest = new VictorSP(3);
}

void test::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
