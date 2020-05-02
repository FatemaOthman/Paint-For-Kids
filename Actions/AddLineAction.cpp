#include "AddLineAction.h"
#include "..\Figures\CLine.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddLineAction:: AddLineAction(ApplicationManager *pApp):Action(pApp)
{}


void AddLineAction:: ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at first point");
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Line: Click at second point");
	pIn->GetPointClicked(P2.x, P2.y);
	
	LineGfxInfo.isFilled = false;	
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	//LineGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

void AddLineAction:: Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CLine *L=new CLine(P1, P2, LineGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(L);
}
