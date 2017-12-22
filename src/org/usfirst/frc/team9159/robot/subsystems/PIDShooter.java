package org.usfirst.frc.team9159.robot.subsystems;

import org.usfirst.frc.team9159.robot.RobotMap;
import org.usfirst.frc.team9159.robot.commands.Shoot;

import edu.wpi.first.wpilibj.Encoder;
import edu.wpi.first.wpilibj.PIDSourceType;
import edu.wpi.first.wpilibj.VictorSP;
import edu.wpi.first.wpilibj.command.PIDSubsystem;

/**
 *
 */
public class PIDShooter extends PIDSubsystem {
	//Not tuned. Not tested with a load, so I don't know if it actually works  
	private static final double PID_SHOOTER_P=0.1;
	private static final double PID_SHOOTER_I=0.0;
	private static final double PID_SHOOTER_D=0.0;
	private static final double PID_SHOOTER_F=0.0;
	private static final double PID_SHOOTER_TOLERANCE_PERCENT=5.0;//Input of 15.0 == 15 percent
	

	private static final double COUNTS_PER_REV = 1024;//Pulse/revolution; for vp integrated encoder
	

	private VictorSP shooterVictor;
	private Encoder shooterEncoder;

	private double motorInput;
	
    // Initialize your subsystem here
    public PIDShooter() {
    	super("PIDShooter", PID_SHOOTER_P, PID_SHOOTER_I, PID_SHOOTER_D,PID_SHOOTER_F);
		shooterVictor=new VictorSP(RobotMap.SHOOTER_MOTOR);

		
		shooterEncoder=new Encoder(RobotMap.SHOOTER_ENCODER_A,RobotMap.SHOOTER_ENCODER_B);
		shooterEncoder.setPIDSourceType(PIDSourceType.kRate);
		shooterEncoder.setDistancePerPulse(1.0/COUNTS_PER_REV);//Revolutions/pulse
		
    	// Use these to get going:
        enable();//Enables the PID controller.
		getPIDController().setContinuous(true);
		setPercentTolerance(PID_SHOOTER_TOLERANCE_PERCENT);
    	setOutputRange(0.0,1.0);//Make sure they don't try to run backward
    }
    
    public void setRaw(double speed){
    	shooterVictor.set(speed);
    }

    public void initDefaultCommand() {
        // Set the default command for a subsystem here.
        setDefaultCommand(new Shoot());
    }

    protected double returnPIDInput() {
        // Return your input value for the PID loop
        // e.g. a sensor, like a potentiometer:
        // yourPot.getAverageVoltage() / kYourMaxVoltage;
        return shooterEncoder.getRate();//Distance/sec (Distance as defined by setDistancePerPulse())
    }

    protected void usePIDOutput(double output) {
    	motorInput=output;
        // Use output to drive your system, like a motor
        shooterVictor.set(output);
    }
    
    public double getEncoderRate(){
    	return shooterEncoder.getRate();
    }
    
    public double getPIDOutput(){
    	return motorInput;
    }
    
    public void setSetPoint(double speed){
    	super.setSetpoint(speed);
    }
}
