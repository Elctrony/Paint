#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "Actions/Action.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include <fstream>
#include <iomanip>
#include<iostream>

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200,MaxActionCount=200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	int selectedindex;

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	
	Action* PlayActions[MaxActionCount];
	int PlayActionCount;
	Action* UndoActions[MaxActionCount];
	int UndoActionCount;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	void SetSelectedFig(CFigure* F);
	CFigure* GetSelectedFig();
	void del();
	bool ccolor(ActionType ActType,color&c);
	void clear();
	int getfigcount();
	bool cantype();
	bool cancolor();
	bool cantypeandcolor();



	CFigure* getrandfig();
	int gettypeno(CFigure*fig);
	int getcolorno(CFigure*fig);
	int gettypeandcolorno(CFigure* fig);

	void unhideall();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void DeleteFigure(CFigure* oFig);
	//void DeleteFigure(CFigure* oFig, int index); //Delete Figure by Index
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	//Save & Load figures

	void SaveAll(ofstream& fout);
	void LoadAll(ifstream& fin);

	int GetColorIndex(color& c);
	color getColorByIndex(int index);

	//Redo Actions
	void UndoLastAction() {
		if (PlayActionCount <= 0) {
			cout << "No Action to Undo"<<endl;
			return;
		}
		if (UndoActionCount < MaxActionCount) {

			if (PlayActions[PlayActionCount - 1] == NULL) {
				cout << "Action is NULL" << endl;
				return;
			}
			PlayActions[PlayActionCount - 1]->Undo();
			cout << "Action Has beed undo"<<endl;
			UndoActions[UndoActionCount] = PlayActions[PlayActionCount - 1];
			PlayActions[PlayActionCount - 1] = NULL;
			PlayActionCount--;
			UndoActionCount++;
		}
	}
	void RedoLastAction() {
		if (UndoActionCount <= 0) {
			cout << "No Action to Redo"<<endl;
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
	
};

#endif