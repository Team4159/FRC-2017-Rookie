#ifndef AutoAim_H
#define AutoAim_H

#include "../CommandBase.h"

class AutoAim : public CommandBase {
public:
	AutoAim();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AutoAim_H
