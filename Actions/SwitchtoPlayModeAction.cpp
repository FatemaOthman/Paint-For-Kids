#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"SwitchtoPlayModeAction.h"
#include"SaveAction.h"

SwitchPlayModeAction:: SwitchPlayModeAction(ApplicationManager *pApp):Action(pApp)
{
}

void SwitchPlayModeAction::ReadActionParameters()
{

}
void SwitchPlayModeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Clicked on pikachue!Let's go Catch 'Em All!Switch to Play Mode, ");
	pOut->CreatePlayToolBar();
	
	ofstream fout("Original Figurelist.txt");
	pManager->SaveAll(fout);
}