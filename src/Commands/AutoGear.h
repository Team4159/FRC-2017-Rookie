#ifndef AutoGear_H
#define AutoGear_H

#include "../CommandBase.h"

class AutoGear : public CommandBase {
public:
	AutoGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double centerX;
	Timer tim;
	int stage;
	double rotato;
	double rotato2;
	double stage2Dist;
	bool turnClockwise;
};

#endif  // AutoGear_H
