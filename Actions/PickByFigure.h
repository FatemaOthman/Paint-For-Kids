#pragma once
#include"Action.h"
class PickByFigure:public Action
{
	int x;int y;
public:
	void ReadActionParameters();
	void Execute();
	PickByFigure(ApplicationManager *pApp);
	~PickByFigure();
};

