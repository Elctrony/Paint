#ifndef SELECTONE_H
#define SELECTONE_H
#include"Action.h"

class SelectOneAction :public Action
{
private:
	Point P1;
	bool IsSelected;
public:
	SelectOneAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};
#endif

