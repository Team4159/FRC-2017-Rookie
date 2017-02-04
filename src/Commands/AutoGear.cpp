#include "AutoGear.h"

AutoGear::AutoGear() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain.get());
	Requires(gearouttake.get());
	centerX = -1;
	stage = 1;
	rotato = -1;
	rotato2 = -1;
	stage2Dist = -1;
	turnClockwise = false;
}

//CASHEWS, CASHEWS, COME FROM A FRUIT!

// Called just before this Command runs the first time
void AutoGear::Initialize() {
	double biggest = 0;
	double secondbiggest = 0;
	cv::Point biggestcenter;
	cv::Point secondbiggestcenter;
	std::vector<std::vector<cv::Point>> contours = filteredContours(cameraPortLow);
	for(int c=0;c<contours.size();c++) {
		if(contourArea(contours[c])>biggest) {
			secondbiggest = biggest;
			secondbiggestcenter = biggestcenter;
			biggest=contourArea(contours[c]);  //the vision target on the gear peg.
			biggestcenter=centerOfContour(contours[c]);
		}
		else if(contourArea(contours[c])>secondbiggest) {
			secondbiggest=contourArea(contours[c]);
			secondbiggestcenter=centerOfContour(contours[c]);
		}
	}
	centerX = (biggestcenter.x+secondbiggestcenter.x)/2;

	//If you're confused about this ask Matthew

	//That's why you explain your code to the cookie!
	if(centerX - (IMG_WIDTH/2) > 0) {turnClockwise = true;}
	double distFromCameraToCenter = (cameraWidth2Feet * distFromGearPeg() * (abs(centerX - (IMG_WIDTH)/2)))/(24.0*IMG_WIDTH);
	double theta =  atan(cameraWidth2Feet*(centerX-(IMG_WIDTH/2))/24.0/IMG_WIDTH);
	double phi = asin(distFromGearPeg()*sin(theta)/distFromCameraToCenter);
	stage2Dist = sqrt(144+pow(distFromGearPeg(),2)-24*distFromGearPeg()*cos(theta+phi-pi/2));
	rotato = asin( (12*sin(theta+phi-pi/2)) / stage2Dist );
	rotato2 = asin(distFromGearPeg()*sin(rotato)/12);
	tim = new Timer(); tim.Reset(); tim.Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoGear::Execute() {
	switch(stage) {
		case 1: {
			if(tim.Get()>rotato/radiansPerSec) {stage++; tim.Reset(); drivetrain->set(0.0,0.0);}
			else {
				if(turnClockwise) {drivetrain->set(1.0,-1.0);}
				else {drivetrain->set(-1.0,1.0);}
			}
			break;
		}
		case 2: {
			if(tim.Get() == 0.0) {tim.Start();}
			else if(tim.Get() > stage2Dist/robotSpeed) {stage++; tim.Reset(); drivetrain->set(0.0,0.0);}
			else {drivetrain->set(1.0,1.0);}
			break;
		}
		case 3: { //same as case 1, but rotating by rotato2 instead of rotato
			if(tim.Get() == 0.0) {tim.Start();}
			else if(tim.Get()>rotato2/radiansPerSec) {stage++; tim.Reset(); drivetrain->set(0.0,0.0);}
			else {
				if(turnClockwise) {drivetrain->set(-1.0,1.0);}
				else {drivetrain->set(1.0,-1.0);} //also turning in the opposite direction
			}
			break;
		}
		case 4: {
			if(tim.Get() == 0.0) {tim.Start();}
			else if(tim.Get() > 12/robotSpeed) {stage++; tim.Reset(); drivetrain->set(0.0,0.0);}
			else {drivetrain->set(1.0,1.0);}
			break;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoGear::IsFinished() {
	return stage == 5;
}

// Called once after isFinished returns true
void AutoGear::End() {
	gearouttake->ReleaseGear();
	Drive(-24);
}
//O Holy Mother, grant me the strength to deal with this putrid lawyer. -Nahyuta Sahdmadhi

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoGear::Interrupted() {

}
