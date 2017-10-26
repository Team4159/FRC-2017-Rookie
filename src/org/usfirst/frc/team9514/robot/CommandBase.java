package org.usfirst.frc.team9514.robot;

import org.usfirst.frc.team9514.robot.OI;
import org.usfirst.frc.team9514.robot.subsystems.Drivetrain;
import org.usfirst.frc.team9514.robot.subsystems.Shooter;

public class CommandBase {
	//Initialize subsystems
	public static final Shooter shooter = new Shooter();
	public static final Drivetrain drivetrain = new Drivetrain();
	public static final Climber climber = new Climber();
	
	public static OI oi = new OI();
	
	public CommandBase(){
		
	}
	
	public static void Init(){
		
	}
	
	public static void enable(){
		
	}
	public static void disable(){
		
	}
}
