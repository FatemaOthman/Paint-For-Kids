#include"LoadAction.h"
#include"../ApplicationManager.h"
#include<fstream>
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\Ccircle.h"
#include "..\defs.h"


LoadAction::LoadAction(ApplicationManager * ptr,string F):Action(ptr)
{
	Filename = F;
}
void LoadAction::ReadActionParameters()
{
    Output *pOut = pManager->GetOutput();
	pOut->PrintMessage("Please enter file name");
	Input *pIN = pManager->GetInput();
	Filename=pIN->GetSrting(pOut);
}
void LoadAction:: Execute()
{
	if (Filename != "YouWon"&& Filename != "Original Figurelist")
	{
		ReadActionParameters();
	}
	Output *pOut = pManager->GetOutput();
	ifstream fin(Filename+".txt");
	
	if (fin.is_open())
	{
		pManager->DeleteAllFigures();
		string DrawColor;
		fin>>DrawColor;

		string FillColor;
		fin>>FillColor;
		int m;
		fin>>m;
		Point p1;
		p1.x=0;
		p1.y=0;
		Point p2;
		p2.x=0;
		p2.y=0;
		Point p3;
		p3.x=0;
		p3.y=0;
		GfxInfo GF;
		if(FillColor=="NON_FILLED")
		UI.isfilled=true;
		else
		{
			UI.isfilled = true;
			pOut->SetCrntFillColor(StringToColor(FillColor));
		}
		pOut->SetCrntDrawColor(StringToColor(DrawColor));
		GF.BorderWdth=1;
		for(int i=0;i<m;i++)
		{
			string fig;
			fin>>fig;
			if(fig=="RECTANGLE")
		{
			CRectangle*ptr=new CRectangle(p1,p2,GF);
			ptr->Load(fin);
			pManager->AddFigure(ptr);
		}
		if(fig=="CIRCLE")
		{   Ccircle*ptr=new Ccircle(p1,p2,GF);
			ptr->Load(fin);
			pManager->AddFigure(ptr);
		}
		if(fig=="TRIANGLE")
		{
			CTriangle*ptr= new CTriangle(p1,p2,p3,GF);
			ptr->Load(fin);
			pManager->AddFigure(ptr);
		}
		if(fig=="LINE")
		{
			GF.isFilled = false;
			CLine*ptr=new CLine(p1,p2,GF);
			ptr->Load(fin);
			pManager->AddFigure(ptr);
		}
	}
	}
	else
	{
    	pOut->PrintMessage("Sorry!!the file doesn't exist :(");
	}
	
	
}
color LoadAction::StringToColor(string s)
{
	Output *pOut = pManager->GetOutput();
	if (s == "BLUE")
		return BLUE;
	if (s == "BLACK")
		return BLACK;
	if (s == "RED")
		return RED;
	if (s == "WHITE")
		return WHITE;
	if (s == "GREEN")
		return GREEN;
}