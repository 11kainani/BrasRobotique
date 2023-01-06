#ifndef FONCTION_VARIABLE_H
#define FONCTION_VARIABLE_H

#include "Fonction.h"
#include "FonctionConstante.h"

class FonctionVariable : public Fonction
{

	double* pdValeur;
	const char* nomVariable;

public:
	FonctionVariable();
	FonctionVariable(double* variable, const char* nom = "?");
	~FonctionVariable();

	virtual double Result();
	virtual Fonction* Derive(double* pcComposante);
	virtual Fonction* Copy();
	void Show();
	bool Zero();
	bool Un();
	bool Constant();
};
#endif
