#include"PasteAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


void PasteAction::ReadActionParameters()
{
	Input*pin = pManager->GetInput();
	Output*pOut = pManager->GetOutput();
	pOut->PrintMessage("Click where you want to paste!");
	pin->GetPointClicked(PastePoint.x, PastePoint.y);
}
void PasteAction::Execute()
{
	ReadActionParameters();
	Output*pOut = pManager->GetOutput();
	CFigure*c = pManager->GetClipboard();
	Input*pin=pManager->GetInput();
	if(c!=NULL)
	{
		CFigure*c2 = c->Paste(PastePoint.x,PastePoint.y);
		pManager->AddFigure(c2);
	}
	else
	{
		
		pOut->PrintMessage("There is no copied figure");
	}

}
PasteAction::PasteAction(ApplicationManager *pApp):Action(pApp)
{
}

