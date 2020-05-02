#include"Action.h"
#include<fstream>
class SaveAction:public Action
{
	string filename;
public:
 SaveAction(ApplicationManager * ptr);
void ReadActionParameters();
void Execute();
};