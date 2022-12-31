#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions/Action.h"
#include <fstream>
#include <iomanip>
#include<iostream>
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200, MaxActionCount = 200};	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	int Count;
	Action* stored[20];

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	Action* pLast;

	bool soundon;


	Action* PlayActions[MaxActionCount];
	int PlayActionCount;
	Action* UndoActions[MaxActionCount];
	int UndoActionCount;
	bool RECMODE;
	int i;

public:	
	ApplicationManager(); 
	~ApplicationManager();

	//setter and getter for selected figure
	void SetSelectedFig(CFigure* F);
	CFigure* GetSelectedFig() const;
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
		
	bool getfillstatus();   //getter for filled or not filled

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	Action* GetLastAction() const; 
	Action** GetRecs() ;
	void ClearRec();
	int getfigcount() const;  //gets number of figures

	bool ChngColor(ActionType ActType, color& c);
	void del();  //deletes a figure from FigList
	void clear();   //clearing the FigList

	void setsound(bool b);
	bool getsound();


	//unhiding all figures
	void unhideall();

	//getting a random figure
	CFigure* getrandfig();
	CFigure* getrandcolorfig();

	//getting number of figures with the same qualities
	int gettypeno(CFigure* fig);
	int getcolorno(CFigure* fig);
	int gettypeandcolorno(CFigure* fig);

	//checking if the kid can pick by color
	bool CanPlay();
	void SaveAll(ofstream& fout);
	void ApplicationManager::LoadAll(ifstream& fin);

	int ApplicationManager::GetColorIndex(color& c);


	color ApplicationManager::getColorByIndex(int index);

	void ApplicationManager::DeleteFigure(CFigure* figure);
	//Redo Actions
	void UndoLastAction() {
		if (PlayActionCount <= 0) {
			cout << "No Action to Undo" << endl;
			return;
		}
		if (UndoActionCount < MaxActionCount) {

			if (PlayActions[PlayActionCount - 1] == NULL) {
				cout << "Action is NULL" << endl;
				return;
			}
			PlayActions[PlayActionCount - 1]->Undo();
			cout << "Action Has beed undo" << endl;
			UndoActions[UndoActionCount] = PlayActions[PlayActionCount - 1];
			PlayActions[PlayActionCount - 1] = NULL;
			PlayActionCount--;
			UndoActionCount++;
		}
	}
	void RedoLastAction() {
		if (UndoActionCount <= 0) {
			cout << "No Action to Redo" << endl;
			return;
		}
		if (PlayActionCount < MaxActionCount) {

			UndoActionCount--;
			UndoActions[UndoActionCount]->Redo();
			PlayActions[PlayActionCount] = UndoActions[UndoActionCount];
			UndoActions[UndoActionCount] = NULL;
			PlayActionCount++;
		}
	}
	void ClearUndoAction() {
		for (int i = 0; i < UndoActionCount; i++) {
			delete UndoActions[i];
			UndoActions[i] = NULL;
		}
		UndoActionCount = 0;
	}
	void ClearPlayAction() {
		for (int i = 0; i < PlayActionCount; i++) {
			delete PlayActions[i];
			PlayActions[i] = NULL;
		}
		PlayActionCount = 0;
	}
	void setlastaction(Action* A) {
		pLast = A;
	}
	void setRECMODE(bool b) { RECMODE = b; }
};

#endif