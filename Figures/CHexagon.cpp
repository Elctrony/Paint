#include "CHexagon.h"
CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}


void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHexa to draw a Hexagon on the screen	
	pOut->DrawHexa(Center, FigGfxInfo, Selected);
}
bool CHexagon::Belong(int x1, int y1)
{
	if ((x1 <= Center.x + 25) && (x1 >= Center.x - 25) && y1 >= Center.y - 25 * sqrt(3) && y1 <= Center.y + 25 * sqrt(3))
		return true;
	int p1x = Center.x + 25;
	int p2x = p1x;
	int p3x = p1x +25;
	int p1y = Center.y + 25 * sqrt(3);
	int p2y= Center.y - 25 * sqrt(3);
	int p3y = Center.y;
	double Atri = abs((p1x * (p2y - p3y) + p2x * (p3y - p1y) + p3x * (p1y - p2y)) / 2.0);
	double A1 = abs((x1 * (p2y - p3y) + p2x * (p3y - y1) + p3x * (y1 - p2y)) / 2.0);
	double A2 = abs((p1x * (y1 - p3y) + x1 * (p3y - p1y) + p3x * (p1y - y1)) / 2.0);
	double A3 = abs((p1x * (p2y - y1) + p2x * (y1 - p1y) + x1 * (p1y - p2y)) / 2.0);
	if (Atri == A1 + A2 + A3)
		return true;
	else {
		p1x = Center.x - 25;
		p2x = p1x;
		p3x = p1x - 25;
		 A1 = abs((x1 * (p2y - p3y) + p2x * (p3y - y1) + p3x * (y1 - p2y)) / 2.0);
		 A2 = abs((p1x * (y1 - p3y) + x1 * (p3y - p1y) + p3x * (p1y - y1)) / 2.0);
	     A3 = abs((p1x * (p2y - y1) + p2x * (y1 - p1y) + x1 * (p1y - p2y)) / 2.0);
		if (Atri == A1 + A2 + A3)
			return true;

	}
	return false;
}
void CHexagon::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("hexagon_ID:"+to_string(ID)+" Center:" + to_string(Center.x) + " " + to_string(Center.y));

}

void CHexagon::Set_ID(int id)
{
	ID = id;
}

void CHexagon::shift(Point P)
{
	Center.x = P.x;
	Center.y = P.y;
}
