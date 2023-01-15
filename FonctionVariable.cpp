#include "FonctionVariable.h"



FonctionVariable::FonctionVariable()
{
	pdValeur = nullptr;
}

FonctionVariable::FonctionVariable(double* variable, const char* nom)
{
	pdValeur = variable;
	nomVariable = nom;
}

FonctionVariable::~FonctionVariable()
{
	if (pdValeur != nullptr)
	{
		pdValeur = nullptr;
	}
}


double FonctionVariable::Result()
{
	// Retourne la valeur pointé par la variable ou 0
	return (pdValeur != nullptr ? *(pdValeur) : 0);
}

Fonction* FonctionVariable::Derive(double* pdComposant)
{
	// Retourne une constante égale à 1 si variable dérivé par rapport à elle-même sinon constante égale à 0
	return new FonctionConstante((pdComposant == pdValeur ? 1 : 0));
}

Fonction* FonctionVariable::Copy()
{
	return new FonctionVariable(pdValeur, nomVariable);
}

void FonctionVariable::Show()
{
	cout << nomVariable;
}

bool FonctionVariable::Zero()
{
	return false;
}

bool FonctionVariable::Un()
{
	return false;
}

bool FonctionVariable::Constant()
{
	return false;
}

