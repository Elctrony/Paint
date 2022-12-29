#include"Action.h"
#include<fstream>
#include<iostream>
#include"../ApplicationManager.h"
class LoadAction : public Action {
private:
	string filename="Figures.txt";
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	virtual void Execute();
};
#pragma once
