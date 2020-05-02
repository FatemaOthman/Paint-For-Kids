#pragma once
#include"Action.h"

class BringToBackAction:public Action
{
public:
	void Execute();
	void ReadActionParameters();
	BringToBackAction(ApplicationManager *pApp);
	~BringToBackAction();
};

