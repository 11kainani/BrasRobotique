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
	 * Constructeur par défaut
	 * @brief Crée un objet FonctionVariable dont le pointeur pdValeur égal null
	*/
	FonctionVariable();

	/**
	 * Constructeur de comfort
	 * @brief Crée un objet FonctionVariable avec un nom donné et dont le pointeur pdValeur pointe une variable donnée
	 * @param variable : adresse d'une variable à suivre
	 * @param nom : nom de la variable ('?' par défaut)
	*/
	FonctionVariable(double* variable, const char* nom = "?");

	/**
	 * Destructeur
	 * @brief Détruis l'objet FonctionVariable
	*/
	~FonctionVariable();


	/**
	 * Surcharge de Fonction::Result()
	 * @brief Retourne la valeur de la variable pointée par pdValeur
	*/
	double Result();

	/**
	 * Surcharge de Fonction::Derive(double*)
	 * @brief Retourne la dérivée (un objet FonctionConstante) égale à 1 si pdComposante pointe la même variable que pdValeur sinon 0
	 * @param pdComposante
	*/
	Fonction* Derive(double* pdComposante);

	/**
	 * Surcharge de Fonction::Copy()
	 * @brief Retourne un nouvel objet FonctionVariable alloué en mémoire pointant la même variable que pdValeur
	*/
	Fonction* Copy();

	/**
	 * Surcharge de Fonction::Show()
	 * @brief Affiche le nom de la variable nomVariable ('?' par défaut)
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
