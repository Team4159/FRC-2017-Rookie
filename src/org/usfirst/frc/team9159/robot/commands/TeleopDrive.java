package org.usfirst.frc.team9159.robot.commands;

import org.usfirst.frc.team9159.robot.CommandBase;
import edu.wpi.first.wpilibj.command.Command;

public class TeleopDrive extends Command {
	
	private final double LEFT_DRIVE_MULTIPLIER = -1.0;
	private final double RIGHT_DRIVE_MULTIPLIER = 1.0;

    public TeleopDrive() {
        // Use requires() here to declare subsystem dependencies
        requires(CommandBase.drivetrain);
    }

    // Called just before this Command runs the first time
    protected void initialize() {
    	//CommandBase.drivetrain.disablePID();
    }

    // Called repeatedly when this Command is scheduled to run
    protected void execute() {
    	CommandBase.drivetrain.setRaw(CommandBase.oi.getLeftDriveValue()*LEFT_DRIVE_MULTIPLIER,
    						 CommandBase.oi.getRightDriveValue()*RIGHT_DRIVE_MULTIPLIER,false);
    	
    }

    // Make this return true when this Command no longer needs to run execute()
    protected boolean isFinished() {
        return false;
    }

    // Called once after isFinished returns true
    protected void end() {
    	//CommandBase.drivetrain.disablePID();
    }

    // Called when another command which requires one or more of the same
    // subsystems is scheduled to run
    protected void interrupted() {
    }
}