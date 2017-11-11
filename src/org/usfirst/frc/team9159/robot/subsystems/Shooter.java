package org.usfirst.frc.team9159.robot.subsystems;

import edu.wpi.first.wpilibj.command.Subsystem;
import edu.wpi.first.wpilibj.Encoder;
import edu.wpi.first.wpilibj.VictorSP;
import edu.wpi.first.wpilibj.PIDController;
import edu.wpi.first.wpilibj.PIDSourceType;

import org.usfirst.frc.team9159.robot.RobotMap;
import org.usfirst.frc.team9159.robot.commands.Shoot;
import org.usfirst.frc.team9159.robot.subsystems.PIDOutputReceiver;

/**
 *
 */
public class Shooter extends Subsystem {
	private static final double ENCODER_PULSE_PER_ROTATION=1024;
	//private static final double ENCODER_WHEEL_DIAMETER=1.25
	//private static final double ENCODER_WHEEL_CIRCUMFERENCE = ENCODER_WHEEL_DIAMETER * Math.PI;
	//private static final double ENCODER_DISTANCE_PER_PULSE = ENCODER_WHEEL_CIRCUMFERENCE / ENCODER_PULSE_PER_ROTATION;
	
	private static final double PID_SHOOTER_P=0.1;
	private static final double PID_SHOOTER_I=0.0;
	private static final double PID_SHOOTER_D=0.0;
	private static final double PID_SHOOTER_F=0.7;
	private static final double PID_SHOOTER_TOLERANCE=2;
	
	private static double TARGET_SPEED = .8;
	
	private VictorSP shooterVictor;
	private Encoder shooterEncoder;
	private PIDController shooterPID;
	private PIDOutputReceiver shooterOutput;
	
    // Put methods for controlling this subsystem
    // here. Call these from Commands.
	
	public Shooter(){
		shooterVictor=new VictorSP(RobotMap.SHOOTER_MOTOR);
		
		shooterEncoder=new Encoder(RobotMap.SHOOTER_ENCODER_A,RobotMap.SHOOTER_ENCODER_B);
		shooterEncoder.setPIDSourceType(PIDSourceType.kRate);
		
		shooterOutput=new PIDOutputReceiver();
		shooterPID = new PIDController(PID_SHOOTER_P, PID_SHOOTER_I, PID_SHOOTER_D, PID_SHOOTER_F, 
		                             shooterEncoder, shooterOutput);
		
		//shooterPID.setContinuous(true);//maybe?
		shooterPID.setAbsoluteTolerance(PID_SHOOTER_TOLERANCE);
		
		set(TARGET_SPEED);
		
	}
	
    public void initDefaultCommand() {
        // Set the default command for a subsystem here.
        //setDefaultCommand(new MySpecialCommand());
    	setDefaultCommand(new Shoot());
    }
    
    public void setRaw(double value){
        shooterVictor.set(value);
    }
    
    public void set(double value){
        shooterPID.setSetpoint(value);    	
    }
    
    public void enablePID(){
    	shooterPID.reset();
    	shooterPID.enable();
    	
    	shooterEncoder.reset();
    }
    public void disablePID(){
        shooterPID.disable();
        shooterEncoder.reset();
    }
    public double getShooterPIDOutput(){
    	return shooterOutput.getValue();
    }
    public double getEncoderValue(){
    	return shooterEncoder.get();
    }
}
