package org.usfirst.frc.team9514.robot.subsystems;

import edu.wpi.first.wpilibj.command.Subsystem;

import edu.wpi.first.wpilibj.VictorSP;
import edu.wpi.first.wpilibj.DigitalInput;
import org.usfirst.frc.team9514.robot.commands.Intake;
import org.usfirst.frc.team9514.robot.RobotMap;

/**
 *
 */
public class ExtendingIntake extends Subsystem {

    private VictorSP intakeVictor1;
    private VictorSP intakeVictor2;
    private DigitalInput limitSwitch;
    public ExtendingIntake(){
        intakeVictor1 = new VictorSP(RobotMap.INTAKE_MOTOR1);
        intakeVictor2 = new VictorSP(RobotMap.INTAKE_MOTOR2);
        limitSwitch = new DigitalInput(RobotMap.LIMIT_SWITCH);
    }
    // Put methods for controlling this subsystem
    // here. Call these from Commands.

    public void initDefaultCommand() {
        // Set the default command for a subsystem here.
        //setDefaultCommand(new MySpecialCommand());
        setDefaultCommand(new Intake());

    }
    public boolean getLimitSwitch() {
        return limitSwitch.get();
    }
    public void setRaw1(double value){
        intakeVictor1.set(value);
    }
    public void setRaw2(double value){
        intakeVictor2.set(value);
    }
}

