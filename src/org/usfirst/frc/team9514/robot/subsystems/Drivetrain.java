package org.usfirst.frc.team9514.robot.subsystems;

import edu.wpi.first.wpilibj.Encoder;
import edu.wpi.first.wpilibj.PIDController;
import edu.wpi.first.wpilibj.VictorSP;
import edu.wpi.first.wpilibj.command.Subsystem;
import org.usfirst.frc.team9514.robot.RobotMap;
import org.usfirst.frc.team9514.robot.commands.TeleopDrive;
import org.usfirst.frc.team9514.robot.subsystems.PIDOutputReceiver;

/**
 *
 */
public class Drivetrain extends Subsystem {
	private VictorSP leftMotor;
	private VictorSP rightMotor;
	
	private Encoder leftEncoder;
	private Encoder rightEncoder;
	
	private PIDController leftPID;
	private PIDController rightPID;
	private PIDOutputReceiver leftOutput;
	private PIDOutputReceiver rightOutput;
	
	private final double PID_LEFT_P = 0.0;
    private final double PID_LEFT_I = 0.0;
    private final double PID_LEFT_D = 0.0;
    private final double PID_LEFT_F = 0.0;
    
    private final double PID_RIGHT_P = 0.0;
	private final double PID_RIGHT_I = 0.0;
	private final double PID_RIGHT_D = 0.0;
	private final double PID_RIGHT_F = 0;
	
	private final double ENCODER_PULSE_PER_ROTATION=360;
	private final double ENCODER_WHEEL_DIAMETER=6;
	private final double ENCODER_WHEEL_CIRCUMFERENCE = ENCODER_WHEEL_DIAMETER * Math.PI;
	private final double ENCODER_DISTANCE_PER_PULSE=ENCODER_WHEEL_CIRCUMFERENCE / ENCODER_PULSE_PER_ROTATION;
	
//	private double lastLeft = 0;
//    private double lastLeftGhost = 0;
//    private double lastRight = 0;
//    private double lastRightGhost = 0;
	
	// Put methods for controlling this subsystem
    // here. Call these from Commands.
	
	public Drivetrain(){
		leftMotor = new VictorSP(RobotMap.LEFT_MOTOR);
		rightMotor = new VictorSP(RobotMap.RIGHT_MOTOR);
	
		leftEncoder = new Encoder(RobotMap.LEFT_DRIVE_ENCODER_A, RobotMap.LEFT_DRIVE_ENCODER_B);
		rightEncoder = new Encoder(RobotMap.RIGHT_DRIVE_ENCODER_A, RobotMap.RIGHT_DRIVE_ENCODER_B);
		
		leftOutput = new PIDOutputReceiver();
		rightOutput = new PIDOutputReceiver();
		
		leftPID = new PIDController(PID_LEFT_P, PID_LEFT_I, PID_LEFT_D, PID_LEFT_F, leftEncoder, leftOutput);
		rightPID = new PIDController( PID_RIGHT_P, PID_RIGHT_I, PID_RIGHT_D, PID_RIGHT_F, rightEncoder, rightOutput);
		
		leftEncoder.setReverseDirection(false);
		rightEncoder.setReverseDirection(false);
		
		leftEncoder.setDistancePerPulse(ENCODER_DISTANCE_PER_PULSE);
		rightEncoder.setDistancePerPulse(ENCODER_DISTANCE_PER_PULSE);
		
		leftPID.setContinuous(false);
		rightPID.setContinuous(false);
	}
	public void setRaw(double left, double right, boolean currentLimit){
//		if(currentLimit){
//			setLeftRaw(left);
//			setRightRaw(right);
//		}else{
			leftMotor.set(left);
			rightMotor.set(right);
//		}
	}
	public void set(double leftValue, double rightValue){
		leftPID.setSetpoint(leftValue);
		rightPID.setSetpoint(rightValue);
	}
//	public void setLeftRaw(left){
//		
//	}
//	public void setRightRaw(right){
//		
//	}
	public double getLeftPIDOutput(){
		return leftOutput.getValue();
	}
	public double GetRightPIDOutput(){
		return rightOutput.getValue();
	}
	
	public void enablePID(){
	    leftPID.reset();
	    rightPID.reset();
	    leftPID.enable();
	    rightPID.enable();

	    leftEncoder.reset();
	    rightEncoder.reset();
	}
	public void disablePID(){
	    leftPID.disable();
	    rightPID.disable();

	    leftEncoder.reset();
	    rightEncoder.reset();

//	    lastLeft = 0;
//	    lastRight = 0;
	}
    public void initDefaultCommand() {
        // Set the default command for a subsystem here.
        //setDefaultCommand(new MySpecialCommand());
    	setDefaultCommand(new TeleopDrive());
    }
}

