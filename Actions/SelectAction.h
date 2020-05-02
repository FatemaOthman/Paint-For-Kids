#pragma once
#include"Action.h"
class SelectAction :public Action
{
	Point P;
	bool HideMsg;
	friend class PickByFigure;
	friend class PickByColor;
	friend class PickByFigAndColor;
public:
	

	void ReadActionParameters();
	void Execute();
	SelectAction(ApplicationManager *pApp, bool h = false);
	~SelectAction();
};

