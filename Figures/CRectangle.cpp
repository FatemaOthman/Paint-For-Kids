#include "CRectangle.h"
#include<fstream>


CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Width = abs(Corner1.x - Corner2.x);
	Length = abs(Corner1.y - Corner2.y);
	NumOfFigures++;
	ID = NumOfFigures;
	r = NULL;
}

CRectangle::~CRectangle()
{
	if (r != NULL)
		delete r;
}


void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::Select(int x, int y)
{
	if (Selected)
		return false;
	Point pt;
	pt.x = x;pt.y = y;
	Point p3,p4;
	p4.x = Corner1.x;p4.y = Corner2.y;
	p3.x = Corner2.x;p3.y = Corner1.y;
	float Area = abs((Corner1.x - Corner2.x)*(Corner1.y - Corner2.y));
	float Area1 = CalcTriArea(&pt, &Corner1, &p3);
	float Area2= CalcTriArea(&pt, &Corner1, &p4);
	float Area3= CalcTriArea(&pt, &Corner2, &p3);
	float Area4= CalcTriArea(&pt, &Corner2, &p4);
	if (Area1+Area2+Area3+Area4==Area)
		return true;
	return false;
	

}
void CRectangle::PrintInfo(Output* pOut)
{
	string x = "The Figure is: Rectangle. ID: ";
	x+= to_string(GetID());
	x += ". Corner 1 at:(";
	x += to_string(Corner1.x);
	x += ",";x += to_string(Corner1.y);x += "), Corner 2 at: (";x += to_string(Corner2.x);x += ",";x += to_string(Corner2.y);
	x += "). Length =: ";x += to_string((int)Length);x += ". Width =";x += to_string((int)Width);x += ".";
	pOut->PrintMessage(x);
}
CFigure*CRectangle::Copy()
{
	CFigure*c = new CRectangle(Corner1, Corner2, FigGfxInfo);
	return c;
}
bool CRectangle::SameDerivedClass(CFigure *c)
{
	return dynamic_cast<CRectangle*>(c);
}
string CRectangle::FigureToString()
{
	return "Rectangle";
}
CFigure* CRectangle::Paste(int x,int y)
{

	CFigure *c = Copy();
	CRectangle*rect = (CRectangle*)c;//dynamic_cast<CRectangle*>(c);
	
	rect->Corner1.x = x;
	rect->Corner1.y = y;
	rect->Corner2.x = rect->Corner1.x + Width;
	rect->Corner2.y = rect->Corner1.y + Length;
	rect->Length = Length;
	rect->Width = Width;
	return rect;
}
void CRectangle::Save(ofstream &OutFile) //Save the figure parameters to the file
{
	OutFile << "RECTANGLE\t" << "   ";
	OutFile << ID << "\t";
	OutFile << Corner1.x << "   " << Corner1.y << "  " << Corner2.x << "  " << Corner2.y << "   ";
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
void CRectangle::Load(ifstream&Infile)
{
	int id, x1, y1, x2, y2;
	Infile >> id;
	ID = id;
	Infile >> x1 >> y1 >> x2 >> y2;
	Corner1.x = x1;
	Corner1.y = y1;
	Corner2.x = x2;
	Corner2.y = y2;
	Width = abs(Corner1.x - Corner2.x);
	Length = abs(Corner1.y - Corner2.y);
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
void CRectangle::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}