#ifndef FONCTION_CONSTANTE_H
#define FONCTION_CONSTANTE_H
#include "Fonction.h"

class FonctionConstante : public Fonction
{
	double dValeur;

public:
	FonctionConstante();
	FonctionConstante(double valeur);
	~FonctionConstante();

	virtual double Result();
	virtual Fonction* Derive(double* pcComposante);
	virtual Fonction* Copy();
	void Show();
	bool Zero();
	bool Un();
	bool Constant();
};
#endif

