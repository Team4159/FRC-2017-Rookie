#ifndef Drive_H
#define Drive_H

#include "../CommandBase.h"

class Drive : public CommandBase {
public:
	Drive(int seconds);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double inches;
	Timer t;
	bool isForward;
};

#endif  // Drive_H
