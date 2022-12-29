#ifndef CHANGEFILLCOLOR_H
#define CHANGEFILLCOLOR_H
#include"Action.h"

class ChangeFillColor :public Action
{
public:
	ChangeFillColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};
#endif


