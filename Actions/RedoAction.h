#include"Action.h"
#include"../ApplicationManager.h"

class RedoAction : public Action {
public:
	RedoAction(ApplicationManager* pApp) :Action(pApp) {

	}
	void ReadActionParameters() {
		pManager->GetOutput()->PrintMessage("Redo Last Action");
	}

	void Execute(bool mode=0) {
		pManager->RedoLastAction();
		ReadActionParameters();
	}
};
#pragma once
