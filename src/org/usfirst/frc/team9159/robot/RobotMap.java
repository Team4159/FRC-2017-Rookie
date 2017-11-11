package org.usfirst.frc.team9159.robot;

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
public class RobotMap {
	// For example to map the left and right motors, you could define the
	// following variables to use with your drivetrain subsystem.
	// public static int leftMotor = 1;
	// public static int rightMotor = 2;
	
	//MOTORS
	public static int LEFT_MOTOR=1;
	public static int RIGHT_MOTOR=2;
	
    public static int SHOOTER_MOTOR=3;
    
    public static int CLIMBER_MOTOR=4;
    
    public static int FEEDER_MOTOR_LEFT=5;
    public static int FEEDER_MOTOR_RIGHT=6;
    
    public static int INTAKE_MOTOR_EXTENDING=7;
    public static int INTAKE_MOTOR_INTAKING=8;
    
    //SENSORS
    public static int SHOOTER_ENCODER_A=0;
    public static int SHOOTER_ENCODER_B=1;
    
    public static int LEFT_DRIVE_ENCODER_A=2;
    public static int LEFT_DRIVE_ENCODER_B=3;
    
    public static int RIGHT_DRIVE_ENCODER_A=4;
    public static int RIGHT_DRIVE_ENCODER_B=5;
    
    //public static int LIMIT_SWITCH = 6;
    
    //SOLENOIDS
    public static int SOLENOID_LEFT_FOWARD = 0;
    public static int SOLENOID_LEFT_REVERSE = 1;
    public static int SOLENOID_RIGHT_FOWARD = 3;
    public static int SOLENOID_RIGHT_REVERSE = 4;
    
	// If you are using multiple modules, make sure to define both the port
	// number and the module. For example you with a rangefinder:
	// public static int rangefinderPort = 1;
	// public static int rangefinderModule = 1;
}
