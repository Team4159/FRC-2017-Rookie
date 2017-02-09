#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <string>
#include "CommandBase.h"
#include "VisionMethods.h"

class Robot: public frc::IterativeRobot {
public:
	void RobotInit() override {
		// chooser.AddObject("My Auto", new MyAutoCommand());
		setupSmartDashboard();
		frc::SmartDashboard::PutData("Auto Modes", &chooser);
	}

	/**
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
	 */
	void DisabledInit() override {

	}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to the
	 * chooser code above (like the commented example) or additional comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() override {
		chooser.AddDefault("Default Auto", new Drive(24.0));
		chooser.AddDefault("Default Auto", new AutoGear());
		switch(initialOrientation()) {
			case "left": {
				chooser.AddDefault("Default Auto", new Turn(74.81, false)); //turn towards hopper
				chooser.AddDefault("Default Auto", new Drive(112.23)); //drive in front of it
				chooser.AddDefault("Default Auto", new Turn(75.19, false)); //turn towards it
				chooser.AddDefault("Default Auto", new Drive(50)); //ram into it
				chooser.AddDefault("Default Auto", new Drive(-48)); //back up to give space to turn
				chooser.AddDefault("Default Auto", new Turn(90, false)); //turn towards left hopper
				chooser.AddDefault("Default Auto", new Drive(36)); //pick up some balls
				chooser.AddDefault("Default Auto", new Turn(180, true)); //turn towards right hopper
				chooser.AddDefault("Default Auto", new Drive(80));
				chooser.AddDefault("Default Auto", new Turn(90, true)); //this is the route to the boiler
				chooser.AddDefault("Default Auto", new Drive(228));
				chooser.AddDefault("Default Auto", new Turn(90, true));
				chooser.AddDefault("Default Auto", new Drive(160));
				break;
			}

			case "middle": {
				chooser.AddDefault("Default Auto", new Turn(58.18, true));
				chooser.AddDefault("Default Auto", new Drive(134.17));
				chooser.AddDefault("Default Auto", new Turn(31.82, true));
				chooser.AddDefault("Default Auto", new Drive(50)); //ram into it
				chooser.AddDefault("Default Auto", new Drive(-48)); //back up to give space to turn
				chooser.AddDefault("Default Auto", new Turn(90, false)); //turn towards left hopper
				chooser.AddDefault("Default Auto", new Drive(36)); //pick up some balls
				chooser.AddDefault("Default Auto", new Turn(180, true)); //turn towards right hopper
				chooser.AddDefault("Default Auto", new Drive(90));
				break;
			}
			case "right": {
				chooser.AddDefault("Default Auto", new Turn(113.16, true));
				chooser.AddDefault("Default Auto", new Drive(35.86));
				chooser.AddDefault("Default Auto", new Turn(36.84, true));
				chooser.AddDefault("Default Auto", new Drive(50)); //ram into it
				chooser.AddDefault("Default Auto", new Drive(-48)); //back up to give space to turn
				chooser.AddDefault("Default Auto", new Turn(90, false)); //turn towards left hopper
				chooser.AddDefault("Default Auto", new Drive(36)); //pick up some balls
				chooser.AddDefault("Default Auto", new Turn(180, true)); //turn towards right hopper
				chooser.AddDefault("Default Auto", new Drive(90));
				break;
			}
			chooser.AddDefault("Default Auto", new AutoAim());
		}
		chooser.AddDefault("Default Auto", new Shoot());
		/* std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");
		if (autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		}
		else {
			autonomousCommand.reset(new ExampleCommand());
		} */

		autonomousCommand.reset(chooser.GetSelected());

		if (autonomousCommand.get() != nullptr) {
			autonomousCommand->Start();
		}
	}

	void AutonomousPeriodic() override {

		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != nullptr) {
			autonomousCommand->Cancel();
		}

	}

	void TeleopPeriodic() override {
		CommandBase::drivetrain->set(CommandBase::oi->getLeftDriveValue(), CommandBase::oi->getRightDriveValue());
		frc::Scheduler::GetInstance()->Run();
	}

	void TestPeriodic() override {
		frc::LiveWindow::GetInstance()->Run();
	}

private:
	std::unique_ptr<frc::Command> autonomousCommand;
	frc::SendableChooser<frc::Command*> chooser;
	void setupSmartDashboard() {

	}
};

START_ROBOT_CLASS(Robot)
