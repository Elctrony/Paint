#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
public:
	CSquare(Point,GfxInfo FigureGfxInfo);
	CSquare();
	virtual void Draw(Output* pOut) const;
	virtual bool Belong(int x1, int y1);
	virtual void change(GfxInfo FigureGfxInfo);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
};

#endif

