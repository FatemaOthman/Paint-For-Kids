#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	float Length;
	float Width;
	CFigure*r;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
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
	~CRectangle();

};


#endif