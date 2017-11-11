package org.usfirst.frc.team9159.robot.commands;

import edu.wpi.first.wpilibj.command.Command;
import org.usfirst.frc.team9159.robot.CommandBase;

public class Climb extends Command{
	public Climb(){
		requires(CommandBase.climber);
	}
	protected void execute() {
		if(CommandBase.oi.getClimber()){
	      CommandBase.climber.set(1.0);
	    }else{
	    	CommandBase.climber.set(0);
	    }
	}
	protected boolean isFinished() {
		// TODO Auto-generated method stub
		return false;
	}
}
