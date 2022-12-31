#ifndef UNDOACTION_H
#define UNDOACTION_H

#include"Action.h"
#include "../ApplicationManager.h"
class UndoAction : public Action {
public:
	UndoAction(ApplicationManager* pApp) :Action(pApp) {

	}
	void ReadActionParameters() {
		pManager->GetOutput()->PrintMessage("Undo Last Action");
	}
	void Execute(bool mode=0) {
		ReadActionParameters();
		pManager->UndoLastAction();
		pManager->GetLastAction()->Undo();

		
	}
	
};
#endif

