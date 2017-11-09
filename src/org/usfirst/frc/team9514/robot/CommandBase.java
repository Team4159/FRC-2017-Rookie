package org.usfirst.frc.team9514.robot;

import org.usfirst.frc.team9514.robot.OI;
import org.usfirst.frc.team9514.robot.subsystems.Climber;
import org.usfirst.frc.team9514.robot.subsystems.Drivetrain;
import org.usfirst.frc.team9514.robot.subsystems.Shooter;
import org.usfirst.frc.team9514.robot.subsystems.Feeder;
import org.usfirst.frc.team9514.robot.subsystems.ExtendingIntake;
import org.usfirst.frc.team9514.robot.subsystems.Gear;

public class CommandBase {
	//Initialize subsystems
	public static Shooter shooter;
	public static Drivetrain drivetrain;
	public static Climber climber;
	public static Feeder feeder;
    public static ExtendingIntake intaker;	
	public static OI oi;
	public static Gear gear;
	
	public CommandBase(){
		
	}
	
	public static void init(){
		oi = new OI();
	    intaker = new ExtendingIntake();	
		shooter = new Shooter();
		drivetrain = new Drivetrain();
		climber = new Climber();
		feeder = new Feeder();
		gear = new Gear();
	}
	
	public static void enable(){
		
	}
	public static void disable(){
		
	}
}
