#include"Action.h"
#include "../ApplicationManager.h"
class UndoAction : public Action {
public:
	UndoAction(ApplicationManager* pApp) :Action(pApp) {

	}
	void ReadActionParameters() {
		pManager->GetOutput()->PrintMessage("Undo Last Action");
	}
	void Execute() {
		ReadActionParameters();
		pManager->UndoLastAction();
	}
};
#pragma once
