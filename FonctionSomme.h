#ifndef FONCTION_SOMME_H
#define FONCTION_SOMME_H

#include "FonctionOperation.h"

class FonctionSomme : public FonctionOperation
{

public:


	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	FonctionSomme();

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	FonctionSomme(ListFonction& fonctions);

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	~FonctionSomme();


	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	// Retourne la somme des résultats de chaque sous fonction
	double Result();


	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	// Retourne la somme des dérivées par rapport à la composante donnée
	Fonction* Derive(double* pcComposante);


	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	// Retourne une copie polymorphique FonctionSomme
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
	// Retourne une fonction constante egal a la somme de deux fonctions constantes
	FonctionConstante OperationConstante(FonctionInterface& constante1, FonctionInterface& constante2);

	double ElementNeutre();


};
#endif
