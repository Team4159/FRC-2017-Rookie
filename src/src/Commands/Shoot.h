#ifndef Shoot_H
#define Shoot_H

#include "../CommandBase.h"

class Shoot: public CommandBase {
  public:
    Shoot(double speed);
    void Initialize();
    void Execute();
    bool IsFinished();
    void End();
    void Interrupted();
  private:
    double shooterSpeed;
};

#endif  // Shoot_H
