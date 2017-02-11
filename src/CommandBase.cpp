#include "CommandBase.h"
#include <Commands/Scheduler.h>

#include "Subsystems/Drivetrain.h"
#include "Commands/GripPipeline.h"
// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.

std::unique_ptr<grip::GripPipeline> CommandBase::gp = NULL;

std::unique_ptr<Drivetrain> CommandBase::drivetrain=
		NULL;

std::unique_ptr<OI> CommandBase::oi = NULL;

std::unique_ptr<Shooter> CommandBase::shooter = NULL;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::init(){
	drivetrain = std::make_unique<Drivetrain>();
	oi = std::make_unique<OI>();
	shooter = std::make_unique<Shooter>();
	robotTimer = std::make_unique<Timer>();
	gp = std::make_unique<grip::GripPipeline>();
	gearouttake = std::make_unique<GearOuttake>();
}
