#ifndef FONCTION_PRODUIT_H
#define FONCTION_PRODUIT_H

#include "FonctionOperation.h"
#include "FonctionSomme.h"

class FonctionProduit : public FonctionOperation
{

public:


	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	FonctionProduit();

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	FonctionProduit(ListFonction& fonctions);

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	~FonctionProduit();

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/


	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	double Result();

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	Fonction* Derive(double* pcComposante);

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	Fonction* Copy();


	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	void Show();

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	bool Zero();

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	bool Un();

private:
	// Retourne une fonction constante egale au produit de deux fonctions constantes
	FonctionConstante OperationConstante(FonctionInterface& constante1, FonctionInterface& constante2);
	double ElementNeutre();


};
#endif
