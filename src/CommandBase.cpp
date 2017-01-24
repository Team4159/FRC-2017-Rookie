#include "CommandBase.h"
#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "Commands/Shoot.h"
//#include "VictorSP.h"
//VictorSP* temp = new VictorSP(1);
#include "CommandBase.h"
#include <Commands/Scheduler.h>

#include "Subsystems/Drivetrain.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/test.h"
#include "OI.h"

//VictorSP* tempmotor = new VictorSP(4);
// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
std::unique_ptr<Drivetrain> CommandBase::drivetrain;//=std::make_unique<Drivetrain>();

std::unique_ptr<OI> CommandBase::oi=std::make_unique<OI>();

std::unique_ptr<Shooter> CommandBase::shooter;//=new Shooter();
test* CommandBase::tester = NULL;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
void CommandBase::init()
{
	tester = new test();
	drivetrain = std::make_unique<Drivetrain> ();
}
