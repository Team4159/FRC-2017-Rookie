#include "Shoot.h"

#include <cmath>
#include "CommandBase.h"
#include <SmartDashboard/SmartDashboard.h>

Shoot::Shoot(double speed) : CommandBase("Shoot") {
	Requires(CommandBase::shooter.get());
  shooterSpeed = speed;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void Shoot::Initialize() {
  CommandBase::shooter->EnablePID();
  CommandBase::shooter->Set(shooterSpeed);
	frc::SmartDashboard::PutBoolean("Shooting", true);
	//shooter->IsShooting = true;
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
	//shooter->SetFlywheel(CommandBase::oi->GetFlywheelValue());
  
  double shooteroutput = -CommandBase::shooter->GetShooterPIDOutput();
  shooteroutput *= .5;
  //Scale output down to fit in range -1 to 1?
  if(CommandBase::oi->GetShooter()==true)
    CommandBase::shooter->SetRaw(shooteroutput);
  else
    CommandBase::shooter->SetRaw(0);
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished(){
	// shootButton will call Interrupted when it is released
	return false;
}

// Called once after isFinished returns true
void Shoot::End(){
  CommandBase::shooter->DisablePID();
  CommandBase::shooter->SetRaw(0);
	//shooter->SetFlywheel(0);
	frc::SmartDashboard::PutBoolean("Shooting", false);
	//shooter->IsShooting = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {
	//shooter->SetFlywheel(0);
  CommandBase::shooter->DisablePID();
  CommandBase::shooter->SetRaw(0);
	frc::SmartDashboard::PutBoolean("Shooting", false);
	//shooter->IsShooting = false;
}
