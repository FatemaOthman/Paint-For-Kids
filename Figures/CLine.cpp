#include "CLine.h"
#include<fstream>

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	NumOfFigures++;
	point1 = P1;
	point2 = P2;
	Length = Dist(point1, point2);
	ID = NumOfFigures;
	l = NULL;
}

CLine::~CLine()
{
	if (l != NULL)
		delete l;
}
	

void CLine::Draw(Output* pOut) const
{	
	pOut->DrawLine(point1, point2, FigGfxInfo, Selected);
}
bool CLine::Select(int x, int y)
{

	if (Selected)
		return false;

	Point pt;
	pt.x = x;
	pt.y = y;
	float DistL = Dist(point1, point2);
	float Dist1 = Dist(pt, point1);
	float Dist2 = Dist(pt, point2);
	float DistL2 = (Dist1 + Dist2)-DistL;
	
	while (DistL2 >= 0 && DistL2 <= 0.5)
	{
		if (DistL + DistL2 == Dist1 + Dist2)
			return true;
	}
	return false;


}
void CLine::PrintInfo(Output* pOut)
{
	string x = "The Figure is: Line. ID: ";

	x += to_string(GetID());
	x += ". Start Point at:(";
	x += to_string(point1.x);
	x += ",";x += to_string(point1.y);x += "), End Point at: (";x += to_string(point2.x);x += ",";x += to_string(point2.y);
	x += "). Length =: ";x += to_string((int)Length);
	pOut->PrintMessage(x);
}
CFigure*CLine::Copy()
{
	CLine*c = new CLine(point1, point2, FigGfxInfo);
	return c;
}
bool CLine::SameDerivedClass(CFigure *c)
{
	return dynamic_cast<CLine*>(c);

}
string CLine::FigureToString()
{
	return "Line";
}
CFigure* CLine::Paste(int x,int y)
{
	CFigure*line = Copy();
	
	CLine*linee = (CLine*)line;
	linee->point1.x = x;
	linee->point1.y = y;
	int X = linee->point1.x - point1.x;
	int Y = linee->point1.y - point1.y;
	linee->point2.x = point2.x + (linee->point1.x - point1.x);
	linee->point2.y = point2.y + (linee->point1.y - point1.y);
	return linee;
}
void CLine::Save(ofstream &OutFile) //Save the figure parameters to the file
{
	OutFile << "LINE\t" << "  ";
	OutFile << ID << "\t";
	OutFile << point1.x << "   " << point1.y << "  " << point2.x << "  " << point2.y << "   ";
	color c = FigGfxInfo.DrawClr;
	Readcolor(OutFile, c);
	OutFile << endl;

}
void CLine::Load(ifstream&Infile)
{
	
	int id, x1, y1, x2, y2;
	Infile >> id;
	ID = id;
	Infile >> x1 >> y1 >> x2 >> y2;
	point1.x = x1;
	point1.y = y1;
	point2.x = x2;
	point2.y = y2;
	string colo;
	Infile >> colo;
	if (colo == "BLUE")
	{
		FigGfxInfo.DrawClr = BLUE;
	}
	if (colo == "BLACK")
	{
		FigGfxInfo.DrawClr = BLACK;
	}
	if (colo == "WHITE")
	{
		FigGfxInfo.DrawClr = WHITE;
	}
	if (colo == "GREEN")
	{
		FigGfxInfo.DrawClr = GREEN;
	}
	if (colo == "RED")
	{
		FigGfxInfo.DrawClr = RED;
	}

}
void CLine::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = false;
	FigGfxInfo.FillClr = Fclr;
}