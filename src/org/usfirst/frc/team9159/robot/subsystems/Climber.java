package org.usfirst.frc.team9159.robot.subsystems;

import edu.wpi.first.wpilibj.command.Subsystem;
import org.usfirst.frc.team9159.robot.RobotMap;
import org.usfirst.frc.team9159.robot.commands.Climb;

import edu.wpi.first.wpilibj.VictorSP;

public class Climber extends Subsystem {
	  private VictorSP climberMotor;
	  public Climber() {
	    climberMotor = new VictorSP(RobotMap.CLIMBER_MOTOR);
	  }
	  public void initDefaultCommand(){
		  setDefaultCommand(new Climb());
	  }
	  public void set(double speed) {
	    climberMotor.set(speed);
	  }
}