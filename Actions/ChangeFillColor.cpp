#include "ChangeFillColor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

ChangeFillColor::ChangeFillColor(ApplicationManager* pApp) :Action(pApp)
{}

void ChangeFillColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select a filling color");
}
void ChangeFillColor::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	CFigure* FIG = pManager->GetSelectedFig();
	pOut->ClearStatusBar();
	
	if (FIG != NULL)
	{
		if (!FIG->isFilled())
		{
			ActionType ActType = pManager->GetUserAction();
			if (pManager->ccolor(ActType, UI.FillColor))
			{
				FIG->ChngFillClr(UI.FillColor);
				FIG->SetFill(true);
				FIG->SetSelected(0);
				pManager->SetSelectedFig(NULL);
			}
		}
		else
		{
			FIG->SetFill(false);
			FIG->SetSelected(0);
			pManager->SetSelectedFig(NULL);
			pManager->UpdateInterface();
		}

	}

}
