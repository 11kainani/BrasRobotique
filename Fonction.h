#ifndef FONCTION_H
#define FONCTION_H

#include <iostream>
using namespace std;

/**
 * Classe abstraite �tablissant les fonctionnalit�s requises des classes filles
 * Repr�sente un fonction math�matique donn�e
 */
class Fonction
{
public:

	/**
	 * M�thode virtuelle pure
	 * @brief Retourne le r�sultat du calcul de la fonction
	*/
	virtual double Result()=0;

	/**
	 * M�thode virtuelle pure
	 * @brief Retourne la d�riv�e de la fonction
	 * ATTENTION : Retourne un pointeur Fonction allou� dynamiquement par new
	 * Vous devez obligatoirement utiliser l'instruction delete sur l'�l�ment retourn�
	 * Note : Stockez l'�l�ment dans une variable Fonction* non allou�e
	 * @param pdComposant : adresse de la variable de d�rivation
	*/
	virtual Fonction* Derive(double* pdComposant) = 0;

	/**
	 * M�thode virtuelle pure
	 * @brief Retourne une copie de la fonction
	 * ATTENTION : Retourne un pointeur Fonction allou� dynamiquement par new
	 * Vous devez obligatoirement utiliser l'instruction delete sur l'�l�ment retourn�
	 * Note : Stockez l'�l�ment dans une variable Fonction* non allou�e
	*/
	virtual Fonction* Copy() = 0;

	/**
	 * M�thode virtuelle pure
	 * @brief Affiche la formule de la fonction
	*/
	virtual void Show() = 0;

	/**
	 * M�thode virtuelle pure
	 * @brief La formule vaut-elle constamment 0 ?
	*/
	virtual bool Zero() = 0;

	/**
	 * M�thode virtuelle pure
	 * @brief La formule vaut-elle constamment 1 ?
	*/
	virtual bool Un() = 0;

	/**
	 * M�thode virtuelle pure
	 * @brief La formule est-elle une constante ?
	*/
	virtual bool Constant() = 0;

	/**
	 * Destructeur virtuel
	 * @brief D�truis l'objet
	*/
	virtual ~Fonction();
};
#endif 

