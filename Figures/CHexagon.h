#ifndef CHEX_H
#define CHEX_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	CHexagon();
	virtual void Draw(Output* pOut) const;
	virtual bool Belong(int x1, int y1);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);

};

#endif

