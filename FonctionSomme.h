#ifndef FONCTION_SOMME_H
#define FONCTION_SOMME_H

#include "FonctionOperation.h"

class FonctionSomme : public FonctionOperation
{

public:
	FonctionSomme();
	FonctionSomme(ListFonction& fonctions);
	~FonctionSomme();

	// Retourne la somme des résultats de chaque sous fonction
	virtual double Result();

	// Retourne la somme des dérivées par rapport à la composante donnée
	virtual Fonction* Derive(double* pcComposante);

	// Retourne une copie polymorphique FonctionSomme
	virtual Fonction* Copy();

	void Show();
	bool Zero();
	bool Un();

private:
	// Retourne une fonction constante egal a la somme de deux fonctions constantes
	virtual FonctionConstante OperationConstante(FonctionInterface& constante1, FonctionInterface& constante2);

	virtual double ElementNeutre();


};
#endif
