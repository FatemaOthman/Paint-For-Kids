#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{

protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	static int NumOfFigures;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual bool Select(int x, int y) = 0;
	//void SetID(int i);
	int GetID();
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	virtual void ChngFillClr(color Fclr)=0;	//changes the figure's filling color
	float CalcTriArea(Point *v1, Point *v2, Point *v3);
	float Dist(Point p1, Point p2);
	virtual CFigure*Copy() = 0;
	color GetDrawColor();
	color GetFillColor();
	bool SameFillColor(CFigure *C);

	virtual bool SameDerivedClass(CFigure *c) = 0;
	string ColorToString(color c);
	virtual string FigureToString()=0;
	
	virtual CFigure* Paste(int x,int y) = 0;
	static void  Readcolor(ofstream&fout, color c);
	

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif