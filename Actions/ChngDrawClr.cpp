#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"ChngDrawClr.h"
#include"..\Figures\CFigure.h"

ChngDrawClr:: ChngDrawClr(ApplicationManager *pApp):Action(pApp)
{
}

void ChngDrawClr:: ReadActionParameters()
{
	ActionType Act= pManager->GetUserAction();
	switch(Act)
	{	
	case AWHITE:
		Clr=WHITE;
		break;

	case ABLACK:
		Clr=BLACK;
		break;

	case ARED:
		Clr=RED;
		break;

	case AGREEN:
		Clr=GREEN;
		break;

	case ABLUE:
		Clr=BLUE;
		break;
	}
}

void ChngDrawClr:: Execute() 
{
	Output* pOut = pManager->GetOutput();
	CFigure *c = pManager->GetSelected();
	pOut->PrintMessage("Click on a Colour to Change Drawing Colour.");	
	if (c != NULL)
	{
		ReadActionParameters();
		c->ChngDrawClr(Clr);
	}
	else
	{
		ReadActionParameters();
		pOut->PrintMessage("The Curent Filling Color is Changed.");
		pOut->SetCrntDrawColor(Clr);
	}
	/*if(pManager->GetSelected()!=NULL)
		{
		  pManager->GetSelected()->SetSelected(false);
		pManager->SetSelected(NULL);

		}*/
		
}