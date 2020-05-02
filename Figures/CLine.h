#pragma once
#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point point1;	
	Point point2;
	float Length;
	CFigure*l;
public:
	CLine(Point , Point, GfxInfo FigureGfxInfo );
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
	~CLine();
};
