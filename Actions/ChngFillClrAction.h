#pragma once
#include"Action.h"
#

class ChngFillClrAction :public Action
{
	color Clr;
public:
   ChngFillClrAction(ApplicationManager *pApp);

	 void ReadActionParameters();
	
	 void Execute() ;

};