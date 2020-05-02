#pragma once
#include"Action.h"

class DeleteAction:public Action
{
public:
	
	void ReadActionParameters();
	void Execute();
	DeleteAction(ApplicationManager* pApp);
	~DeleteAction();
};

