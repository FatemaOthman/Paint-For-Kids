#pragma once
#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Point1;	
	Point Point2;
	Point Point3;
	CFigure*t;
public:
	CTriangle(Point , Point ,Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool Select(int x, int y);
	void PrintInfo(Output* pOut);
	CFigure*Copy();
	bool SameDerivedClass(CFigure *c);
	string FigureToString();
	void Save(ofstream &OutFile);
	void Load(ifstream &Infile);
	CFigure* Paste(int x,int y);
	virtual void ChngFillClr(color Fclr);
	~CTriangle();

};