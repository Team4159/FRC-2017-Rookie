package org.usfirst.frc.team9514.robot.commands;

import edu.wpi.first.wpilibj.command.Command;

import org.usfirst.frc.team9514.robot.Robot;

/**
 *
 */
public class Shoot extends Command { 
    
    public Shoot() {
        // Use requires() here to declare subsystem dependencies
        // eg. requires(chassis);
        requires(Robot.shooter);
    }

    // Called just before this Command runs the first time
    protected void initialize() {
        Robot.shooter.enablePID();
    }

    // Called repeatedly when this Command is scheduled to run
    protected void execute() {
        double shooterOutput = Robot.shooter.getShooterPIDOutput();
        shooterOutput*=.5;//Scale
        if(Robot.oi.getShooter()==true)
            Robot.shooter.setRaw(shooterOutput);
        else
            Robot.shooter.setRaw(0);
    }

    // Make this return true when this Command no longer needs to run execute()
    protected boolean isFinished() {
        return false;
    }

    // Called once after isFinished returns true
    protected void end() {
        Robot.shooter.disablePID();
        Robot.shooter.setRaw(0);
    }

    // Called when another command which requires one or more of the same
    // subsystems is scheduled to run
    protected void interrupted() {
        Robot.shooter.disablePID();
        Robot.shooter.setRaw(0);
    }
}
