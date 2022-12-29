#ifndef CHANGEDRAWCOLOR_H
#define CHANGEDRAWCOLOR_H
#include"Action.h"

class ChangeDrawColor :public Action
{
public:
	ChangeDrawColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};
#endif
