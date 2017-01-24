#ifndef test_H
#define test_H

#include <Commands/Subsystem.h>
#include <VictorSP.h>
class test : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	test();
	void InitDefaultCommand();
	VictorSP* victortest;
};

#endif  // test_H
