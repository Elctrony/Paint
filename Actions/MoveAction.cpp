#include "MoveAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

MoveAction::MoveAction(ApplicationManager* pApp) :Action(pApp)
{}

void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Move selected figure: Click at any Point");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
	pOut->ClearDrawArea();

}
void MoveAction::Execute()
{
	ReadActionParameters();
	CFigure* MFIG=pManager->GetSelectedFig();
	MFIG->shift(P1);
}
