package org.usfirst.frc.team9514.robot.commands;

import org.usfirst.frc.team9514.robot.CommandBase;
import edu.wpi.first.wpilibj.command.Command;
import edu.wpi.first.wpilibj.Timer;

/**
 *
 */
public class AutonomousDrive extends Command {
    private boolean setpointReached;
    private Timer setpointTimer;
    public AutonomousDrive() {
        // Use requires() here to declare subsystem dependencies
        // eg. requires(chassis);
        requires(CommandBase.drivetrain);
    }

    // Called just before this Command runs the first time
    protected void initialize() {
        CommandBase.drivetrain.enablePID();
        setpointTimer = new Timer();
        setpointReached = false;

    }

    // Called repeatedly when this Command is scheduled to run
    protected void execute() {
        double leftoutput = CommandBase.drivetrain.getLeftPIDOutput();
        double rightoutput = CommandBase.drivetrain.GetRightPIDOutput();
        if(Math.abs(leftoutput) > 1 || Math.abs(rightoutput) > 1) {
            double scalefactor = 1.0/(Math.max(Math.abs(leftoutput), Math.abs(rightoutput)));
            leftoutput *= scalefactor;
            rightoutput *= scalefactor;
        }
        CommandBase.drivetrain.setRaw(leftoutput, rightoutput, false);
        //if(CommandBase.drivetrain.DistancePIDDone())
            if(!setpointReached) {
                setpointTimer.start();
                setpointReached = true;
            }else {
                setpointTimer.stop();
                setpointTimer.reset();
                setpointReached = false;
            }
    }
    

    // Make this return true when this Command no longer needs to run execute()
    protected boolean isFinished() {
        return setpointReached && setpointTimer.get() > 0.1;
    }

    // Called once after isFinished returns true
    protected void end() {
        CommandBase.drivetrain.disablePID();
        CommandBase.drivetrain.setRaw(0, 0, false);
        System.out.println("Finished drived distance");
    }

    // Called when another command which requires one or more of the same
    // subsystems is scheduled to run
    protected void interrupted() {
    }
}
