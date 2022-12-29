#include "CCircle.h"
#include<fstream>
#include<iostream>
using namespace std;
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	p2 = P2;
}
CCircle::CCircle() : CFigure(GfxInfo())
{
	
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a Circle on the screen	
	pOut->DrawCircle(center, p2, FigGfxInfo, Selected);
}
bool CCircle::Belong(int x1, int y1)
{
	int d = (center.x - x1) * (center.x - x1) + (center.y - y1) * (center.y - y1);
	int r= (center.x -p2.x) * (center.x - p2.x) + (center.y -p2.y) * (center.y -p2.y);
	if (d > r)
		return false;
	return true;
}																						  ;

double CCircle::getRadius() {

	return sqrt(pow((p2.x - center.x), 2) + pow((p2.y - center.y), 2));
}
 
void CCircle::Save(ofstream& fout) {
	int fillColor = FigGfxInfo.isFilled ? GetColorIndex(FigGfxInfo.FillClr) : -1;
	fout << circle << setw(8) << ID << setw(8) << center.x << setw(8) << center.y << setw(8) <<p2.x<<setw(8)<<p2.y
		<< setw(8) << GetColorIndex(FigGfxInfo.DrawClr) << setw(8) << fillColor<<endl;
}

void CCircle::Load(ifstream& Infile) {
	int  draw,fill;
	double radius;
	Infile >> ID >> center.x >> center.y >> p2.x >> p2.y >> draw >> fill;
	FigGfxInfo.DrawClr = getColorByIndex(draw);
	if (fill != -1) {
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = getColorByIndex(fill);
	}
	else {
		FigGfxInfo.isFilled = false;
	}
	cout << ID << setw(8) << center.x << setw(8) << center.y << setw(8) << p2.x << setw(8) << p2.y
		<< setw(8) << draw << setw(8) << fill << endl;
}