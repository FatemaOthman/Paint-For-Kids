#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"SwitchToDrawModeAction.h"
#include"LoadAction.h"

SwitchToDrawModeAction::SwitchToDrawModeAction(ApplicationManager *pApp):Action(pApp)
{
}

void SwitchToDrawModeAction::ReadActionParameters()
{

}
void SwitchToDrawModeAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Action: Switch to Draw Mode");
	pOut->CreateDrawToolBar();
	Action* pAct;
	pAct = new LoadAction(pManager, "Original Figurelist");
	pAct->Execute();
	delete pAct;
	

}