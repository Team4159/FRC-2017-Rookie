#include "CommandBase.h"

#include <Commands/Scheduler.h>

#include "Subsystems/Drivetrain.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
std::unique_ptr<Drivetrain> CommandBase::drivetrain=
		NULL;

std::unique_ptr<OI> CommandBase::oi = NULL;

std::unique_ptr<Shooter> CommandBase::shooter = NULL;

std::unique_ptr<Climber> CommandBase::climber = NULL;
CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::init(){
	drivetrain = std::make_unique<Drivetrain>();
	oi = std::make_unique<OI>();
	shooter = std::make_unique<Shooter>();
	climber = std::make_unique<Climber>();
}
