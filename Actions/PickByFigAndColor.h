#pragma once
#include"Action.h"
class PickByFigAndColor:public Action
{

public:
	void ReadActionParameters();
	void Execute();
	PickByFigAndColor(ApplicationManager*pApp);
	~PickByFigAndColor();
};

