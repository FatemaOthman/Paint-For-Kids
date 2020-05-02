#pragma once
#include"Action.h"


class CopyAction :public Action
{
public:
   CopyAction(ApplicationManager *pApp);

	 void ReadActionParameters();
	
	 void Execute() ;

};