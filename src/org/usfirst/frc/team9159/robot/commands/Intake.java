package org.usfirst.frc.team9159.robot.commands;

import edu.wpi.first.wpilibj.command.Command;
import org.usfirst.frc.team9159.robot.CommandBase;

public class Intake extends Command{
    public Intake(){
        requires(CommandBase.intaker);
    }
    protected void execute(){
        if(CommandBase.oi.getIntaker())
                CommandBase.intaker.setRawIntaking(1.0);   
        else
        	CommandBase.intaker.setRawIntaking(0);
            
        if(CommandBase.oi.getExtend())
        	CommandBase.intaker.setRawExtending(.5);
        else
        	CommandBase.intaker.setRawExtending(0);
    }
    protected boolean isFinished(){
        return false;
    }
}
