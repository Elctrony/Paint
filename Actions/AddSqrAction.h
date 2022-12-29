#ifndef ADD_SQR_ACTION_H
#define ADD_SQR_ACTION_H

#include "Action.h"

//Add square Action class
class AddSqrAction : public Action
{
private:
	Point P1; //square center
	GfxInfo SqrGfxInfo;
public:
	AddSqrAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif

