#include "BringToBackAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"



void BringToBackAction::Execute()
{
	pManager->BringToBack();
	Output*pOut = pManager->GetOutput();
	if (pManager->GetSelected() != NULL)
	{
		pOut->PrintMessage("The Figure is sent to the Back :)");
	}
	else
		pOut->PrintMessage("There's no selected figure! ");
}

void BringToBackAction::ReadActionParameters()
{}
BringToBackAction::BringToBackAction(ApplicationManager*pApp):Action(pApp)
{
}


BringToBackAction::~BringToBackAction()
{
}
