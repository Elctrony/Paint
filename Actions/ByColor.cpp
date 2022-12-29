#include "ByColor.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

ByColor::ByColor(ApplicationManager* pApp) :Action(pApp)
{}

void ByColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	RightAns=0;
	WrongAns=0;
	tobepicked=0;
	pickedno=0;
}
void ByColor::Execute()
{
	ReadActionParameters();
	pManager->unhideall();    //in case we want to restart
	pManager->UpdateInterface();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->cancolor())  //checking that there are multiple color to play
	{
		CFigure* rand = pManager->getrandfig();    //choosing random figure
		tobepicked = pManager->getcolorno(rand);    //getting number of figures with the same color as the random figure
		if(rand->getfillcolor()==YELLOW)
			pOut->PrintMessage("Pick all Yellow figures");
		else if (rand->getfillcolor() == BLACK)
			pOut->PrintMessage("Pick all Black figures");
		else if (rand->getfillcolor() == BLUE)
			pOut->PrintMessage("Pick all Blue figures");
		else if (rand->getfillcolor() == ORANGE)
			pOut->PrintMessage("Pick all Orange figures");
		else if (rand->getfillcolor() == RED)
			pOut->PrintMessage("Pick all Red figures");
		else 
			pOut->PrintMessage("Pick all Green figures");
		while (pickedno != tobepicked)    //kid keep picking till all right figures are picked
		{
			pIn->GetPointClicked(P.x, P.y);
			if (P.y > UI.ToolBarHeight)
			{
				CFigure* picked = pManager->GetFigure(P.x, P.y);
				if (picked != NULL)
				{
					picked->SetHidden(true);  //hiding the figure
					pOut->ClearDrawArea();
					pManager->UpdateInterface();
					if (picked->getfillcolor()==rand->getfillcolor()&&picked->isFilled())  //checking if it match the chosen figure
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
			else if (P.x < UI.MenuItemWidth * 2 && P.x>UI.MenuItemWidth * 1)  //restarting the game
			{
				Execute();
			}
			else if (P.x < UI.MenuItemWidth * 4 && P.x>UI.MenuItemWidth * 3)  //going back to draw mode
			{
				ActionType pAct = TO_DRAW;
				pickedno = -1;
				pManager->ExecuteAction(pAct);
				break;
			}
			else
			{
				pickedno = tobepicked;  //clicking any other space end the game

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
	{
		pOut->PrintMessage("you need to have more than one color to play");

	}
}

void ByColor::print(bool b)
{
	Output* pOut = pManager->GetOutput();

	if (b)  //right answer
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