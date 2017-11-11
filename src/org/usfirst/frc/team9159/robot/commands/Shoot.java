package org.usfirst.frc.team9159.robot.commands;

import edu.wpi.first.wpilibj.command.Command;
import org.usfirst.frc.team9159.robot.CommandBase;

/**
 *
 */
public class Shoot extends Command { 
    private double TARGET_SPEED = .8;
	
    public Shoot() {
        // Use requires() here to declare subsystem dependencies
        // eg. requires(chassis);
        requires(CommandBase.shooter);
    }

    // Called just before this Command runs the first time
    protected void initialize() {
        CommandBase.shooter.enable();
    }

    // Called repeatedly when this Command is scheduled to run
    protected void execute() {
        //shooterOutput*=.5;//Scale
        if(CommandBase.oi.getShooter())
            CommandBase.shooter.setSetPoint(TARGET_SPEED);
        else
            CommandBase.shooter.setRaw(0);
    }

    // Make this return true when this Command no longer needs to run execute()
    protected boolean isFinished() {
        return CommandBase.shooter.onTarget();
    }

    // Called once after isFinished returns true
    protected void end() {
        CommandBase.shooter.disable();
        CommandBase.shooter.setRaw(0);
    }

    // Called when another command which requires one or more of the same
    // subsystems is scheduled to run
    protected void interrupted() {
        end();
    }
}
