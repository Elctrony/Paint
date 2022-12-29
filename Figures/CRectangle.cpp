#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

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
