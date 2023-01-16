#ifndef FONCTION_H
#define FONCTION_H

#include <iostream>
using namespace std;

/**
 * @brief Classe abstraite etablissant les fonctionnalites requises des classes filles
 * Represente un fonction mathematique donnee
 */
class Fonction
{
public:

	/**
	 * Methode virtuelle pure
	 * @brief Retourne le resultat du calcul de la fonction
	*/
	virtual double Result()=0;

	/**
	 * Methode virtuelle pure
	 * @brief Retourne la derivee de la fonction
	 * ATTENTION : Retourne un pointeur Fonction alloue dynamiquement par new
	 * Vous devez obligatoirement utiliser l'instruction delete sur l'element retourne
	 * Note : Stockez l'element dans une variable Fonction* non allouee
	 * @param pdComposant : adresse de la variable de derivation
	*/
	virtual Fonction* Derive(double* pdComposant) = 0;

	/**
	 * Methode virtuelle pure
	 * @brief Retourne une copie de la fonction
	 * ATTENTION : Retourne un pointeur Fonction alloue dynamiquement par new
	 * Vous devez obligatoirement utiliser l'instruction delete sur l'element retourne
	 * Note : Stockez l'element dans une variable Fonction* non allouee
	*/
	virtual Fonction* Copy() = 0;

	/**
	 * Methode virtuelle pure
	 * @brief Affiche la formule de la fonction
	*/
	virtual void Show() = 0;

	/**
	 * Methode virtuelle pure
	 * @brief La formule vaut-elle constamment 0 ?
	*/
	virtual bool Zero() = 0;

	/**
	 * Methode virtuelle pure
	 * @brief La formule vaut-elle constamment 1 ?
	*/
	virtual bool Un() = 0;

	/**
	 * Methode virtuelle pure
	 * @brief La formule est-elle une constante ?
	*/
	virtual bool Constant() = 0;

	/**
	 * Destructeur virtuel
	 * @brief Detruis l'objet
	*/
	virtual ~Fonction();
};
#endif 

