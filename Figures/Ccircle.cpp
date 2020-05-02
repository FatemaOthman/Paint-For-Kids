#include "Ccircle.h"
#include<fstream>

Ccircle::Ccircle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	point1 = P1;
	point2 = P2;
	Radius = Dist(P1, P2);
	NumOfFigures++;
	ID = NumOfFigures;
	c = NULL;
}
Ccircle::~Ccircle()
{
	if (c != NULL)
		delete c;
}

void Ccircle::Draw(Output* pOut) const
{

	pOut->DrawCircle(point1, point2, FigGfxInfo, Selected);
}
bool Ccircle::Select(int x, int y)
{
	if (Selected)
		return false;
	Point pt;
	pt.x = x;
	pt.y = y;
	float RPoint = Dist(pt, point1);
	float Radius = Dist(point1, point2);
	if (RPoint > Radius)
		return false;
	Selected = true;
	return true;

}
void Ccircle::PrintInfo(Output* pOut)
{


	string x = "The Figure is: Circle. ID: ";
	x += to_string(GetID());
	x += ". The Center at:(";
	x += to_string(point1.x);
	x += ",";x += to_string(point1.y);x += "), Radius =";x += to_string((int)Radius);
	pOut->PrintMessage(x);
}
CFigure*Ccircle::Copy()
{
	CFigure*c = new Ccircle(point1, point2, FigGfxInfo);
	return c;
}
bool Ccircle::SameDerivedClass(CFigure *c)
{
	return dynamic_cast<Ccircle*>(c);

}
string Ccircle::FigureToString()
{
	return "Circle";
}

CFigure* Ccircle::Paste(int x,int y)
{
	CFigure* Circle = Copy();
	Ccircle *c = (Ccircle*)Circle;
	c->point1.x = x;
	c->point1.y = y;
	c->point2.x = Radius + c->point1.x;
	c->point2.y = c->point1.y;
	//Ccircle *c=Copy()
	//Ccircle*cir = dynamic_cast<Ccircle*>(c);
	//Pin->GetPointClicked(cir->point1.x, cir->point1.y);
	//cir->point2.y = (int)Radius + cir->point1.y;
	//cir->Radius = Radius;
	//cir->point2.x = cir->point1.x;
	return c;
}

void Ccircle::Save(ofstream &OutFile) //Save the figure parameters to the file
{
	OutFile << "CIRCLE\t" << "  ";
	OutFile << ID << "\t";
	OutFile << point1.x << "   " << point1.y << "  " << point2.x << "  " << point2.y << "   " << Radius << "   ";
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
void Ccircle::Load(ifstream &Infile)
{
	int id, x1, y1, x2, y2;
	float r;
	Infile >> id;
	ID = id;
	Infile >> x1 >> y1 >> x2 >> y2 >> r;
	point1.x = x1;
	point1.y = y1;
	point2.x = x2;
	point2.y = y2;
	Radius = r;
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
void Ccircle::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}