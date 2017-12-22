package org.usfirst.frc.team9159.robot.commands;

import edu.wpi.first.wpilibj.command.Command;
import org.usfirst.frc.team9159.robot.CommandBase;

public class Feed extends Command{
    public Feed(){
        requires(CommandBase.feeder);
    }
    protected void initialize(){
    }
    protected void execute(){
        if(CommandBase.oi.getFeeder())
            CommandBase.feeder.setRaw(.1);
        else
        	CommandBase.feeder.setRaw(0);

    }
    protected boolean isFinished(){
    	return false;	
    }
}
