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
    Timer tim;
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;
    double m;
    double pathlength;
    double radiansPerSec;
    bool turnClockwise;
};


#endif  // AutoGear_H
