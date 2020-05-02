#pragma once
#include"Action.h"
class SwitchToDrawModeAction :public Action
{
public:
	SwitchToDrawModeAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();

};