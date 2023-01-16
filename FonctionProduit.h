#ifndef FONCTION_PRODUIT_H
#define FONCTION_PRODUIT_H

#include "FonctionOperation.h"
#include "FonctionSomme.h"

/**
 * @brief  Classe heritant de FonctionOperation
 * Represente une serie de multiplication appliquees entre formules f1, f2, ... et fn
 */
class FonctionProduit : public FonctionOperation
{

public:


	/**
	 * Constructeur par defaut
	 * @brief Cree un objet vide
	*/
	FonctionProduit();

	/**
	 * Constructeur de comfort
	 * @brief Appel le constructeur de comfort de FonctionOperation
	 * et applique les multiplications entre les elements constants
	 * @param fonctions : Liste de fonctions
	*/
	FonctionProduit(ListFonction& fonctions);

	/**
	 * Destructeur
	 * @brief Appel le destructeur de FonctionOperation
	*/
	~FonctionProduit();

	/**
	 * Surcharge de Fonction::Result()
	 * @brief Retourne le resultat de la multiplication des formules (f1*f2*...*fn)
	*/
	double Result();

	/**
	 * Surcharge de Fonction::Derive(double*)
	 * @brief Alloue dynamiquement la derive du produit de fonctions
	 * (f1*f2*...*fn) -> (f1'*f2*...*fn) + (f1*f2'*...*fn) + ... + (f1*f2*...*fn')
	 * @param pdComposante : adresse de la variable de derivation
	*/
	Fonction* Derive(double* pcComposante);

	/**
	 * Surcharge de Fonction::Copy()
	 * @brief Alloue dynamiquement une copie de l'objet FonctionProduit en utilisant le constructeur de recopie
	*/
	Fonction* Copy();


	/**
	 * Surcharge de Fonction::Show()
	 * @brief Affiche le produit de fonctions sous la forme (f1 * f2 * ... * fn)
	*/
	void Show();

	/**
	 * Surcharge de Fonction::Zero()
	 * @brief Retourne vrai si l'une des fonctions vaut constamment 0
	*/
	bool Zero();

	/**
	 * Surcharge de Fonction::Un()
	 * @brief Retourne vrai si toutes les fonctions valent constamment 1
	*/
	bool Un();

private:

	
	/**
	 * Surcharge de FonctionOperation::OperationConstante(FonctionInterface&, FonctionInterface&)
	 * @brief Retourne une fonction constante egale au produit de deux fonctions constantes
	 * @param constante1 : Objet FonctionInterface dont la formule est constante
	 * @param constante2 : Objet FonctionInterface dont la formule est constante
	*/
	FonctionConstante OperationConstante(FonctionInterface& constante1, FonctionInterface& constante2);

	/**
	 * Surcharge de FonctionOperation::ElementNeutre()
	 * @brief Retourne 1, l'element neutre du produit
	*/
	double ElementNeutre();


};
#endif
