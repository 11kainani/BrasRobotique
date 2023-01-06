#ifndef VARIABLE_ARTICULAIRE_H
#define VARIABLE_ARTICULAIRE_H

#include <iostream>

class VariableArticulaire
{
private:
	double dvaleur;

	double dvariable;  // copie de fvaleur accessible uniquement en lecture

	double fmin;

	double fmax;

	bool bvariable;

	bool bAngulaire;


public:
	VariableArticulaire();

	VariableArticulaire(double fValue, int fMinValue, int fMaxValue, int bIsVariable);

	~VariableArticulaire();

	double LireValeur();

	bool ModifierValeur(double fValue);

	double* LireVariable();

	double LireMax();

	bool ModifierMax(double max);

	double LireMin();

	bool ModifierMin(double min);

	bool LireBVariable();

	void ModifierBVariable(bool bValue);

	bool LireBAngulaire();

	void ModifierBAngulaire(bool bValue);

};
#endif