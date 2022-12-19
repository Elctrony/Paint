#ifndef CCIRC_H
#define CCIRC_H



#include "CFigure.h"
class CCircle:public CFigure
{
private:
	Point center;
	Point p2;
	double r;
	int ID;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool Belong(int x1, int y1);
	virtual void PrintInfo(Output* pOut);
	virtual void Set_ID(int id);
};
#endif

