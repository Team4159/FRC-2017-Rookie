#include <Joystick.h>
#include <VictorSP.h>
#include "../RobotMap.h"

Shooter::Shooter() :
		frc::Subsystem("Shooter") {
    motor = new VictorSP(shooterMotor);
}

void Shooter::InitDefaultCommand() {

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Shooter::shoot(){
	motor->Set(1.0);
}
