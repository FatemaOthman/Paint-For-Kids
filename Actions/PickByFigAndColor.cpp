#include "PickByFigAndColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include"SelectAction.h"
#include"DeleteAction.h"
#include"CopyAction.h"
#include"LoadAction.h"



void PickByFigAndColor::ReadActionParameters()
{}
void PickByFigAndColor::Execute()
{
/*	ifstream fin("Original Figurelist.txt");
	if (fin.is_open())
	{
		pManager->DeleteAllFigures();
		string fig1;
		fin >> fig1;
		string fig2;//uncomment this(fig2 is current fill color)
		fin >> fig2;
		int m;
		fin >> m;
		Point p1;
		p1.x = 0;
		p1.y = 0;
		Point p2;
		p2.x = 0;
		p2.y = 0;
		Point p3;
		p3.x = 0;
		p3.y = 0;
		GfxInfo GF;
		GF.isFilled = false;
		GF.BorderWdth = 1;
		for (int i = 0;i<m;i++)
		{
			string fig;
			fin >> fig;
			if (fig == "RECTANGLE")
			{
				CRectangle*ptr = new CRectangle(p1, p2, GF);
				ptr->Load(fin);
				pManager->AddFigure(ptr);
			}
			if (fig == "CIRCLE")
			{
				Ccircle*ptr = new Ccircle(p1, p2, GF);
				ptr->Load(fin);
				pManager->AddFigure(ptr);
			}
			if (fig == "TRIANGLE")
			{
				CTriangle*ptr = new CTriangle(p1, p2, p3, GF);
				ptr->Load(fin);
				pManager->AddFigure(ptr);
			}
			if (fig == "LINE")
			{
				CLine*ptr = new CLine(p1, p2, GF);
				ptr->Load(fin);
				pManager->AddFigure(ptr);
			}
		}
	}*/
	
	Action* pAct;
	pAct = new LoadAction(pManager, "Original Figurelist");
	pAct->Execute();
	delete pAct;
	pManager->UpdateInterface();
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	CFigure *F = pManager->RandomFig();
	pManager->SetSelected(F);
	pAct = new CopyAction(pManager);
	pAct->Execute();
	delete pAct;
	F = pManager->GetClipboard();
	int c = pManager->CountByFigAndColor(F);
	if (c == 0)
		return;
	pManager->SetSelected(NULL);
	int CorrectPicks = 0;
	int IncorrectPicks = 0;
	string s;
	s = "Pick All ";
	s += F->ColorToString(F->GetFillColor());
	s += " ";
	s += F->FigureToString();
	s += "s";
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
			if (pManager->GetSelected()->SameDerivedClass(F)&&pManager->GetSelected()->SameFillColor(F))
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
		/*ifstream fin("YouWon.txt");
		if (fin.is_open())
		{
			pManager->DeleteAllFigures();
			string fig1;
			fin >> fig1;
			string fig2;//uncomment this(fig2 is current fill color)
			fin >> fig2;
			int m;
			fin >> m;
			Point p1;
			p1.x = 0;
			p1.y = 0;
			Point p2;
			p2.x = 0;
			p2.y = 0;
			Point p3;
			p3.x = 0;
			p3.y = 0;
			GfxInfo GF;
			GF.isFilled = false;
			GF.BorderWdth = 1;
			for (int i = 0;i<m;i++)
			{
				string fig;
				fin >> fig;
				if (fig == "RECTANGLE")
				{
					CRectangle*ptr = new CRectangle(p1, p2, GF);
					ptr->Load(fin);
					pManager->AddFigure(ptr);
				}
				if (fig == "CIRCLE")
				{
					Ccircle*ptr = new Ccircle(p1, p2, GF);
					ptr->Load(fin);
					pManager->AddFigure(ptr);
				}
				if (fig == "TRIANGLE")
				{
					CTriangle*ptr = new CTriangle(p1, p2, p3, GF);
					ptr->Load(fin);
					pManager->AddFigure(ptr);
				}
				if (fig == "LINE")
				{
					CLine*ptr = new CLine(p1, p2, GF);
					ptr->Load(fin);
					pManager->AddFigure(ptr);
				}
			}
		}*/
		pManager->UpdateInterface();
		string n = "You Won! ";
		n += s;
		pOut->PrintMessage(n);
	}
	else if (CheckPoint.y<=50 && CheckPoint.x<=251)
	{
		pOut->ClearStatusBar();
		pManager->GetUserAction();
	}
}

PickByFigAndColor::PickByFigAndColor(ApplicationManager*pApp):Action(pApp)

{
}


PickByFigAndColor::~PickByFigAndColor()
{
}
