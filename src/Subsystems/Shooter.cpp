#include "Shooter.h"
#include "../RobotMap.h"
#include <VictorSP.h>

Shooter::Shooter() : Subsystem("Shooter") {
	flywheelMotor = new VictorSP(flywheelPort);
	IsShooting=false;
}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Shooter::SetFlywheel(double value){
	flywheelMotor->Set(value);
}