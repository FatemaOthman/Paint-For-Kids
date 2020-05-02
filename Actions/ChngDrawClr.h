#pragma once
#include"Action.h"
#

class ChngDrawClr :public Action
{
	color Clr;
public:
   ChngDrawClr(ApplicationManager *pApp);

	 void ReadActionParameters();
	
	 void Execute() ;

};