package org.usfirst.frc.team9514.robot.subsystems;

import edu.wpi.first.wpilibj.command.Subsystem;
import edu.wpi.first.wpilibj.DoubleSolenoid;
import org.usfirst.frc.team9514.robot.RobotMap;
/**
 *
 */
public class Gear extends Subsystem {
    DoubleSolenoid gearSolenoid;
    public Gear(){
        gearSolenoid = new DoubleSolenoid(RobotMap.SOLENOID1, RobotMap.SOLENOID2);
    }
    // Put methods for controlling this subsystem
    // here. Call these from Commands.

    public void initDefaultCommand() {
        // Set the default command for a subsystem here.
        //setDefaultCommand(new MySpecialCommand());
    }
    
    public void setSolenoid(boolean up) {
        gearSolenoid.set(up ? DoubleSolenoid.Value.kForward : DoubleSolenoid.Value.kReverse);
    }
}

