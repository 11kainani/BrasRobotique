#ifndef FONCTION_SOMME_H
#define FONCTION_SOMME_H

#include "FonctionOperation.h"

/**
 * Classe héritant de FonctionOperation
 * Représente une série d'addition appliquées entre formules f1, f2, ..., fn
 */
class FonctionSomme : public FonctionOperation
{

public:


	/**
	 * Constructeur par défaut
	 * @brief Crée un objet vide
	*/
	FonctionSomme();

	/**
	 * Constructeur de comfort
	 * @brief Appel le constructeur de comfort de FonctionOperation
	 * et applique les additions entre les éléments constants
	 * @param fonctions : Liste de fonctions
	*/
	FonctionSomme(ListFonction& fonctions);

	/**
	 * Destructeur
	 * @brief Appel le destructeur de FonctionOperation
	*/
	~FonctionSomme();


	/**
	 * Surcharge de Fonction::Result()
	 * @brief Retourne la somme des résultats de chaque sous fonction
	*/
	double Result();


	/**
	 * Surcharge de Fonction::
	 * @brief Retourne la somme des dérivées par rapport à la composante donnée
	 * @param pdComposante : adresse de la variable de dérivation
	*/
	Fonction* Derive(double* pcComposante);


	/**
	 * Surcharge de Fonction::Copy()
	 * @brief Alloue dynamiquement un objet FonctionSomme en utilisant le constructeur de recopie
	*/
	Fonction* Copy();


	/**
	 * Surcharge de Fonction::
	 * @brief Affiche la somme de fonctions sous la forme [f1 + f2 + ... + fn]
	*/
	void Show();

	/**
	 * Surcharge de Fonction::Zero()
	 * @brief Retourne vrai si toutes les fonctions valent constamment 0
	*/
	bool Zero();

	/**
	 * Surcharge de Fonction::Un()
	 * @brief Retourne vrai si la somme vaut constamment 1
	 * @param
	*/
	bool Un();

private:
	/**
	 * Surcharge de FonctionOperation::OperationConstante(FonctionInterface&, FonctionInterface&)
	 * @brief Retourne une fonction constante égale à la somme de deux fonctions constantes
	 * @param constante1 : Objet FonctionInterface dont la formule est constante
	 * @param constante2 : Objet FonctionInterface dont la formule est constante
	*/
	FonctionConstante OperationConstante(FonctionInterface& constante1, FonctionInterface& constante2);

	/**
	 * Surcharge de FonctionOperation::ElementNeutre()
	 * @brief Retourne 0, l'élément neutre de la somme
	*/
	double ElementNeutre();


};
#endif
