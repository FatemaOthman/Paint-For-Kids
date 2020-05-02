#pragma once
#include"Action.h"
class BringToFrontAction:public Action
{
public:
	void Execute();
	void ReadActionParameters();
	BringToFrontAction(ApplicationManager *pApp);
	~BringToFrontAction();
};

