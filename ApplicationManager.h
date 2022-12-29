#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include <fstream>
#include <iomanip>

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	int selectedindex;

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

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
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	

	//Save & Load figures

	void SaveAll(ofstream& fout);
	void LoadAll(ifstream& fin);

	int GetColorIndex(color& c);
	color getColorByIndex(int index);

};

#endif