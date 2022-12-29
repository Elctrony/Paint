#include "ByTypeAndColor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

#include"..\Figures\CCircle.h"
#include"..\Figures\CHexagon.h"
#include"..\Figures\CSquare.h" 
#include"..\Figures\CRectangle.h"
#include"..\Figures\CTriangle.h"


ByTypeAndColor::ByTypeAndColor(ApplicationManager* pApp) :Action(pApp)
{}
void ByTypeAndColor::Execute()
{
	ReadActionParameters();
	pManager->unhideall();
	pManager->UpdateInterface();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	string s;
	if (pManager->cantypeandcolor())
	{
		CFigure* rand = pManager->getrandfig();
		tobepicked = pManager->gettypeandcolorno(rand);

		if (rand->getfillcolor() == YELLOW)
			s = "Pick all Yellow";
		else if (rand->getfillcolor() == BLACK)
			s = "Pick all Black";
		else if (rand->getfillcolor() == BLUE)
			s = "Pick all Blue";
		else if (rand->getfillcolor() == ORANGE)
			s = "Pick all Orange";
		else if (rand->getfillcolor() == RED)
			s = "Pick all Red";
		else
			s = "Pick all Green";

		switch (rand->gettype())
		{
		case rectangle:
			s+=" rectangles";
			break;
		case square:
			s += " squares";
			break;
		case circle:
			s += " circles";
			break;
		case triangle:
			s += " triangles";
			break;
		case hexagon:
			s += " hexagons";
			break;
		}

		

		pOut->PrintMessage(s);

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
					if (dynamic_cast<CRectangle*>(picked) && rand->gettype() == rectangle&& picked->getfillcolor() == rand->getfillcolor() && picked->isFilled())
					{
						pickedno++;
						print(1);
					}
					else if (dynamic_cast<CCircle*>(picked) && rand->gettype() == circle&& picked->getfillcolor() == rand->getfillcolor() && picked->isFilled())
					{
						pickedno++;
						print(1);
					}
					else if (dynamic_cast<CHexagon*>(picked) && rand->gettype() == hexagon&& picked->getfillcolor() == rand->getfillcolor() && picked->isFilled())
					{
						pickedno++;
						print(1);
					}
					else if (dynamic_cast<CTriangle*>(picked) && rand->gettype() == triangle&& picked->getfillcolor() == rand->getfillcolor() && picked->isFilled())
					{
						pickedno++;
						print(1);

					}
					else if (dynamic_cast<CSquare*>(picked) && rand->gettype() == square&& picked->getfillcolor() == rand->getfillcolor() && picked->isFilled())
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
			else if (P.x < UI.MenuItemWidth * 3 && P.x> UI.MenuItemWidth * 2)
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
		pOut->PrintMessage("you need to have more than one type and color to play");


}
void ByTypeAndColor::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	RightAns = 0;
	WrongAns = 0;
	tobepicked = 0;
	pickedno = 0;
}
void ByTypeAndColor::print(bool b)
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