/*
 * VisionMethods.h
 *
 *  Created on: Feb 3, 2017
 *      Author: matthewacho
 */

#ifndef SRC_VISIONMETHODS_H_
#define SRC_VISIONMETHODS_H_


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
