#ifndef CLEARALLACTION_H
#define CLEARALLACTION_H
#include"Action.h"
class ClearAll :public Action
{
public:
	ClearAll(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};
#endif 

