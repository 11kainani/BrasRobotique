#ifndef FONCTION_CONSTANTE_H
#define FONCTION_CONSTANTE_H
#include "Fonction.h"

class FonctionConstante : public Fonction
{
	double dValeur;

public:

	/**
	 * Constructeur par défaut
	 * @brief Crée un objet FonctionConstante dont la valeur est 0
	*/
	FonctionConstante();

	/**
	 * Contructeur de comfort
	 * @brief Crée un objet FonctionConstante avec une valeur donnée
	 * @param valeur
	*/
	FonctionConstante(double valeur);

	/**
	 * Destructeur
	 * @brief Détruis l'objet FonctionConstante
	*/
	~FonctionConstante();


	/**
	 * Surcharge de Fonction::Result()
	 * @brief Retourne la valeur de la constante
	*/
	double Result();

	/**
	 * Surcharge de Fonction::Derive(double*)
	 * @brief Retourne un nouvel objet FonctionConstante égal à 0
	 * @param pdComposante
	*/
	Fonction* Derive(double* pdComposante);

	/**
	 * Surcharge de Fonction::Copy()
	 * @brief Retourne un nouvel objet FonctionConstante alloué en mémoire avec la même valeur
	*/
	Fonction* Copy();


	/**
	 * Surcharge de Fonction::Show()
	 * @brief Affiche la valeur de la constante
	*/
	void Show();

	/**
	 * Surcharge de Fonction::Zero()
	 * @brief La valeur est-elle égale à 0 ?
	*/
	bool Zero();

	/**
	 * Surcharge de Fonction::Un()
	 * @brief La valeur est-elle égale à 1 ?
	*/
	bool Un();

	/**
	 * Surcharge de Fonction::Constante()
	 * @brief Retourne toujours vrai
	*/
	bool Constant();
};
#endif

