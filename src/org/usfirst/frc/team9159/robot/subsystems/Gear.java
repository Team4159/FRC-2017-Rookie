package org.usfirst.frc.team9159.robot.subsystems;

import edu.wpi.first.wpilibj.command.Subsystem;
import edu.wpi.first.wpilibj.DoubleSolenoid;
import org.usfirst.frc.team9159.robot.RobotMap;
/**
 *
 */
public class Gear extends Subsystem {
    DoubleSolenoid gearSolenoidLeft;
    DoubleSolenoid gearSolenoidRight;
    public Gear(){
        gearSolenoidLeft = new DoubleSolenoid(RobotMap.SOLENOID_LEFT_FOWARD, RobotMap.SOLENOID_LEFT_REVERSE);
        gearSolenoidRight = new  DoubleSolenoid(RobotMap.SOLENOID_RIGHT_FOWARD, RobotMap.SOLENOID_RIGHT_REVERSE);
    }
    // Put methods for controlling this subsystem
    // here. Call these from Commands.

    public void initDefaultCommand() {
        // Set the default command for a subsystem here.
        //setDefaultCommand(new MySpecialCommand());
    }
    
    public void setSolenoid(boolean up) {
        gearSolenoidLeft.set(up ? DoubleSolenoid.Value.kForward : DoubleSolenoid.Value.kReverse);
        gearSolenoidRight.set(up ? DoubleSolenoid.Value.kForward : DoubleSolenoid.Value.kReverse);
    }
}

