package org.usfirst.frc.team9514.robot.subsystems;

import edu.wpi.first.wpilibj.PIDOutput;

public class PIDOutputReceiver implements PIDOutput {
    private double value;
    
    public PIDOutputReceiver(){
    	
    }
    public void pidWrite(double output) {
        // TODO Auto-generated method stub
        value=output;
    }
    public double getValue() {
        // TODO Auto-generated method stub
        return value;
    }
}
