#include "Shoot.h"
#include <SmartDashboard/SmartDashboard.h>
#include "../OI.h"
Shoot::Shoot() {
	Requires(shooter.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void Shoot::Initialize() {
	frc::SmartDashboard::PutBoolean("Shooting", true);
	shooter->IsShooting = true;
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
	shooter->SetFlywheel(CommandBase::oi->getFlywheelValue());
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
	return (robotTimer->Get()>15 && !OI::shootButton->Get());
}

// Called once after isFinished returns true
void Shoot::End() {
	shooter->SetFlywheel(0);
	frc::SmartDashboard::PutBoolean("Shooting", false);
	shooter->IsShooting = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {
	shooter->SetFlywheel(0);
	frc::SmartDashboard::PutBoolean("Shooting", false);
	shooter->IsShooting = false;
}
