#ifndef BYTYPEANDCOLORACTION_H
#define BYTYPEANDCOLORACTION_H
#include"Action.h"
class ByTypeAndColor :public Action
{
	int RightAns;
	int WrongAns;
	int tobepicked;
	int pickedno;
	Point P;
public:
	ByTypeAndColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	void print(bool b);

};
#endif 
