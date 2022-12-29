#include "CTriangle.h"
#include <fstream>
#include <iostream>
CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;

}

CTriangle::CTriangle():CFigure(GfxInfo())
{

}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->DrawTri(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}
bool CTriangle::Belong(int x1,int y1)
{
	double Atri= abs((Corner1.x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - Corner2.y)) / 2.0);
	double A1 = abs((x1 * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - y1) + Corner3.x * (y1 - Corner2.y)) / 2.0);


	double A2 = abs((Corner1.x * (y1 - Corner3.y) + x1 * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - y1)) / 2.0);

	
	double A3 = abs((Corner1.x * (Corner2.y - y1) + Corner2.x * (y1 - Corner1.y) + x1 * (Corner1.y - Corner2.y)) / 2.0);
	return(Atri == A1 + A2 + A3);
}


void CTriangle::Save(ofstream& fout) {
	int fillColor = FigGfxInfo.isFilled ? GetColorIndex(FigGfxInfo.FillClr) : -1;
	fout << triangle << setw(8) << ID << setw(8)
		<< Corner1.x << setw(8) << Corner1.y << setw(8)
		<< Corner2.x << setw(8) << Corner2.y << setw(8)
		<< Corner3.x << setw(8) << Corner3.y << setw(8) 
		<< GetColorIndex(FigGfxInfo.DrawClr) << setw(8) << fillColor << endl;
}

void CTriangle::Load(ifstream& fin) {
	int draw, fill;
	fin >> ID >> Corner1.x >> Corner1.y
		>> Corner2.x >> Corner2.y
		>> Corner3.x >> Corner3.y
		>> draw >> fill;
	FigGfxInfo.DrawClr = getColorByIndex(draw);
	if (fill != -1) {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getColorByIndex(fill);
	}
	else {
		FigGfxInfo.isFilled = false;
	}
	cout << triangle << setw(8) << ID << setw(8)
		<< Corner1.x << setw(8) << Corner1.y << setw(8)
		<< Corner2.x << setw(8) << Corner2.y << setw(8)
		<< Corner3.x << setw(8) << Corner3.y << setw(8)
		<< draw << setw(8) << fill << endl;
}