#include "Shoot.h"

Shoot::Shoot() {
	Requires(shooter.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void Shoot::Initialize() {
	printf("start shooting\n");
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
	shooter->setFlywheel(-1);
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Shoot::End() {
	shooter->setFlywheel(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {
	printf("done shooting\n");
	shooter->setFlywheel(0);
}
