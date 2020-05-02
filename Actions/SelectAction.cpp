#include "SelectAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


void SelectAction::Execute()
{
	ReadActionParameters();
	CFigure *c = pManager->GetFigure(P.x, P.y);
	pManager->SetSelected(c);
	Output *pOut = pManager->GetOutput();
	if (c != NULL)
	{
		
		c->PrintInfo(pOut);
	}


}
void SelectAction::ReadActionParameters()
{
	Output *pOut = pManager->GetOutput();
	Input *pIn = pManager->GetInput();
	if (!HideMsg)
	{
		pOut->PrintMessage("Click on the figure you want to select.");
	}
	int x;
	int y;
	pIn->GetPointClicked(x, y);
	P.x = x;
	P.y = y;
	if (!HideMsg)
	{
		pOut->ClearStatusBar();
	}
}

SelectAction::SelectAction(ApplicationManager *pApp,bool h):Action(pApp),HideMsg(h)
{
}
SelectAction::~SelectAction()
{
}
