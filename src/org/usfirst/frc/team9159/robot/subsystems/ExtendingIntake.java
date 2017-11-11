package org.usfirst.frc.team9159.robot.subsystems;

import edu.wpi.first.wpilibj.command.Subsystem;

import edu.wpi.first.wpilibj.VictorSP;
//import edu.wpi.first.wpilibj.DigitalInput;
import org.usfirst.frc.team9159.robot.commands.Intake;
import org.usfirst.frc.team9159.robot.RobotMap;

/**
 *
 */
public class ExtendingIntake extends Subsystem {

    private VictorSP intakeVictor1;
    private VictorSP intakeVictor2;
    //private DigitalInput limitSwitch;
    public ExtendingIntake(){
        intakeVictor1 = new VictorSP(RobotMap.INTAKE_MOTOR_EXTENDING);
        intakeVictor2 = new VictorSP(RobotMap.INTAKE_MOTOR_INTAKING);
       // limitSwitch = new DigitalInput(RobotMap.LIMIT_SWITCH);
    }
    // Put methods for controlling this subsystem
    // here. Call these from Commands.

    public void initDefaultCommand() {
        // Set the default command for a subsystem here.
        //setDefaultCommand(new MySpecialCommand());
        setDefaultCommand(new Intake());

    }
//    public boolean getLimitSwitch() {
//        return limitSwitch.get();
//    }
    public void setRawExtending(double value){
        intakeVictor1.set(value);
    }
    public void setRawIntaking(double value){
        intakeVictor2.set(-value);
    }
}

