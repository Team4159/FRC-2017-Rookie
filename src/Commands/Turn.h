#ifndef Turn_H
#define Turn_H

#include "../CommandBase.h"

class Turn : public CommandBase {
public:
	Turn(double degrees, bool isClockwise);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double angle; //radians
	Timer time;
	bool isClockwise;
};

#endif  // Turn_H
