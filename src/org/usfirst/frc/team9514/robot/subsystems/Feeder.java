package org.usfirst.frc.team9514.robot.subsystems;

import edu.wpi.first.wpilibj.command.Subsystem;

import edu.wpi.first.wpilibj.Encoder;
import edu.wpi.first.wpilibj.VictorSP;
import edu.wpi.first.wpilibj.PIDController;
import org.usfirst.frc.team9514.robot.RobotMap;
import org.usfirst.frc.team9514.robot.commands.Feed;
/**
 *
 */
public class Feeder extends Subsystem {
    private VictorSP feederVictor;
    public Feeder(){
        feederVictor = new VictorSP(RobotMap.FEEDER_MOTOR);
    // Put methods for controlling this subsystem
    // here. Call these from Commands.
    }
    public void initDefaultCommand() {
        // Set the default command for a subsystem here.
        //setDefaultCommand(new MySpecialCommand());
        setDefaultCommand(new Feed());
    }
    public void setRaw(double value){
        feederVictor.set(value);
    }
    
}

