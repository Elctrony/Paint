#ifndef ADD_SQR_ACTION_H
#define ADD_SQR_ACTION_H

#include "Action.h"
#include"../ApplicationManager.h"
#include"../Figures/CSquare.h"

//Add square Action class
class AddSqrAction : public Action
{
private:
	Point P1; //square center
	GfxInfo SqrGfxInfo;
	CSquare* figSqaure;
public:
	AddSqrAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add Square to the ApplicationManager
	virtual void Execute();

	virtual void Undo() {
		cout << "Undo Add Square" << endl;
		pManager->DeleteFigure(figSqaure);
	}

	virtual void Redo() {
		cout << "REDO add Sqaure" << endl;
		pManager->AddFigure(figSqaure);

	}
};

#endif

