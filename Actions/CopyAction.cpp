#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"CopyAction.h"

CopyAction:: CopyAction(ApplicationManager *pApp):Action(pApp)
{
}

void CopyAction:: ReadActionParameters()
{
}

void CopyAction:: Execute() 
{
	CFigure *c = pManager->GetSelected();
	Output* pOut = pManager->GetOutput();
	
	if (c != NULL)
	{
		pManager->setclipboard(c->Copy());
    	pOut->PrintMessage("The Figure is copied to the clibboard.");	
	}
	else
	{
		pOut->PrintMessage("There is no selected figure.");
	}
	
}