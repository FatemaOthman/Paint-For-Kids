#pragma once
#include"Action.h"
class SwitchPlayModeAction :public Action
{
public:
	SwitchPlayModeAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();

};