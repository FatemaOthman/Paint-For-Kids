#pragma once
#include"Action.h"


class ExtAction :public Action
{
public:
	ExtAction(ApplicationManager *pApp);

	void ReadActionParameters();

	void Execute();

};
