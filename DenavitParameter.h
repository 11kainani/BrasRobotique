#ifndef DENAVIT_PARAMETER_H
#define DENAVIT_PARAMETER_H

#include <iostream>

#include "VariableArticulaire.h"

class DenavitParameter
{
private:
	VariableArticulaire** variableArticulaire;

public:
	DenavitParameter();

	DenavitParameter(VariableArticulaire** VARListe);

	DenavitParameter(DenavitParameter& DENObject);

	~DenavitParameter();

	void AddParameter(int iIndice, VariableArticulaire VARvariable);

	void DeleteParameter(int iIndice);

	void Swap(int iFrom, int iDestination);

};
#endif
