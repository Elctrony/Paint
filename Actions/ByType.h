#ifndef BYTYPEACTION_H
#define BYTYPEACTION_H
#include"Action.h"
class ByType :public Action
{
	int RightAns;
	int WrongAns;
	int tobepicked;
	int pickedno;
	Point P;
public:
	ByType(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	void print(bool b);

};
#endif 


