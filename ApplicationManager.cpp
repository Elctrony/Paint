#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include"Actions/AddCircAction.h"
#include"Actions/AddSqrAction.h"
#include"Actions/AddHexaAction.h"
#include"Actions/AddTriAction.h"
#include"Actions/SelectOneAction.h"
#include"Actions/DeleteAction.h"
#include"Actions/ChangeFillColor.h"
#include"Actions/ChangeDrawColor.h"
#include"Actions/ToPlay.h"
#include"Actions/ToDraw.h"
#include"Actions/ClearAll.h"
#include"Figures/CCircle.h"
#include"Figures/CHexagon.h"
#include"Figures/CSquare.h"
#include"Figures/CRectangle.h"
#include"Figures/CTriangle.h"
#include"Actions/ByType.h"
#include"Actions/ByColor.h"
#include"Actions/ByTypeAndColor.h"
#include "Actions/SaveAction.h"
#include"Actions/LoadAction.h"







#include"Actions/Exit.h"

#include<iostream>





//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	SelectedFig = NULL;
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			break;
		case DRAW_HEXA:
			pAct = new AddHexaAction(this);
			break;
		case DRAW_SQR:
			pAct = new AddSqrAction(this);
			break;
		case DRAW_TRIANGLE:
			pAct = new AddTriAction(this);
			break;
		case SELECT:
			pAct = new SelectOneAction(this);
			break;
		case DELET:
			pAct = new DeleteAction(this);
			break;
		case FILL:
			pAct = new ChangeFillColor(this);
			break;
		case DRAWCOLOR:
			pAct = new ChangeDrawColor(this);
			break;
		case TO_PLAY:
			pAct = new ToPlay(this);
			break;
		case TO_DRAW:
			pAct = new ToDraw(this);
			break;
		case CLEAR:
			pAct = new ClearAll(this);
			break;
		case MODE1:
			pAct = new ByType(this);
			break;
		case MODE2:
			pAct = new ByColor(this);
			break;
		case MODE3:
			pAct = new ByTypeAndColor(this);
			break;
		case TO_SAVE:
			pAct = new SaveAction(this);
			break;
		case LOAD:
			std::cout << "LOAD Action" << endl;
			pAct = new LoadAction(this);
			break;
		

		case EXIT:
			pAct = new Exit(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}

bool ApplicationManager::ccolor(ActionType ActType,color&c)
{
	Action* pAct = NULL;
	switch (ActType)
	{
	case COLOR_GREEN:
		c = GREEN;
		return true;
	case COLOR_BLACK:
		c = BLACK;
		return true;
	case COLOR_BLUE:
		c = BLUE;
		return true;
	case COLOR_ORANGE:
		c = ORANGE;
		return true;
	case COLOR_RED:
		c = RED;
		return true;
	case COLOR_YELLOW:
		c = YELLOW;
		return true;
	}
	return false;
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	bool flag=0;
	for (int i = 0; i < FigCount; i++)
	{
		flag=FigList[i]->Belong(x, y);
		if (flag)
			return FigList[i];
	}
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	for (int i = 0; i < FigCount; i++)
	{
		if (!(FigList[i]->IsHidden()))
		{
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}

void ApplicationManager::SetSelectedFig(CFigure* F)
{
	SelectedFig = F;

}

CFigure* ApplicationManager::GetSelectedFig()
{
	return SelectedFig;
}

void ApplicationManager::del()
{
	if (SelectedFig != NULL)
	{
		for (int i = 0; i < FigCount; i++)
		{
			if ((FigList[i]) == SelectedFig)
			{
				SelectedFig = NULL;
				FigList[i] = FigList[FigCount - 1];
				FigList[FigCount - 1] = NULL;
				FigCount--;
				break;
			}
		}
	}
}
void ApplicationManager::clear()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
	}
	FigCount = 0;
}

int ApplicationManager::getfigcount()
{
	return FigCount;
}
bool ApplicationManager::cantype()
{
	if (FigCount > 1)
	{
		for (int i = 1; i < FigCount; i++)
		{
			if (FigList[0]->gettype() != FigList[i]->gettype())
				return true;
		}
	}
	return false;
}
CFigure* ApplicationManager::getrandfig()
{
	int n = rand() % FigCount;
	return FigList[n];
}
int ApplicationManager::gettypeno(CFigure* fig)
{
	int n = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->gettype() == fig->gettype())
			n++;
	}
	return n;
}
int ApplicationManager::getcolorno(CFigure* fig)
{
	int n = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->getfillcolor() == fig->getfillcolor())
			n++;
	}
	return n;
}
void ApplicationManager::unhideall()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsHidden())
			FigList[i]->SetHidden(0);
	}
}
bool ApplicationManager::cancolor()
{
	if (FigCount > 1)
	{
		for (int i = 1; i < FigCount; i++)
		{
			if (FigList[0]->getfillcolor() != FigList[i]->getfillcolor())
				return true;
		}
	}
	return false;
}
bool ApplicationManager::cantypeandcolor()
{
	if (FigCount > 1)
	{
		for (int i = 1; i < FigCount; i++)
		{
			if (FigList[0]->getfillcolor() != FigList[i]->getfillcolor()&& FigList[0]->gettype() != FigList[i]->gettype())
				return true;
		}
	}
	return false;
}

int ApplicationManager::gettypeandcolorno(CFigure* fig)
{
	int n = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->gettype() == fig->gettype()&& FigList[i]->getfillcolor() == fig->getfillcolor())
			n++;
	}
	return n;
}

void ApplicationManager::SaveAll(ofstream& fout) {
	fout << GetColorIndex((pOut->getCrntDrawColor())) << setw(8) << GetColorIndex((pOut->getCrntFillColor())) << endl;
	fout << FigCount << endl;
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->Save(fout);
	}
}

void ApplicationManager::LoadAll(ifstream& fin) {
	clear();
	FigCount = 0;
	int drawIndex, fillIndex;

}

int ApplicationManager::GetColorIndex(color& c) {
	if (c == RED) {
		return 1;
	}
	else if (c == GREEN) {
		return 2;
	}
	else if (c == BLUE) {
		return 3;
	}
	else if (c == YELLOW) {
		return 4;
	}
	else if (c == ORANGE) {
		return 5;
	}
	else if (c == BLACK) {
		return 6;
	}
	else {
		return -1;
	}
}


color ApplicationManager::getColorByIndex(int index) {
	if (index == 1) {
		return RED;
	}
	else if (index == 2) {
		return GREEN;
	}
	else if (index == 3) {
		return BLUE;
	}
	else if (index == 4) {
		return YELLOW;
	}
	else if (index == 5) {
		return ORANGE;
	}
	else if (index == 6) {
		return BLACK;
	}
	else {
		return WHITE;
	}
}