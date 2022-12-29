#include "Exit.h"
#include "..\ApplicationManager.h"
#include"ClearAll.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
Exit::Exit(ApplicationManager* pApp) :Action(pApp)
{}
void Exit::Execute()
{
	ReadActionParameters();
}
void Exit::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Saving & Exiting..GoodBye");

}
