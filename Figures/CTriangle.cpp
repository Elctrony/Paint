#include "CTriangle.h"
#include "..\GUI\UI_Info.h"
CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;

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

void CTriangle::PrintInfo(Output* pOut)
{
	string s1 = to_string(Corner1.x) +" "+ to_string(Corner1.y);
	string s2 = to_string(Corner2.x) +" "+ to_string(Corner2.y);
	string s3 = to_string(Corner3.x) +" "+ to_string(Corner3.y);
	pOut->PrintMessage("triangle_ID:"+to_string(ID)+"corners are:"+s1+"  "+s2 +"  "+ s3);
}

void CTriangle::Set_ID(int id)
{
	ID = id;
}
