#pragma once
#include"Action.h"
class AddLineAction :public Action
{
private:
	Point P1, P2; 
	GfxInfo LineGfxInfo;

public:
     AddLineAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;
	
};

