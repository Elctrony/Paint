#include "AddHexaAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexaAction::AddHexaAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at center");

	//Read center and store in point P1
	do
	{
		pIn->GetPointClicked(P1.x, P1.y);
		if (P1.y - 25 * sqrt(3) < UI.ToolBarHeight || (P1.y + 25 * sqrt(3) > UI.height - UI.StatusBarHeight))
			pOut->PrintMessage("invalid point click again");

	} while (P1.y-25*sqrt(3) < UI.ToolBarHeight|| (P1.y+25 * sqrt(3) > UI.height-UI.StatusBarHeight));//check if point is out of boundaries

	HexaGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexaAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a Hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(P1, HexaGfxInfo);

	//Add the hexagon to the list of figures
	pManager->AddFigure(H);
}
