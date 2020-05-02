#include "PickByColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"SelectAction.h"
#include"CopyAction.h"
#include"DeleteAction.h"
#include"LoadAction.h"



void PickByColor::ReadActionParameters()
{
}
void PickByColor::Execute()
{
	Action* pAct;
	pAct = new LoadAction(pManager, "Original Figurelist");
	pAct->Execute();
	pManager->UpdateInterface();
	delete pAct;
	
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	CFigure *F = pManager->RandomFig();
	pManager->SetSelected(F);
	pAct = new CopyAction(pManager);
	pAct->Execute();
	delete pAct;
	F = pManager->GetClipboard();
	int c = pManager->CountByColor(F);
	if (c == 0)
		return;
	pManager->SetSelected(NULL);
	int CorrectPicks = 0;
	int IncorrectPicks = 0;
	string s;
	s = "Pick All ";
	s += F->ColorToString(F->GetFillColor());
	s += " Figures";
	pOut->PrintMessage(s);
	Point CheckPoint;
	CheckPoint.x = 252;
	CheckPoint.y = 51;
	while (c != 0 && (CheckPoint.y>50 || CheckPoint.x>251))
	{

		pAct = new SelectAction(pManager, true);
		pAct->Execute();
		SelectAction* p = (SelectAction*)pAct;
		CheckPoint = p->P;
		delete pAct;
		if ((pManager->GetSelected() != NULL))
		{
			if (pManager->GetSelected()->SameFillColor(F))
			{
				c--;
				CorrectPicks++;
			}
			else
				IncorrectPicks++;
			pAct = new DeleteAction(pManager);
			pAct->Execute();
			delete pAct;
		}
		pManager->SetSelected(NULL);
		pManager->UpdateInterface();
		s = "Number of Corrcect Picks= ";
		s += to_string(CorrectPicks);
		s += "| Number Of Incorrect Picks =";
		s += to_string(IncorrectPicks);
		pOut->PrintMessage(s);

	}
	if (c == 0)
	{
		pAct = new LoadAction(pManager, "YouWon");
		pAct->Execute();
		delete pAct;
		string n = "You Won! ";
		n += s;
		pOut->PrintMessage(n);
	}
	else if (CheckPoint.y>50 && CheckPoint.x>251)
	{
		pOut->ClearStatusBar();
		pManager->GetUserAction();
	}
}
PickByColor::PickByColor(ApplicationManager*pApp):Action(pApp)
{
	
}


PickByColor::~PickByColor()
{
}
