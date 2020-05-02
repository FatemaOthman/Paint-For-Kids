#pragma once
#include"Action.h"
class PickByColor:public Action
{
public:
	void ReadActionParameters();
	void Execute();
	PickByColor(ApplicationManager *pApp);
	~PickByColor();
};

