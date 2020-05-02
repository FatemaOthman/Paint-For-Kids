#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"CutAction.h"

CutAction:: CutAction(ApplicationManager *pApp):Action(pApp)
{
}

void CutAction:: ReadActionParameters()
{
}

void CutAction:: Execute() 
{
	CFigure *c = pManager->GetSelected();
	Output* pOut = pManager->GetOutput();
	
	if (c != NULL)
	{
		pManager->setclipboard(c->Copy());
    	pOut->PrintMessage("The Figure is cut to the clibboard.");	
		pManager->DeleteFig();
		pManager->SetSelected(NULL);
	}
	else
	{
		pOut->PrintMessage("There is no selected figure to cut.");
	}
	
}