#include <iostream>
#include <fstream>

#include "VariableArticulaire.h"


VariableArticulaire::VariableArticulaire()
{
	fvaleur = 0;
	fmin = 0;
	fmax = 0;
	bvariable = 0;
}

VariableArticulaire::VariableArticulaire(float fValue, int fMinValue, int fMaxValue, int bIsVariable)
{
	if (fMinValue > fMaxValue)
	{
		// Exception
	}

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

bool VariableArticulaire::ModifierValeur(float fValue)
{
	if (fValue < fmin || fValue > fmax)
	{
		return false;
	}

	fvaleur = fValue;

	return true;
	
}

float VariableArticulaire::LireMax()
{
	return fmax;
}

bool VariableArticulaire::ModifierMax(float max)
{
	// if (max < fmin) { return false; }
	
	if(fvaleur > max)
	{
		fvaleur = max;
	}

	fmax = max;
	return true;
}

float VariableArticulaire::LireMin()
{
	return fmin;
}

bool VariableArticulaire::ModifierMin(float min)
{
	// if (min > fmax) { return false; }

	if (fvaleur < min)
	{
		fvaleur = min;
	}

	fmin = min;
	return true;
}

bool VariableArticulaire::LireBVariable()
{
	return bvariable;
}

void VariableArticulaire::ModifierBVariable(bool bValue)
{
	bvariable = bValue;
}
