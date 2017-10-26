import edu.wpi.first.wpilibj.command.Subsystem;
import org.usfirst.frc.team9514.robot.RobotMap;

import edu.wpi.first.wpilibj.VictorSP;

class Climber extends Subsystem{
  private VictorSP climberMotor;
  Climber() {
    climberMotor = new VictorSP(RobotMap.CLIMBER_MOTOR);
  }
  public set(double speed) {
    climberMotor.Set(speed);
  }
}
