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

AutoAim::AutoAim() {
	Requires(drivetrain.get());
	Requires(shooter.get());
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}



std::vector<std::vector<cv::Point>> filteredContours(int cameranum) {
	cv::Mat frame;
	cv::VideoCapture cap(cameranum);
	cap.set(CV_CAP_PROP_FRAME_WIDTH, IMG_WIDTH);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, IMG_HEIGHT);
	bool bSuccess = cap.read(frame);
	return gp.GripPipeline::process(frame);
}

double distFromHighGoal() { //Find distance from the center of the boiler, in inches.
	int maxArea = 0;
	double bestHeight = 0.0;
	std::vector<std::vector<cv::Point>> contours = filteredContours(cameraPortHigh);
	for(int c=0;c<contours.size();c++) {
		if(contourArea(contours[c])>maxArea) {
			maxArea=contourArea(contours[c]);
			bestHeight = boundingRect(contours[c]).height;
		}
	}
	//Pixel height and distance are inversely proportional
	return 48.0*bestHeight/targetHeight4FeetFromHighGoal;
}

double distFromGearPeg() { //Find distance from the gear peg, in inches.
	int maxArea = 0;
	double bestHeight = 0.0;
	std::vector<std::vector<cv::Point>> contours = filteredContours(cameraPortLow);
	for(int c=0;c<contours.size();c++) {
		if(contourArea(contours[c])>maxArea) {
			maxArea=contourArea(contours[c]);
			bestHeight = boundingRect(contours[c]).height;
		}
	}
	//Pixel height and distance are inversely proportional
	return 48.0*bestHeight/targetHeight4FeetFromGearPeg;
}

cv::Point centerOfContour(std::vector<cv::Point> contour) {
	int totalx=0.0;
	int totaly=0.0;
	for(int d=0; d<contour.size();d++) {
		totalx+=contour[d].x;
		totaly+=contour[d].y;
	}
	cv::Point pt;
	pt.x=totalx/contour.size();
	pt.y=totaly/contour.size();
	return pt;
}

// Called just before this Command runs the first time
void AutoAim::Initialize() {
	frc::SmartDashboard::PutBoolean("Aiming", true);
	isAiming=true;
	//The next 2 while loops put the robot in position to shoot
	std::vector<std::vector<cv::Point>> contours;
	double biggest = 0;
	cv::Point biggestcenter;

	contours = filteredContours(cameraPortHigh);
	for(int c=0;c<contours.size();c++) {
		if(contourArea(contours[c])>biggest) {
			biggest=contourArea(contours[c]);  //the vision target on the gear peg.
			biggestcenter=centerOfContour(contours[c]);
		}
	}
	int centerX = biggestcenter.x;

	//Turns until the camera is aligned with the goal, using the distance algorithm.

	if(centerX > IMG_WIDTH/2) {
		drivetrain->set(1.0,-1.0);
		Wait(atan(cameraWidth2Feet*(centerX-(IMG_WIDTH/2))/24.0)/radiansPerSec);
		drivetrain->set(0.0,0.0);
	}
	else {
		drivetrain->set(-1.0,1.0);
		Wait(atan(cameraWidth2Feet*((IMG_WIDTH/2)-centerX)/24.0)/radiansPerSec);
		drivetrain->set(0.0,0.0);
	}


	drivetrain->set(1.0,1.0);
	Wait((distFromHighGoal()-bestDistFromHighGoal)/robotSpeed); //drives until the optimal
	drivetrain->set(0.0,0.0);                                   //shooting distance is reached
	isAiming=false;
}

// Called repeatedly when this Command is scheduled to run
void AutoAim::Execute() {
	if(!isAiming) {Shoot();}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoAim::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AutoAim::End() {
	frc::SmartDashboard::PutBoolean("Aiming", false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoAim::Interrupted() {

}
