#ifndef FONCTION_VARIABLE_H
#define FONCTION_VARIABLE_H

#include "Fonction.h"
#include "FonctionConstante.h"

/**
 * @brief Classe heritant de Fonction
 * Represente une fonction f(x) = x  ou x est une variable de type double du programme
 */
class FonctionVariable : public Fonction
{

	double* pdValeur;
	const char* nomVariable;

public:

	/**
	 * Constructeur par defaut
	 * @brief Cree un objet FonctionVariable dont le pointeur pdValeur egal null
	*/
	FonctionVariable();

	/**
	 * Constructeur de comfort
	 * @brief Cree un objet FonctionVariable avec un nom donne et dont le pointeur pdValeur pointe une variable donnee
	 * @param variable : adresse d'une variable a suivre
	 * @param nom : nom de la variable ('?' par defaut)
	*/
	FonctionVariable(double* variable, const char* nom = "?");

	/**
	 * Destructeur
	 * @brief Detruis l'objet FonctionVariable
	*/
	~FonctionVariable();


	/**
	 * Surcharge de Fonction::Result()
	 * @brief Retourne la valeur de la variable pointee par pdValeur
	*/
	double Result();

	/**
	 * Surcharge de Fonction::Derive(double*)
	 * @brief Retourne la derivee (un objet FonctionConstante) egale a 1 si pdComposante pointe la meme variable que pdValeur sinon 0
	 * @param pdComposante : adresse de la variable de derivation
	*/
	Fonction* Derive(double* pdComposante);

	/**
	 * Surcharge de Fonction::Copy()
	 * @brief Retourne un nouvel objet FonctionVariable alloue en memoire pointant la meme variable que pdValeur
	*/
	Fonction* Copy();

	/**
	 * Surcharge de Fonction::Show()
	 * @brief Affiche le nom de la variable nomVariable ('?' par defaut)
	*/
	void Show();

	/**
	 * Surcharge de Fonction::Zero()
	 * @brief Retourne toujours faux 
	*/
	bool Zero();

	/**
	 * Surcharge de Fonction::Un()
	 * @brief Retourne toujours faux
	*/
	bool Un();

	/**
	 * Surcharge de Fonction::Constant()
	 * @brief Retourne toujours faux
	*/
	bool Constant();

};
#endif
