#ifndef ADD_HEXA_ACTION_H
#define ADD_HEXA_ACTION_H

#include "Action.h"

//Add Hexagon Action class
class AddHexaAction : public Action
{
private:
	Point P1; //Hexagon Center
	GfxInfo HexaGfxInfo;
public:
	AddHexaAction(ApplicationManager* pApp);

	//Reads Hexagon parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif
