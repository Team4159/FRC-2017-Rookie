package org.usfirst.frc.team9514.robot.commands;

import edu.wpi.first.wpilibj.command.Command;
import org.usfirst.frc.team9514.robot.CommandBase;

public class Intake extends Command{
    public Intake(){
        requires(CommandBase.intaker);
    }
    protected void execute(){
        if(CommandBase.oi.getIntaker()){
            if(CommandBase.intaker.getLimitSwitch()){
                CommandBase.intaker.setRaw1(.5);
                
            }
            CommandBase.intaker.setRaw2(.5);
            
        }
    }
    protected boolean isFinished(){
        return false;
    }
}
