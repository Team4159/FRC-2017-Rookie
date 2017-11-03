package org.usfirst.frc.team9514.robot.commands;

import edu.wpi.first.wpilibj.command.Command;
import org.usfirst.frc.team9514.robot.CommandBase;

public class Climb extends Command{
	public Climb(){
		requires(CommandBase.climber);
	}
	protected void execute() {
		if(CommandBase.oi.getClimber()){
	      CommandBase.climber.set(.5);
	    }
	}
	protected boolean isFinished() {
		// TODO Auto-generated method stub
		return false;
	}
}
