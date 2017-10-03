#include <memory>
//#include <signal.h>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "CommandBase.h"

#include "CardinalDash/IterativeRobot.h"

class Robot: public CardinalDash::IterativeRobot
{
    public:
        static void term ( int signum );

        void RobotInit() override;

        void RobotPeriodic() override;

        void DisabledInit() override;

        void DisabledPeriodic() override;

        void AutonomousInit() override;

        void AutonomousPeriodic() override;

        void TeleopInit() override;

        void TeleopPeriodic() override;

        void TestPeriodic() override;

    private:
        typedef IterativeRobot super;
        frc::CameraServer * cameraServer;
        Command* autonomousCommand;
        std::unique_ptr<AutoRecorder> autoRecorder;
        SendableChooser<Command*>* chooser;
};