#include "DeleteAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"



void DeleteAction::ReadActionParameters()
{
}
void DeleteAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure*c = pManager->GetSelected();
	if (c != NULL)
	{
		pManager->DeleteFig();
		pManager->SetSelected(NULL);

		pOut->PrintMessage("The Figure is Deleted :) ");
	}
	else
		pOut->PrintMessage("There is no selcted Figure");
}
DeleteAction::DeleteAction(ApplicationManager *pApp):Action(pApp)
{
}


DeleteAction::~DeleteAction()
{
}
