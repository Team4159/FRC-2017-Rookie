package org.usfirst.frc.team9514.robot.commands;

import edu.wpi.first.wpilibj.command.Command;
import org.usfirst.frc.team9514.robot.CommandBase;

/**
 *
 */
public class Shoot extends Command { 
    
    public Shoot() {
        // Use requires() here to declare subsystem dependencies
        // eg. requires(chassis);
        requires(CommandBase.shooter);
    }

    // Called just before this Command runs the first time
    protected void initialize() {
        CommandBase.shooter.enablePID();
    }

    // Called repeatedly when this Command is scheduled to run
    protected void execute() {
        double shooterOutput = CommandBase.shooter.getShooterPIDOutput();
        shooterOutput*=.5;//Scale
        if(CommandBase.oi.getShooter())
            CommandBase.shooter.setRaw(shooterOutput);
        else
            CommandBase.shooter.setRaw(0);
    }

    // Make this return true when this Command no longer needs to run execute()
    protected boolean isFinished() {
        return false;
    }

    // Called once after isFinished returns true
    protected void end() {
        CommandBase.shooter.disablePID();
        CommandBase.shooter.setRaw(0);
    }

    // Called when another command which requires one or more of the same
    // subsystems is scheduled to run
    protected void interrupted() {
        CommandBase.shooter.disablePID();
        CommandBase.shooter.setRaw(0);
    }
}
