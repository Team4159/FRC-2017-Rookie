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
	
	private static final double PID_SHOOTER_P=0.1;
	private static final double PID_SHOOTER_I=0.0;
	private static final double PID_SHOOTER_D=0.0;
	private static final double PID_SHOOTER_F=0.7;
	private static final double PID_SHOOTER_TOLERANCE=2;
	

	private VictorSP shooterVictor;
	private Encoder shooterEncoder;
	
    // Initialize your subsystem here
    public PIDShooter() {
    	super("PIDShooter", PID_SHOOTER_P, PID_SHOOTER_I, PID_SHOOTER_D,PID_SHOOTER_F);
		shooterVictor=new VictorSP(RobotMap.SHOOTER_MOTOR);
		
		shooterEncoder=new Encoder(RobotMap.SHOOTER_ENCODER_A,RobotMap.SHOOTER_ENCODER_B);
		shooterEncoder.setPIDSourceType(PIDSourceType.kRate);
		
    	// Use these to get going:
        //enable();//Enables the PID controller.
    	setAbsoluteTolerance(PID_SHOOTER_TOLERANCE);
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
        return shooterEncoder.getRate();
    }

    protected void usePIDOutput(double output) {
        // Use output to drive your system, like a motor
        shooterVictor.set(output);
    }
    
    public void setSetPoint(double speed){
    	super.setSetpoint(speed);
    }
}
