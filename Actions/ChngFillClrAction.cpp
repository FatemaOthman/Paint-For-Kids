#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"ChngFillClrAction.h"
#include"..\Figures\CFigure.h"

ChngFillClrAction:: ChngFillClrAction(ApplicationManager *pApp):Action(pApp)
{
}

void ChngFillClrAction:: ReadActionParameters()
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

void ChngFillClrAction:: Execute() 
{
	Output* pOut = pManager->GetOutput();
	CFigure *c = pManager->GetSelected();
	pOut->PrintMessage("Click on a Colour to Change Fill Colour.");	
	if (c != NULL)
	{
		ReadActionParameters();
		c->ChngFillClr(Clr);
	}
	else
	{
		ReadActionParameters();
		pOut->PrintMessage("The Curent Filling Color is Changed.");
		
		//FigGfxInfo.isFilled=true;
		pOut->SetCrntFillColor(Clr);

	}
	/*if(pManager->GetSelected()!=NULL)
		{
		  pManager->GetSelected()->SetSelected(false);
		pManager->SetSelected(NULL);

		}*/
}