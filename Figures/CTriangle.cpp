#include "CTriangle.h"
#include<fstream>
CTriangle::CTriangle(Point P1, Point P2 ,Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
	Point3 = P3;
	NumOfFigures++;
	ID = NumOfFigures;
	t = NULL;
}

CTriangle::~CTriangle()
{
	if (t != NULL)
		delete t;
}
	

void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTriangle(Point1, Point2, Point3, FigGfxInfo, Selected);
}
bool CTriangle::Select(int x, int y)
{
	if (Selected)
		return false;
	Point pt;
	pt.x = x;
	pt.y = y;
	float TotalArea = CalcTriArea(&Point1, &Point2, &Point3);
	float Area1 = CalcTriArea(&pt, &Point3, &Point2);
	float Area2 = CalcTriArea(&pt, &Point1, &Point3);
	float Area3 = CalcTriArea(&pt, &Point1, &Point2);

	if ((Area1 + Area2 + Area3) == TotalArea)
		return true;
	else
		
		return false;
}
void CTriangle::PrintInfo(Output* pOut)
{
	string x = "The Figure is: Triangle. ID: ";

	x += to_string(GetID());
	x += ". Point 1 at:(";
	x += to_string(Point1.x);
	x += ",";x += to_string(Point1.y);x += "), Point2 at: (";x += to_string(Point2.x);x += ",";x += to_string(Point2.y);
	x += ") Point3 at: (";x += to_string(Point3.x);x += ",";x += to_string(Point3.y);x += ").";
	pOut->PrintMessage(x);
}
CFigure*CTriangle::Copy()
{
	CFigure*c = new CTriangle(Point1, Point2, Point3, FigGfxInfo);
	return c;
}
bool CTriangle::SameDerivedClass(CFigure *c)
{
	return dynamic_cast<CTriangle*>(c);

}
string CTriangle::FigureToString()
{
	return "Triangle";
}
void CTriangle::Save(ofstream &OutFile) //Save the figure parameters to the file
{
	OutFile << "TRIANGLE\t" << "   ";
	OutFile << ID << "\t";
	OutFile << Point1.x << "   " << Point1.y << "  " << Point2.x << "  " << Point2.y << "   " << Point3.x << "   " << Point3.y << "   ";
	color c = FigGfxInfo.DrawClr;
	color c2 = FigGfxInfo.FillClr;
	Readcolor(OutFile, c);
	OutFile << "  ";
	color c1 = GetFillColor();
	if (!FigGfxInfo.isFilled)
		OutFile << "NO_FILL";
	else
		Readcolor(OutFile, c2);
	OutFile << endl;
}
void CTriangle::Load(ifstream&Infile)
{
	int id, x1, y1, x2, y2, x3, y3;
	Infile >> id;
	ID = id;
	Infile >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	Point1.x = x1;
	Point1.y = y1;
	Point2.x = x2;
	Point2.y = y2;
	Point3.x = x3;
	Point3.y = y3;
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
	string Fill;
	Infile >> Fill;
	if (Fill == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
	}
	else
	{
		FigGfxInfo.isFilled = true;
		if (Fill == "BLUE")
		{
			FigGfxInfo.FillClr = BLUE;
		}
		if (Fill == "BLACK")
		{
			FigGfxInfo.FillClr = BLACK;
		}
		if (Fill == "WHITE")
		{
			FigGfxInfo.FillClr = WHITE;
		}
		if (Fill == "GREEN")
		{
			FigGfxInfo.FillClr = GREEN;
		}
		if (Fill == "RED")
		{
			FigGfxInfo.FillClr = RED;
		}
	}

}
CFigure* CTriangle::Paste(int x,int y)
{
	CFigure*c = Copy();
	CTriangle*tri = (CTriangle*)c; 
	
	tri->Point1.x = x;
	tri->Point1.y = y;
	
	tri->Point2.x = (tri->Point1.x - Point1.x) + Point2.x;
	tri->Point2.y = (tri->Point1.y - Point1.y) + Point2.y;
	tri->Point3.x = (tri->Point1.x - Point1.x) + Point3.x;
	tri->Point3.y = (tri->Point1.y - Point1.y) + Point3.y;
	return tri;
}
void CTriangle::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}