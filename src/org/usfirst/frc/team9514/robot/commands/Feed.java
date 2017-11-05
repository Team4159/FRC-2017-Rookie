package org.usfirst.frc.team9514.robot.commands;

import edu.wpi.first.wpilibj.command.Command;
import org.usfirst.frc.team9514.robot.CommandBase;

public class Feed extends Command{
    public Feed(){
        requires(CommandBase.feeder);
    }
    protected void initialize(){
    }
    protected void execute(){
        if(CommandBase.oi.getFeeder())
            CommandBase.shooter.setRaw(.5);

    }
    protected boolean isFinished(){
    return false;
   }
        


}
