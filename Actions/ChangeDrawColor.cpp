#include "ChangeDrawColor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

ChangeDrawColor::ChangeDrawColor(ApplicationManager* pApp) :Action(pApp)
{}

void ChangeDrawColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select a drawing color");
}
void ChangeDrawColor::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	CFigure* FIG = pManager->GetSelectedFig();
	ActionType ActType = pManager->GetUserAction();
	pOut->ClearStatusBar();

	if (FIG != NULL)
	{
		if (pManager->ccolor(ActType, UI.DrawColor))
		{
			FIG->ChngDrawClr(UI.DrawColor);
			FIG->SetSelected(0);
			pManager->SetSelectedFig(NULL);
		}
	}
}