#include "Shooter.h"
#include "../RobotMap.h"

#include <Commands/Shoot.h>
#include <VictorSP.h>
#include <SmartDashboard/SmartDashboard.h>

#include <cmath>

std::unique_ptr<PowerDistributionPanel> Shooter::pdp = std::make_unique<PowerDistributionPanel>();

Shooter::Shooter() : Subsystem("Shooter") {
  //flywheelMotor = new VictorSP(shooterFlywheelMotor);
  ShooterVictor = std::make_unique<VictorSP> (MOTOR_SHOOTER);
  
  ShooterEncoder = std::make_unique<frc::Encoder>( ENCODER_SHOOTER_A, ENCODER_SHOOTER_B );
  ShooterEncoder->SetReverseDirection( false );
  ShooterEncoder->SetDistancePerPulse( ENCODER_DISTANCE_PER_PULSE );
  
  ShooterOutput = std::make_unique<PIDOutputReceiver>();
  ShooterPID = std::make_unique<frc::PIDController>( PID_SHOOTER_P, PID_SHOOTER_I, PID_SHOOTER_D, PID_SHOOTER_F, ShooterEncoder.get(), ShooterOutput.get() );
  
  ShooterPID->SetContinuous( true );//maybe true?
  ShooterPID->SetAbsoluteTolerance( PID_SHOOTER_TOLERANCE );
  
  LiveWindow::GetInstance()->AddActuator( "Shooter", "ShooterPID", ShooterPID.get() );
  LiveWindow::GetInstance()->AddSensor( "Shooter", "ShooterEncoder", ShooterEncoder.get() );
}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
  
  SetDefaultCommand( new Shoot(20) );
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

//void Shooter::SetFlywheel(double value){
//	flywheelMotor->Set(value);
//	frc::SmartDashboard::PutNumber("FlywheelPower", value);
//}

void Shooter::SetRaw ( double value){
  //if ( currentLimit ){
   //   SetShooterRaw( value );
  //} else {//why?
      ShooterVictor->Set( value );
  //}
}

void Shooter::Set(double value){
    ShooterPID->SetSetpoint(value);
}

//void Shooter::SetAdd(double value){
//    ShooterPID->SetSetpoint(ShooterPID->GetSetpoint() + value);
//}

// void Shooter::SetShooterRaw(double value){
    // double voltage = pdp->GetVoltage();
    // double maxDiff = MAX_ACCEL * voltage;

    // if ( fabs(value) - fabs(lastValue) > maxDiff ) {
        // if ( lastValue > value ) {
            // if ( lastValue < 0 && lastValueGhost > 0 ) {
                // value = lastValueGhost - maxDiff;
            // } else {
                // value = lastValue - maxDiff;
            // }
        // } else {
            // if ( lastValue > 0 && lastValueGhost < 0 ) {
                // value = lastValueGhost + maxDiff;
            // } else {
                // value = lastValue + maxDiff;
            // }
        // }
    // }
    // if ( lastValueGhost > lastValue ) {
        // lastValueGhost -= MAX_GHOST_ACCEL;
        // if ( lastValueGhost > lastValue ) {
            // lastValueGhost = lastValue;
        // }
    // } else {
        // lastValueGhost += MAX_GHOST_ACCEL;
        // if ( lastValueGhost < lastValue ) {
            // lastValueGhost = lastValue;
        // }
    // }

    // double valueTotal = pdp->GetCurrent(SHOOTER_CHANNEL);

    // if ( valueTotal > 100 ){
        // value /= ( 100/valueTotal );
    // }

    // if ( voltage < 10 ){
        // value /= ( 10/voltage );
    // }

    // ShooterVictor->Set( value );

    // lastValue = value;
// }

void Shooter::EnablePID(){
  ShooterPID->Reset();
  ShooterPID->Enable();

  ShooterEncoder->Reset();
}

void Shooter::DisablePID(){
  ShooterPID->Disable();
  ShooterEncoder->Reset();

  lastValue = 0;
}

double Shooter::GetShooterPIDOutput(){
  return ShooterOutput->GetValue();
}

double Shooter::GetEncoderValue ( void* instance ){
    return ( ( Encoder*) instance )->Get();
}