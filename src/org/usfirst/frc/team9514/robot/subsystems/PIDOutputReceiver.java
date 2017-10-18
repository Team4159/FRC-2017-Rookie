package org.usfirst.frc.team9514.robot.subsystems;

import edu.wpi.first.wpilibj.PIDOutput;

public class PIDOutputReceiver implements PIDOutput {
    private double value;
    
    public void PIDWrite(double output){
        value=output;
    }
    
    @Override
    public void pidWrite(double output) {
        // TODO Auto-generated method stub
        
    }
    public double getValue() {
        // TODO Auto-generated method stub
        return value;
    }
}
