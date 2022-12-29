#include "CRectangle.h"
#include<fstream>
#include<iostream>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	
CRectangle::CRectangle():CFigure(GfxInfo()) {}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::Belong(int x1, int y1)
{
	if (Corner1.x > Corner2.x)
	{
		if (x1>Corner1.x || x1<Corner2.x)
			return false;
	}
	else {
		if (x1 < Corner1.x || x1 > Corner2.x)
			return false;
	}
	if (Corner1.y > Corner2.y)
	{
		if (y1 > Corner1.y || y1 < Corner2.y)
			return false;
	}
	else {
		if (y1 < Corner1.y || y1 > Corner2.y)
			return false;
	}
	return true;
}

void CRectangle::Save(ofstream& fout) {
	int fillColor = FigGfxInfo.isFilled ? GetColorIndex(FigGfxInfo.FillClr) : -1;
	fout << rectangle << setw(8) << ID << setw(8) << Corner1.x << setw(8) << Corner1.y << setw(8) << Corner2.x << setw(8) << Corner2.y
		<< setw(8) << GetColorIndex(FigGfxInfo.DrawClr) << setw(8) << fillColor << endl;
}

void CRectangle::Load(ifstream& fin) {
	int  draw, fill;
	fin >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> draw >> fill;
	cout << ID << setw(8) << Corner1.x << setw(8) << Corner1.y << setw(8)
		 << Corner2.x << setw(8) << Corner2.y << setw(8) << draw << setw(8) << fill << endl;
	FigGfxInfo.DrawClr = getColorByIndex(draw);
	if (fill != -1) {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getColorByIndex(fill);
	}
	else {
		FigGfxInfo.isFilled = false;
	}
}