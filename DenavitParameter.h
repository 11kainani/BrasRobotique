#ifndef DENAVIT_PARAMETER_H
#define DENAVIT_PARAMETER_H

#include <iostream>
#include "VariableArticulaire.h"
using namespace std;
#define NB_VARIABLES 4

class DenavitParameter
{
private:
	VariableArticulaire** pVARVariable;

public:
	DenavitParameter();

	DenavitParameter(VariableArticulaire** VARListe);

	DenavitParameter(DenavitParameter& DENObject);

	~DenavitParameter();

	void SetVariable(int iIndice, VariableArticulaire* VARvariable);

	void DeleteVariable(int iIndice);

	DenavitParameter& operator=(DenavitParameter& parameter);

	double* LireVariable(int Iindice);

	double LireValeur(int Iindice);
	
	bool LireBVariable(int Iindice);

	// void Swap(int iFrom, int iDestination);

	void Affiche();

};
#endif