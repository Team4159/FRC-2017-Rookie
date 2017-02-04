#include "Drive.h"

Drive::Drive(int dist) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
	if(dist>0) {
		inches = dist;
		isForward = true;
	}
	else {
		inches = -dist;
		isForward = false;
	}
	t = Timer();

}

// Called just before this Command runs the first time
void Drive::Initialize() {
	t.Reset();
	t.Start();
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	if(isForward) {drivetrain->set(1.0,1.0);}
	else {drivetrain->set(-1.0,-1.0);}
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return (t.Get() > inches/robotSpeed);
}

// Called once after isFinished returns true
void Drive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {

}
