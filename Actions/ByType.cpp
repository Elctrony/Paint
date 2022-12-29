#include "ByType.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

#include"..\Figures\CCircle.h"
#include"..\Figures\CHexagon.h"
#include"..\Figures\CSquare.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\CTriangle.h"


ByType::ByType(ApplicationManager* pApp) :Action(pApp)
{}
void ByType::Execute()
{
	ReadActionParameters();
	pManager->unhideall();
	pManager->UpdateInterface();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->cantype())
	{
		CFigure* rand = pManager->getrandfig();
		tobepicked = pManager->gettypeno(rand);
		switch (rand->gettype())
		{
		case rectangle:
			pOut->PrintMessage("Pick all rectangles");
			break;
		case square:
			pOut->PrintMessage("Pick all squares");
			break;
		case circle:
			pOut->PrintMessage("Pick all circles");
			break;
		case triangle:
			pOut->PrintMessage("Pick all triangles");
			break;
		case hexagon:
			pOut->PrintMessage("Pick all hexagons");
			break;
		}

		while (pickedno != tobepicked)
		{
			pIn->GetPointClicked(P.x, P.y);
			if (P.y > UI.ToolBarHeight)
			{
				CFigure* picked = pManager->GetFigure(P.x, P.y);
				if (picked != NULL)
				{
					picked->SetHidden(true);
					pOut->ClearDrawArea();
					pManager->UpdateInterface();
					if (dynamic_cast<CRectangle*>(picked) && rand->gettype() == rectangle)
					{
						pickedno++;
						print(1);
					}
					else if (dynamic_cast<CCircle*>(picked) && rand->gettype() == circle)
					{
						pickedno++;
						print(1);
					}
					else if (dynamic_cast<CHexagon*>(picked) && rand->gettype() == hexagon)
					{
						pickedno++;
						print(1);
					}
					else if (dynamic_cast<CTriangle*>(picked) && rand->gettype() == triangle)
					{
						pickedno++;
						print(1);

					}
					else if (dynamic_cast<CSquare*>(picked) && rand->gettype() == square)
					{
						pickedno++;
						print(1);

					}
					else
					{
						print(0);
					}
				}
			}
			else if (P.x<UI.MenuItemWidth*1 && P.x>0)
			{
				Execute();
			}
			else if (P.x < UI.MenuItemWidth * 4 && P.x>UI.MenuItemWidth * 3)
			{
				ActionType pAct = TO_DRAW;
				pickedno = -1;
				pManager->ExecuteAction(pAct);
				break;
			}
			else 
			{
				pickedno = tobepicked;

			}
		}
		if (pickedno != -1)
		{
			pOut->PrintMessage("Game Over your right answers = " + to_string(RightAns) + " wrong answers = " + to_string(WrongAns));
			pManager->unhideall();
			pManager->UpdateInterface();
		}
	}
	else
		pOut->PrintMessage("you need to have more than one type to play");


}
void ByType::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	RightAns=0;
	WrongAns=0;
	tobepicked=0;
	pickedno=0;
}
void ByType::print(bool b)
{
	Output* pOut = pManager->GetOutput();

	if (b)
	{
		RightAns++;
		pOut->PrintMessage(" YAY! your right answers = " + to_string(RightAns) + " wrong answers = " + to_string(WrongAns));

	}
	else
	{
		WrongAns++;
		pOut->PrintMessage("OPS your right answers = " + to_string(RightAns) + " wrong answers = " + to_string(WrongAns));
	}

}