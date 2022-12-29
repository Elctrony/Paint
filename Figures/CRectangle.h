#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle();
	virtual void Draw(Output* pOut) const;
	virtual bool Belong(int x1, int y1);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
};

#endif