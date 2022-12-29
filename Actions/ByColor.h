#ifndef BYCOLORACTION_H
#define BYCOLORACTION_H
#include"Action.h"
class ByColor :public Action
{
	int RightAns;
	int WrongAns;
	int tobepicked; //number of figures kid have to pick
	int pickedno;   //number of the right picks
	Point P;
public:
	ByColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	void print(bool b);

};
#endif 

