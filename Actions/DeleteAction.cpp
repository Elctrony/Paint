#include "DeleteAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
DeleteAction::DeleteAction(ApplicationManager* pApp) :Action(pApp)
{}
void DeleteAction::Execute()
{
	ReadActionParameters();
	pManager->del();
	pManager->UpdateInterface();
}
void DeleteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearDrawArea();
	
}
