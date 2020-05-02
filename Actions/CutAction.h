#pragma once
#include"Action.h"

class CutAction :public Action
{
public:
   CutAction(ApplicationManager *pApp);

	 void ReadActionParameters();
	
	 void Execute() ;

};