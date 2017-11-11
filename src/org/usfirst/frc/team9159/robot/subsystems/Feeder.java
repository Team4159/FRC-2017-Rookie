package org.usfirst.frc.team9159.robot.subsystems;

import edu.wpi.first.wpilibj.command.Subsystem;

import edu.wpi.first.wpilibj.VictorSP;
import org.usfirst.frc.team9159.robot.RobotMap;
import org.usfirst.frc.team9159.robot.commands.Feed;
/**
 *
 */
public class Feeder extends Subsystem {
    private VictorSP feederVictorLeft;
    private VictorSP feederVictorRight;
    public Feeder(){
        feederVictorLeft = new VictorSP(RobotMap.FEEDER_MOTOR_LEFT);
        feederVictorRight = new VictorSP(RobotMap.FEEDER_MOTOR_RIGHT);
    // Put methods for controlling this subsystem
    // here. Call these from Commands.
    }
    public void initDefaultCommand() {
        // Set the default command for a subsystem here.
        //setDefaultCommand(new MySpecialCommand());
        setDefaultCommand(new Feed());
    }
    public void setRaw(double value){
        feederVictorLeft.set(value);
        feederVictorRight.set(value);
    }
    
}

