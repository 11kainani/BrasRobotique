#ifndef VARIABLE_ARTICULAIRE_H
#define VARIABLE_ARTICULAIRE_H

#include <iostream>

class VariableArticulaire
{
private:
	float fvaleur;

	float fmin;

	float fmax;

	bool bvariable;


public:
	VariableArticulaire();

	VariableArticulaire(float fValue, int fMinValue, int fMaxValue, int bIsVariable);

	~VariableArticulaire();

	float LireValeur();

	void ModifierValeur(float fValue);

	float LireMax();

	void ModifierMax(float max);

	float LireMin();

	void ModifierMin(float min);

	bool LireBVariable();

	void ModifierBVariable(bool bValue);

};
#endif
