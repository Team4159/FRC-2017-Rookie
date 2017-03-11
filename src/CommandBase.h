#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <Commands/Command.h>

#include "OI.h"
#include "Subsystems/Drivetrain.h"
#include "Subsystems/Shooter.h"
#include "Commands/GripPipeline.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;

	// Create a single static instance of all of your subsystems
	static std::unique_ptr<Drivetrain> drivetrain;
	static std::unique_ptr<OI> oi;
	static std::unique_ptr<Shooter> shooter;
	static std::unique_ptr<Timer> robotTimer;
	static std::unique_ptr<grip::GripPipeline> gp;
	static std::unique_ptr<GearOuttake> gearouttake;
    static std::unique_ptr<Gyrosensor> gyro;
	static void init();
};

#endif  // COMMAND_BASE_H
