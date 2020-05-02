#include "BringToFrontAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
void BringToFrontAction::Execute()
{
	pManager->BringToFront();
	Output*pOut = pManager->GetOutput();
	if (pManager->GetSelected() != NULL)
	{
		pOut->PrintMessage("The Figure is sent to the Front :)");
	}
	else
		pOut->PrintMessage("There's no selected figure! ");
}
void BringToFrontAction::ReadActionParameters()
{
}


BringToFrontAction::BringToFrontAction(ApplicationManager *pApp):Action(pApp)
{
}


BringToFrontAction::~BringToFrontAction()
{
}
