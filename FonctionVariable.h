#ifndef FONCTION_VARIABLE_H
#define FONCTION_VARIABLE_H

#include "Fonction.h"
#include "FonctionConstante.h"

class FonctionVariable : public Fonction
{

	double* pdValeur;
	const char* nomVariable;

public:

	/**
	 * Constructeur par d�faut
	 * @brief Cr�e un objet FonctionVariable dont le pointeur pdValeur �gal null
	*/
	FonctionVariable();

	/**
	 * Constructeur de comfort
	 * @brief Cr�e un objet FonctionVariable avec un nom donn� et dont le pointeur pdValeur pointe une variable donn�e
	 * @param variable : adresse d'une variable � suivre
	 * @param nom : nom de la variable ('?' par d�faut)
	*/
	FonctionVariable(double* variable, const char* nom = "?");

	/**
	 * Destructeur
	 * @brief D�truis l'objet FonctionVariable
	*/
	~FonctionVariable();


	/**
	 * Surcharge de Fonction::Result()
	 * @brief Retourne la valeur de la variable point�e par pdValeur
	*/
	double Result();

	/**
	 * Surcharge de Fonction::Derive(double*)
	 * @brief Retourne la d�riv�e (un objet FonctionConstante) �gale � 1 si pdComposante pointe la m�me variable que pdValeur sinon 0
	 * @param pdComposante
	*/
	Fonction* Derive(double* pdComposante);

	/**
	 * Surcharge de Fonction::Copy()
	 * @brief Retourne un nouvel objet FonctionVariable allou� en m�moire pointant la m�me variable que pdValeur
	*/
	Fonction* Copy();

	/**
	 * Surcharge de Fonction::Show()
	 * @brief Affiche le nom de la variable nomVariable ('?' par d�faut)
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
