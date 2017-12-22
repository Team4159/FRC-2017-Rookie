package org.usfirst.frc.team9159.robot.commands;

import org.usfirst.frc.team9159.robot.CommandBase;

import edu.wpi.first.wpilibj.command.TimedCommand;

/**
 *
 */
public class DriveStraight extends TimedCommand {
	//Oh the irony
    public DriveStraight(double timeout) {
        super(timeout);
        requires(CommandBase.drivetrain);
    }

    // Called just before this Command runs the first time
    protected void initialize() {
    }

    // Called repeatedly when this Command is scheduled to run
    protected void execute() {
    	CommandBase.drivetrain.setRaw(0.5, 0.5);
    }

    // Called once after timeout
    protected void end() {
    	CommandBase.drivetrain.setRaw(0, 0);
    }

    // Called when another command which requires one or more of the same
    // subsystems is scheduled to run
    protected void interrupted() {
    	end();
    }
}
