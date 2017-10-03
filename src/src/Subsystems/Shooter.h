#ifndef SHOOTER_H
#define SHOOTER_H

#include <Commands/Subsystem.h>
#include <math.h>
#include <Encoder.h>
#include <PIDController.h>
#include <VictorSP.h>
#include "PIDOutputReceiver.h"

#include "WPILib.h"

class Shooter : public Subsystem {
  public:
    Shooter();
    void InitDefaultCommand();
    void Set(double value);
    void SetRaw(double value);
    void SetAdd(double value);
    void SetShooterRaw(double value);
    //bool IsShooting = false;
    
    void EnablePID();
    void DisablePID();
    
    double GetShooterPIDOutput();
  private:
    const double ENCODER_PULSE_PER_ROTATION = 360;
    const double ENCODER_WHEEL_DIAMETER = 2; // inches
    const double ENCODER_WHEEL_CIRCUMFERENCE = ENCODER_WHEEL_DIAMETER * M_PI;
    const double ENCODER_DISTANCE_PER_PULSE = ENCODER_WHEEL_CIRCUMFERENCE / ENCODER_PULSE_PER_ROTATION;

    const double PID_SHOOTER_P = 0.3;
    const double PID_SHOOTER_I = 0.0;
    const double PID_SHOOTER_D = 0.0;
    const double PID_SHOOTER_F = 0.8;
    const double PID_SHOOTER_TOLERANCE = 2;

    double lastValue = 0;
    double lastValueGhost = 0;

    const double ACCEL_MULT = 1.2;

    const double MAX_ACCEL = 0.0025 * ACCEL_MULT;
    const double MAX_GHOST_ACCEL = 15 * MAX_ACCEL;

    static std::unique_ptr<PowerDistributionPanel> pdp;
    
    std::unique_ptr<VictorSP> ShooterVictor;

    std::unique_ptr<frc::Encoder> ShooterEncoder;

    std::unique_ptr<frc::PIDController> ShooterPID;
    std::unique_ptr<PIDOutputReceiver> ShooterOutput;

    static double GetEncoderValue ( void* instance );

    //VictorSP* flywheelMotor;
};

#endif  // SHOOTER_H
