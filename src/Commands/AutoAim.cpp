#include "AutoAim.h"
#include <memory>
#include <opencv2/highgui/highgui.hpp>
#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <vector>
#include "CommandBase.h"
#include "WPILib.h"
#include "GripPipeline.h"
#include <string>
#include <math.h>
#include <vector>
#include "../OI.h"
#include "../RobotMap.h"
#include "../VisionMethods.h"

AutoAim::AutoAim() {
	Requires(drivetrain.get());
	Requires(shooter.get());
	centerX = -1;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}



// Called just before this Command runs the first time
void AutoAim::Initialize() {
	frc::SmartDashboard::PutBoolean("Aiming", true);
	isAiming=true;
	double biggest = -1;
	cv::Point biggestcenter;

	std::vector<std::vector<cv::Point>> contours = filteredContours(cameraPortHigh);
	for(int c=0;c<contours.size();c++) {
		if(contourArea(contours[c])>biggest) {
			biggest=contourArea(contours[c]);  //the vision target on the gear peg.
			biggestcenter=centerOfContour(contours[c]);
		}
	}
	if(biggest == -1) {isAiming = false;}
	if(isAiming) {centerX = biggestcenter.x;}
	ti = new Timer(); ti.Reset(); ti.Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoAim::Execute() {
	if(isAiming) {
		if(centerX > IMG_WIDTH/2) {drivetrain->set(1.0,-1.0);}
		else {drivetrain->set(-1.0,1.0);}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoAim::IsFinished() {
	if(!isAiming) {return true;}
	else if(centerX > IMG_WIDTH/2) {
		return ti.Get() > atan(cameraWidth2Feet*(centerX-(IMG_WIDTH/2))/24.0/IMG_WIDTH)/radiansPerSec;
	}
	else {
		return ti.Get() > atan(cameraWidth2Feet*((IMG_WIDTH/2)-centerX)/24.0/IMG_WIDTH)/radiansPerSec;
	}
}

// Called once after isFinished returns true
void AutoAim::End() {
	delete ti;
	frc::SmartDashboard::PutBoolean("Aiming", false);
	drivetrain->set(0.0,0.0);
	isAiming=false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoAim::Interrupted() {
	delete ti;
	frc::SmartDashboard::PutBoolean("Aiming", false);
	drivetrain->set(0.0,0.0);
	isAiming=false;
}
