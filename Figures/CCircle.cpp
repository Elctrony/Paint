#include "CCircle.h"
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P1;
	p2 = P2;
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
}