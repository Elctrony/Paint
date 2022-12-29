#include "LoadAction.h"
#include"../ApplicationManager.h"
#include "../Figures/CCircle.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CTriangle.h"


LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp) {

}

void LoadAction::ReadActionParameters() {
	Output* out = pManager->GetOutput();
	Input* in = pManager->GetInput();
	out->PrintMessage("Enter the name of the file to laod from:");
	filename = in->GetSrting(out);
	filename.append(".txt");
	out->ClearStatusBar();
	out->PrintMessage("Figures have been Loaded from " + filename);
}

void LoadAction::Execute() {
	ReadActionParameters();
	ifstream fin;
	fin.open(filename);
	// rectangle, circle, square, hexagon, triangle
	if (fin.is_open()) {
		pManager->clear();
		int draw, fill, figCount;
		fin >> draw >> fill >> figCount;
		std::cout << draw << "      " << fill << "         " << figCount << endl;
		color drawColor = pManager->getColorByIndex(draw);
		color fillColor = pManager->getColorByIndex(fill);
		pManager->GetOutput()->setCrntDrawColor(drawColor);
		pManager->GetOutput()->setCrntFillColor(fillColor);
		int figType;
		for (int i = 0; i < figCount; i++) {
			fin >> figType;
			CFigure* tempFigure;
			if (figType == rectangle) {
				cout << "Rectangle" << endl;
				tempFigure = new CRectangle();
				tempFigure->Load(fin);
			}
			else if (figType == circle) {
				cout << "Circle" << endl;
				tempFigure = new CCircle();
				tempFigure->Load(fin);
			}
			else if (figType == square) {
				cout << "Square" << endl;
				tempFigure = new CSquare();
				tempFigure->Load(fin);
			}
			else if (figType == hexagon) {
				cout << "Hexagon" << endl;
				tempFigure = new CHexagon();
				tempFigure->Load(fin);
			}
			else if (figType == triangle) {
				cout << "Trianlge" << endl;
				tempFigure = new CTriangle();
				tempFigure->Load(fin);
			}
			else {
				cout << "NONE" << endl;
				continue;
			}
			pManager->AddFigure(tempFigure);

		}
	}
}