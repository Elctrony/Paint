#ifndef ADD_HEXA_ACTION_H
#define ADD_HEXA_ACTION_H

#include "Action.h"
#include "../Figures/CHexagon.h"
#include "../ApplicationManager.h"
//Add Hexagon Action class
class AddHexaAction : public Action
{
private:
	Point P1; //Hexagon Center
	GfxInfo HexaGfxInfo;
	CHexagon* figHexagon;
public:
	AddHexaAction(ApplicationManager* pApp);

	//Reads Hexagon parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	virtual void Undo() {
		cout << "Undo Add Hexagon" << endl;
		pManager->DeleteFigure(figHexagon);
	}

	virtual void Redo() {
		cout << "REDO add Hexagon" << endl;
		pManager->AddFigure(figHexagon);

	}
};

#endif
