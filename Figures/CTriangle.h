#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point,Point, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void Draw(Output* pOut) const;
	virtual bool Belong(int x1,int y1);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
};

#endif

