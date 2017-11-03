package org.usfirst.frc.team9514.robot;

import org.usfirst.frc.team9514.robot.OI;
import org.usfirst.frc.team9514.robot.subsystems.Climber;
import org.usfirst.frc.team9514.robot.subsystems.Drivetrain;
import org.usfirst.frc.team9514.robot.subsystems.Shooter;

public class CommandBase {
	//Initialize subsystems
	public static Shooter shooter;
	public static Drivetrain drivetrain;
	public static Climber climber;
	
	public static OI oi;
	
	public CommandBase(){
		
	}
	
	public static void init(){
		oi = new OI();
		
		shooter = new Shooter();
		drivetrain = new Drivetrain();
		climber = new Climber();
	}
	
	public static void enable(){
		
	}
	public static void disable(){
		
	}
}
