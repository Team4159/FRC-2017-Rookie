#include "Turn.h"

Turn::Turn(double degrees, bool clockwise) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
	angle = degrees;
	isClockwise = clockwise;
	time = Timer();
}

// Called just before this Command runs the first time
void Turn::Initialize() {
	time.Reset();
	time.Start();
}

// Called repeatedly when this Command is scheduled to run
void Turn::Execute() {
	if(isClockwise) {drivetrain->set(1.0,-1.0);}
	else {drivetrain->set(-1.0,1.0);}
}

// Make this return true when this Command no longer needs to run execute()
bool Turn::IsFinished() {
	return time.Get() > (pi*angle/180.0)/radiansPerSec;
}

// Called once after isFinished returns true
void Turn::End() {
	drivetrain->set(0.0,0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn::Interrupted() {
	drivetrain->set(0.0,0.0);
}
