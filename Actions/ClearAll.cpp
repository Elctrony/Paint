#include "ClearAll.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
ClearAll::ClearAll(ApplicationManager* pApp) :Action(pApp)
{}
void ClearAll::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pManager->clear();
	pOut->ClearDrawArea();
	pOut->reset();

}
void ClearAll::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();

}