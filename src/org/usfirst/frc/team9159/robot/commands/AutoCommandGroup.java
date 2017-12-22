package org.usfirst.frc.team9159.robot.commands;

import org.usfirst.frc.team9159.robot.CommandBase;

import edu.wpi.first.wpilibj.command.CommandGroup;

/**
 *
 */
public class AutoCommandGroup extends CommandGroup {

    public AutoCommandGroup() {
    	
    	requires(CommandBase.drivetrain);
    	
    	addSequential(new DriveStraight(5)); 
    }
}
