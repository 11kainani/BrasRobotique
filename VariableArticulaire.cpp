#include <iostream>
#include <fstream>

#include "VariableArticulaire.h"


VariableArticulaire::VariableArticulaire()
{
}

VariableArticulaire::VariableArticulaire(float fValue, int fMinValue, int fMaxValue, int bIsVariable)
{
	fvaleur = fValue;
	fmin = fMinValue;
	fmax = fMaxValue;
	bvariable = bIsVariable;
}

VariableArticulaire::~VariableArticulaire()
{
}

float VariableArticulaire::LireValeur()
{
	return fvaleur;
}

void VariableArticulaire::ModifierValeur(float fValue)
{
	fvaleur = fValue;
}

float VariableArticulaire::LireMax()
{
	return fmax;
}

void VariableArticulaire::ModifierMax(float max)
{
	fmax = max;
}

float VariableArticulaire::LireMin()
{
	return fmin;
}

void VariableArticulaire::ModifierMin(float min)
{
	fmin = min;
}

bool VariableArticulaire::LireBVariable()
{
	return bvariable;
}

void VariableArticulaire::ModifierBVariable(bool bValue)
{
	bvariable = bValue;
}
