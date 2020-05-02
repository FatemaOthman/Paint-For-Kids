#pragma once
#include"SaveAction.h"
#include <fstream>
#include"Action.h"
#include"../ApplicationManager.h"
#include<fstream>
SaveAction::SaveAction(ApplicationManager * ptr):Action(ptr)
{}
void SaveAction::ReadActionParameters()
{
	Output *pOut = pManager->GetOutput();
	Input *pIN = pManager->GetInput();
	pOut->PrintMessage("Please enter file name");
	filename=pIN->GetSrting(pOut);

}
void SaveAction::Execute()
{
	ReadActionParameters();
	ofstream fout(filename+".txt");
	pManager->SaveAll(fout);
	fout.close();
	Output *pOut = pManager->GetOutput();
	pOut->PrintMessage("The file is saved successfully:)");
}