package org.usfirst.frc.team9514.robot.commands;

import edu.wpi.first.wpilibj.command.Command;
import org.usfirst.frc.team9514.robot.CommandBase;

class Climb extends Command{
  public Climb(){

  }
  protected execute() {
    if(CommandBase.oi.getClimber()){
      CommandBase.climber.set(.5);
    }
  }
}
