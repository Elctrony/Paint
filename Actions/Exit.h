#ifndef EXITACTION_H
#define EXITACTION_H
#include"Action.h"
class Exit :public Action
{
public:
	Exit(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};
#endif 

