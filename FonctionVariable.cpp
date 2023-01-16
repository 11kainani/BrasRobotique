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
	// Retourne la valeur pointe par la variable ou 0
	return (pdValeur != nullptr ? *(pdValeur) : 0);
}

Fonction* FonctionVariable::Derive(double* pdComposant)
{
	// Retourne une constante egale a 1 si variable derive par rapport a elle-meme sinon constante egale a 0
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

