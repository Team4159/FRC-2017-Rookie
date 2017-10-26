package org.usfirst.frc.team9514.robot.subsystems;

import edu.wpi.first.wpilibj.command.Subsystem;
import edu.wpi.first.wpilibj.Encoder;
import edu.wpi.first.wpilibj.VictorSP;
import edu.wpi.first.wpilibj.PIDController;

import org.usfirst.frc.team9514.robot.RobotMap;
import org.usfirst.frc.team9514.robot.subsystems.PIDOutputReceiver;

/**
 *
 */
public class Shooter extends Subsystem {
	//private static final double ENCODER_PULSE_PER_ROTATION=360;
	
	private static final double PID_SHOOTER_P=0.0;
	private static final double PID_SHOOTER_I=0.0;
	private static final double PID_SHOOTER_D=0.0;
	private static final double PID_SHOOTER_F=0.0;
	private static final double PID_SHOOTER_TOLERANCE=2;
	
	private static int TARGET_SPEED = 3000;
	
	private VictorSP shooterVictor;
	private Encoder shooterEncoder;
	private PIDController shooterPID;
	private PIDOutputReceiver shooterOutput;
	
    // Put methods for controlling this subsystem
    // here. Call these from Commands.
	
	public Shooter(){
		shooterVictor=new VictorSP(RobotMap.SHOOTER_MOTOR);
		
		shooterEncoder=new Encoder(RobotMap.SHOOTER_ENCODER_A,RobotMap.SHOOTER_ENCODER_B);
		
		shooterOutput=new PIDOutputReceiver();
		shooterPID = new PIDController(PID_SHOOTER_P, PID_SHOOTER_I, PID_SHOOTER_D, PID_SHOOTER_F, 
		                             shooterEncoder, shooterOutput);
		
		
		shooterPID.setContinuous(true);//maybe?
		shooterPID.setAbsoluteTolerance(PID_SHOOTER_TOLERANCE);
		
		set(TARGET_SPEED);
		
	}
	
    public void initDefaultCommand() {
        // Set the default command for a subsystem here.
        //setDefaultCommand(new MySpecialCommand());
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
}

