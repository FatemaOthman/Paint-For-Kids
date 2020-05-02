#include "CFigure.h"
#include<iostream>
#include<fstream>

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo= FigureGfxInfo;	//Default status is non-filled.

	Selected = false;
	ID=++ID;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }


float CFigure::CalcTriArea(Point *v1, Point *v2, Point *v3)
{
	float det = 0.0f;
	det = (v2->x*v3->y - v3->x*v2->y) - (v1->x*v3->y - v1->y*v3->x) + (v1->x*v2->y - v1->y*v2->x);
	det = abs(det);

	
	return (det / 2.0f);
}
float CFigure::Dist(Point p1, Point p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int CFigure::GetID()
{
	return ID;
}

string CFigure::ColorToString(color c)
{
	if (!FigGfxInfo.isFilled)
		return "Non Filled";
	if (c==RED)
		return "Red";
	else if (c==GREEN)
		return "Green";
	else if (c==BLUE)
		return "Blue";
	else if (c==WHITE)
		return "White";
	else if (c==BLACK)
		return "Black";
}
color CFigure::GetDrawColor()
{
	return FigGfxInfo.DrawClr;
}
color CFigure::GetFillColor()
{
	if (FigGfxInfo.isFilled)
		return FigGfxInfo.FillClr;

}
void CFigure::Readcolor(ofstream&fout, color c)
{

	if (c==BLUE)
		fout << "BLUE";
	if (c==BLACK)
		fout << "BLACK";
	if (c==WHITE)
		fout << "WHITE";
	if (c==GREEN)
		fout << "GREEN";
	if (c==RED)
		fout << "RED";
}
bool CFigure::SameFillColor(CFigure *C)
{
	if (FigGfxInfo.isFilled != C->FigGfxInfo.isFilled)
		return false;
	return FigGfxInfo.FillClr == C->FigGfxInfo.FillClr;
		
}