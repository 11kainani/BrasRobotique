#ifndef FONCTION_H
#define FONCTION_H

#include <iostream>
using namespace std;

/**
 * Classe abstraite établissant les fonctionnalités requises des classes filles
 * Représente un fonction mathématique donnée
 */
class Fonction
{
public:

	/**
	 * Méthode virtuelle pure
	 * @brief Retourne le résultat du calcul de la fonction
	*/
	virtual double Result()=0;

	/**
	 * Méthode virtuelle pure
	 * @brief Retourne la dérivée de la fonction
	 * ATTENTION : Retourne un pointeur Fonction alloué dynamiquement par new
	 * Vous devez obligatoirement utiliser l'instruction delete sur l'élément retourné
	 * Note : Stockez l'élément dans une variable Fonction* non allouée
	 * @param pdComposant : adresse de la variable de dérivation
	*/
	virtual Fonction* Derive(double* pdComposant) = 0;

	/**
	 * Méthode virtuelle pure
	 * @brief Retourne une copie de la fonction
	 * ATTENTION : Retourne un pointeur Fonction alloué dynamiquement par new
	 * Vous devez obligatoirement utiliser l'instruction delete sur l'élément retourné
	 * Note : Stockez l'élément dans une variable Fonction* non allouée
	*/
	virtual Fonction* Copy() = 0;

	/**
	 * Méthode virtuelle pure
	 * @brief Affiche la formule de la fonction
	*/
	virtual void Show() = 0;

	/**
	 * Méthode virtuelle pure
	 * @brief La formule vaut-elle constamment 0 ?
	*/
	virtual bool Zero() = 0;

	/**
	 * Méthode virtuelle pure
	 * @brief La formule vaut-elle constamment 1 ?
	*/
	virtual bool Un() = 0;

	/**
	 * Méthode virtuelle pure
	 * @brief La formule est-elle une constante ?
	*/
	virtual bool Constant() = 0;

	/**
	 * Destructeur virtuel
	 * @brief Détruis l'objet
	*/
	virtual ~Fonction();
};
#endif 

