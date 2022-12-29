#ifndef CCIRC_H
#define CCIRC_H



#include "CFigure.h"
class CCircle:public CFigure
{
private:
	Point center;
	Point p2;
public:
	CCircle();
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	double getRadius();
	virtual void Draw(Output* pOut) const;
	virtual bool Belong(int x1, int y1);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};
#endif

