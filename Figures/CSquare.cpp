#include "CSquare.h"
#include <fstream>
#include <iostream>
CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}

CSquare::CSquare() : CFigure(GfxInfo()) {
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSQ to draw a Square on the screen	
	pOut->DrawSQ(Center, FigGfxInfo, Selected);
}
bool CSquare::Belong(int x1, int y1)
{
	if (x1 > Center.x + 50 || x1<Center.x - 50 || y1>Center.y + 50 || y1 < Center.y - 50)
		return false;
	return true;
}
void CSquare::change(GfxInfo FigureGfxInfo)
{

}

void CSquare::Save(ofstream& fout) {
	int fillColor = FigGfxInfo.isFilled ? GetColorIndex(FigGfxInfo.FillClr) : -1;
	fout << square << setw(8) << ID << setw(8) << Center.x << setw(8) << Center.y << setw(8)
		<< GetColorIndex(FigGfxInfo.DrawClr) << setw(8) << fillColor << endl;
}


void CSquare::Load(ifstream& InFile) {
	int draw, fill;
	InFile >> ID >> Center.x >> Center.y >>  draw >> fill;
	cout << ID << setw(8) << Center.x << setw(8) << Center.y << setw(8) << draw << setw(8) << fill << endl;
	FigGfxInfo.DrawClr = getColorByIndex(draw);
	if (fill != -1) {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getColorByIndex(fill);
	}
	else {
		FigGfxInfo.isFilled = false;
	}
}
