#ifndef MOVEACTION_H
#define MOVEACTION_H
#include"Action.h"
class MoveAction :public Action
{
private:
	Point P1;
public:
	MoveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~MoveAction();

};
#endif 
