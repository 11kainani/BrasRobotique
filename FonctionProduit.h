#ifndef FONCTION_PRODUIT_H
#define FONCTION_PRODUIT_H

#include "FonctionOperation.h"
#include "FonctionSomme.h"

class FonctionProduit : public FonctionOperation
{

public:
	FonctionProduit();
	FonctionProduit(ListFonction& fonctions);
	~FonctionProduit();

	virtual double Result();
	virtual Fonction* Derive(double* pcComposante);
	virtual Fonction* Copy();
	void Show();
	bool Zero();
	bool Un();

private:
	// Retourne une fonction constante egale au produit de deux fonctions constantes
	virtual FonctionConstante OperationConstante(FonctionInterface& constante1, FonctionInterface& constante2);
	virtual double ElementNeutre();


};
#endif
