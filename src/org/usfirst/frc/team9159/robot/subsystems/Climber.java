package org.usfirst.frc.team9159.robot.subsystems;

import edu.wpi.first.wpilibj.command.Subsystem;
import org.usfirst.frc.team9159.robot.RobotMap;
import org.usfirst.frc.team9159.robot.commands.Climb;

import edu.wpi.first.wpilibj.VictorSP;

public class Climber extends Subsystem {
	  private VictorSP climberMotor;
	  private VictorSP climberMotor2;
	  public Climber() {
		    climberMotor = new VictorSP(RobotMap.CLIMBER_MOTOR);
		    climberMotor2 = new VictorSP(RobotMap.CLIMBER_MOTOR_2);
	  }
	  public void initDefaultCommand(){
		  setDefaultCommand(new Climb());
	  }
	  public void set(double speed) {
	    climberMotor.set(-speed);
	    climberMotor2.set(-speed);
	  }
}