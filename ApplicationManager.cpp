#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions\AddCircleAction.h"
#include"Actions\AddLineAction.h"
#include"Actions\AddTriangleAction.h"
#include"Actions\SelectAction.h"
#include"Actions\DeleteAction.h"
#include"Actions\CopyAction.h"
#include"Actions\CutAction.h"
#include"Actions\PasteAction.h"
#include"Actions\SaveAction.h"
#include"Actions\LoadAction.h"
#include"Actions\PickByFigure.h"
#include"Actions\PickByColor.h"
#include"Actions\PickByFigAndColor.h"
#include"Actions\ChngDrawClr.h"
#include"Actions\ChngFillClrAction.h"
#include"Actions\BringToBackAction.h"
#include"Actions\BringToFrontAction.h"
#include"Actions\SwitchToDrawModeAction.h"
#include"Actions\SwitchtoPlayModeAction.h"
#include"Actions\ExitAction.h"
int CFigure::NumOfFigures = 0;
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	SelectedFig = NULL;
	Clipboard = NULL;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case DRAW_LINE:
		pAct = new AddLineAction(this);
		break;

	case DRAW_CIRC:
		pAct = new AddCircleAction(this);
		break;

	case DRAW_TRI:
		pAct = new AddTriangleAction(this);
		break;
	case SELECT:
		pAct = new SelectAction(this);
		break;
	case DELETe:
		pAct = new DeleteAction(this);
		break;
	case COPY:
		pAct = new CopyAction(this);
		break;
	case CUT:
		pAct = new CutAction(this);
		break;
	case PASTE:
		pAct = new PasteAction(this);
		break;
	case CHNG_DRAW_CLR:
		pAct = new ChngDrawClr(this);
		break;
	case CHNG_FILL_CLR:
		pAct = new ChngFillClrAction(this);
		break;
	case SAVE:
		pAct = new SaveAction(this);
		break;
	case LOAD:
		pAct = new LoadAction(this);
		break;
	case TOFRONT:
		pAct = new BringToFrontAction(this);
		break;
	case TOBACK:
		pAct = new BringToBackAction(this);
		break;
	case PLAY_BYFIGURE:
		pAct = new PickByFigure(this);
		break;
	case PLAY_BYCOLOR:
		pAct = new PickByColor(this);
		break;
	case PLAY_BYFIGUREANDCOLOR:
		pAct = new PickByFigAndColor(this);
		break;
	case TO_PLAY:
		pAct = new SwitchPlayModeAction(this);
		break;
	case TO_DRAW:
		pAct = new SwitchToDrawModeAction(this);
		break;
	case EXIT:
			pAct = new ExtAction(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount++] = pFig;
	
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	if (FigCount == 0)
		return NULL;
	for (int i = 0;i <FigCount;i++)
	{
		FigList[i]->SetSelected(false);
	}
	for (int i = FigCount - 1;i >= 0;i--) 
	{
		if (FigList[i]->Select(x, y))
		{
			if (FigList[i] == SelectedFig)
			{

				return NULL;
			}

			else
			{
				FigList[i]->SetSelected(true);
				return FigList[i];
			}
		}
	}
	if (SelectedFig != NULL)
	{
		SelectedFig->SetSelected(true);
		return SelectedFig;
	}
	

	return NULL;
}
void ApplicationManager::SetSelected(CFigure *C)
{
	SelectedFig = C;
}
void ApplicationManager::DeleteFig()
{
	if (SelectedFig == NULL)
		return;
	int c = 201;
	for (int i = 0;i < FigCount;i++)
	{
		if (FigList[i] == SelectedFig)
		{
			c = i;
			FigList[i] = NULL;
		}
	}

	for (int i = c;i <FigCount;i++)
	{
		FigList[i] = FigList[i + 1];
	}
	FigList[FigCount - 1] = NULL;
	FigCount--;
	

}
void ApplicationManager::setclipboard(CFigure *c)
{
	if (Clipboard != NULL)
		delete Clipboard;
	Clipboard = c;
}
CFigure* ApplicationManager::GetClipboard()
{
	return Clipboard;
}
int ApplicationManager::CountByFig(CFigure *C)
{
	int c = 0;
	for (int i = 0;i < FigCount;i++)
	{
		
		if (FigList[i]->SameDerivedClass(C))
		{	
			c++;
		}
	}
		
	return c;
}
int ApplicationManager::CountByColor(CFigure *C)
{
	int c = 0;
	for (int i = 0;i<FigCount;i++)
	{
		if (FigList[i]->SameFillColor(C))
			c++;
	}
	return c;

}
int ApplicationManager::CountByFigAndColor(CFigure *CF)
{
	int c = 0;
	for (int i = 0;i<FigCount;i++)
	{
		if (FigList[i]->SameFillColor(CF) &&FigList[i]->SameDerivedClass(CF))
			c++;
	}
	return c;
}
CFigure* ApplicationManager::RandomFig()
{
	if (FigCount == 0)
		return NULL;
	srand((unsigned)time(NULL));
	return FigList[0 + rand() % FigCount];
}

int ApplicationManager::GetFigCount()
{
	return FigCount;
}
void ApplicationManager::DeleteAllFigures()//FUNCTION TO DELETE ALL FIGURES BEFORE LOADING FILE 
{
	for (int i = 0;i<FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	SelectedFig = NULL;
	Clipboard = NULL;
	FigCount = 0;
	pOut->ClearDrawArea();
}

void ApplicationManager::SaveAll(ofstream &out)
{
	color c1 = pOut->getCrntDrawColor();
	color c = pOut->getCrntFillColor();
	CFigure::Readcolor(out, c1);
	out << "  ";
	if (UI.isfilled)
		CFigure::Readcolor(out, c);
	else
		out << "NON_FILLED";
	out << endl;
	out << FigCount << endl;
	for (int i = 0;i<FigCount;i++)
		FigList[i]->Save(out);

}

void ApplicationManager::BringToBack()
{
	if (SelectedFig == NULL)
		return;
	int c = 201;
	for (int i = 0;i < FigCount;i++)
	{
		if (FigList[i] == SelectedFig)
		{
			c = i;
			FigList[i] = NULL;
		}
	}
	
	for (int i = c;i >0;i--)
	{
		FigList[i] = FigList[i - 1];
	}
	FigList[0] = SelectedFig;

	
}
void  ApplicationManager::BringToFront()
{
	if(SelectedFig == NULL)
		return;
	int c = 201;
	for (int i = 0;i < FigCount;i++)
	{
		if (FigList[i] == SelectedFig)
		{
			c = i;
			FigList[i] = NULL;
		}
	}

	for (int i = c;i <FigCount;i++)
	{
		FigList[i] = FigList[i+1];
	}
	FigList[FigCount-1] = SelectedFig;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
CFigure*ApplicationManager:: GetSelected()
{
	return SelectedFig;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	if (Clipboard != NULL)
		delete Clipboard;
	delete pIn;
	delete pOut;
	
}
