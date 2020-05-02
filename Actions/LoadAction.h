#include<string>
#include"Action.h"

class LoadAction:public Action
{
	string Filename;
    public:
LoadAction(ApplicationManager * ptr,string F=" ");
color StringToColor(string s);
void ReadActionParameters();

void Execute();
};