#pragma once
#include"Action.h"

class PasteAction:public Action
{
	Point PastePoint;
public:
	
	void ReadActionParameters();
	void Execute();
	PasteAction(ApplicationManager* pApp);
};