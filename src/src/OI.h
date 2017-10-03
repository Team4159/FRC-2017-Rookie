#ifndef OI_H
#define OI_H

#include <Joystick.h>
#include <Buttons/JoystickButton.h>
class OI {
  public:
    OI();
    double GetLeftDriveValue();
    double GetRightDriveValue();
    //double GetFlywheelValue();
    double GetTurnValue();
    bool GetShooter();
  private:
    std::unique_ptr<Joystick> leftStick; 
    std::unique_ptr<Joystick> rightStick;
    std::unique_ptr<frc::Joystick> secondaryStick;

    //JoystickButton *shootButton;

    Joystick::AxisType LEFT_DRIVE_AXIS = Joystick::AxisType::kYAxis;
    double LEFT_DRIVE_MULTIPLIER = 1;

    Joystick::AxisType RIGHT_DRIVE_AXIS = Joystick::AxisType::kYAxis;
    double RIGHT_DRIVE_MULTIPLIER = 1;

    //Joystick::AxisType FLYWHEEL_AXIS = Joystick::AxisType::kYAxis;
    //double FLYWHEEL_DEFAULT = -0.5;

    //Joystick::AxisType SHOOTING_TURN_AXIS = Joystick::AxisType::kXAxis;
    //double SHOOTING_TURN_MULTIPLIER = 0.5;
    
    bool shooterOn = false;
};

#endif  // OI_H
