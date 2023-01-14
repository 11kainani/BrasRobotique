#include <iostream>
#include <fstream>

#include "VariableArticulaire.h"


VariableArticulaire::VariableArticulaire()
{
	dvaleur = 0;
	dvariable = 0;
	fmin = 0;
	fmax = 0;
	bvariable = false;
	bAngulaire = false;
}

VariableArticulaire::VariableArticulaire(double fValue, int fMinValue, int fMaxValue, int bIsVariable)
{
	if (fMinValue > fMaxValue)
	{
		// Exception
	}

	dvaleur = fValue;
	dvariable = dvaleur;
	fmin = fMinValue;
	fmax = fMaxValue;
	bvariable = bIsVariable;
	bAngulaire = false;
}

VariableArticulaire::~VariableArticulaire()
{
}

double VariableArticulaire::LireValeur()
{
	return dvaleur;
}

bool VariableArticulaire::ModifierValeur(double fValue)
{
	/*
	if (fValue < fmin || fValue > fmax)
	{
		return false;
	}
	*/
	dvaleur = fValue;
	dvariable = dvaleur;

	return true;

}

double* VariableArticulaire::LireVariable()
{
	return &dvariable;
}

double VariableArticulaire::LireMax()
{
	return fmax;
}

bool VariableArticulaire::ModifierMax(double max)
{
	// if (max < fmin) { return false; }

	if (dvaleur > max)
	{
		ModifierValeur(max);
	}

	fmax = max;
	return true;
}

double VariableArticulaire::LireMin()
{
	return fmin;
}

bool VariableArticulaire::ModifierMin(double min)
{
	// if (min > fmax) { return false; }

	if (dvaleur < min)
	{
		ModifierValeur(min);
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

bool VariableArticulaire::LireBAngulaire()
{
	return bAngulaire;
}

void VariableArticulaire::ModifierBAngulaire(bool bValue)
{
	bAngulaire = bValue;
}