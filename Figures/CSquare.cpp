#include "CSquare.h"
CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
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

