#include "SelectOneAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

SelectOneAction::SelectOneAction(ApplicationManager* pApp) :Action(pApp)
{}

void SelectOneAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select a figure: Click at any figure");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();

}
void SelectOneAction::Execute()
{
	ReadActionParameters();
	CFigure* T=pManager->GetFigure(P1.x, P1.y);
	if (T != NULL&&(T->IsSelected() == 0))
	{
		T->SetSelected(1);
	}
	else if (T != NULL && (T->IsSelected()==1))
	{
		T->SetSelected(0);
	}

}
