package org.usfirst.frc.team9159.robot.subsystems;

import edu.wpi.first.wpilibj.VictorSP;
import edu.wpi.first.wpilibj.command.Subsystem;
import org.usfirst.frc.team9159.robot.RobotMap;
import org.usfirst.frc.team9159.robot.commands.TeleopDrive;

/**
 *
 */
public class Drivetrain extends Subsystem {
	private VictorSP leftMotor;
	private VictorSP rightMotor;
	
	// Put methods for controlling this subsystem
    // here. Call these from Commands.
	
	public Drivetrain(){
		leftMotor = new VictorSP(RobotMap.LEFT_MOTOR);
		rightMotor = new VictorSP(RobotMap.RIGHT_MOTOR);	
	}
	public void setRaw(double left, double right){
			leftMotor.set(left);
			rightMotor.set(-right);
	}

    public void initDefaultCommand() {
        // Set the default command for a subsystem here.
        //setDefaultCommand(new MySpecialCommand());
    	setDefaultCommand(new TeleopDrive());
    }
}

