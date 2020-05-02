#include "AddCircleAction.h"
#include "..\Figures\Ccircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircleAction:: AddCircleAction(ApplicationManager *pApp):Action(pApp)
{}

void AddCircleAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at first point");

	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at second point");

	pIn->GetPointClicked(P2.x, P2.y);
//	if(!CFigure::)
	CircleGfxInfo.isFilled = UI.isfilled;

	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}
	
void AddCircleAction::Execute() 
{
	ReadActionParameters();
	
	Ccircle *C=new Ccircle(P1, P2, CircleGfxInfo);

	pManager->AddFigure(C);
}
