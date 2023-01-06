#include "FonctionConstante.h"



FonctionConstante::FonctionConstante()
{
	dValeur = 0;
}

FonctionConstante::FonctionConstante(double valeur)
{
	dValeur = valeur;
}

FonctionConstante::~FonctionConstante()
{
}

double FonctionConstante::Result()
{
	return dValeur;
}

Fonction* FonctionConstante::Derive(double* pdComposant)
{
	return new FonctionConstante(0);
}

Fonction* FonctionConstante::Copy()
{
	return new FonctionConstante(dValeur);
}

void FonctionConstante::Show()
{
	cout << dValeur;
}

bool FonctionConstante::Zero()
{
	return (dValeur == 0);
}

bool FonctionConstante::Un()
{
	return (dValeur == 1);
}

bool FonctionConstante::Constant()
{
	return true;
}
