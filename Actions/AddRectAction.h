#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H

#include "Action.h"
#include<iostream>
#include"../Figures/CRectangle.h"
#include"../ApplicationManager.h"
//Add Rectangle Action class
class AddRectAction: public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
	CRectangle* figRectangle;
public:
	AddRectAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute();

	virtual void Undo() {
		cout << "Undo Add Rect" << endl;
		pManager->DeleteFigure(figRectangle);
	}

	virtual void Redo() {
		cout << "REDO add Reac" << endl;
		pManager->AddFigure(figRectangle);
	}
	
	
};

#endif