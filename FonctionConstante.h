#ifndef FONCTION_CONSTANTE_H
#define FONCTION_CONSTANTE_H
#include "Fonction.h"

class FonctionConstante : public Fonction
{
	double dValeur;

public:

	/**
	 * Constructeur par d�faut
	 * @brief Cr�e un objet FonctionConstante dont la valeur est 0
	*/
	FonctionConstante();

	/**
	 * Contructeur de comfort
	 * @brief Cr�e un objet FonctionConstante avec une valeur donn�e
	 * @param valeur
	*/
	FonctionConstante(double valeur);

	/**
	 * Destructeur
	 * @brief D�truis l'objet FonctionConstante
	*/
	~FonctionConstante();


	/**
	 * Surcharge de Fonction::Result()
	 * @brief Retourne la valeur de la constante
	*/
	double Result();

	/**
	 * Surcharge de Fonction::Derive(double*)
	 * @brief Retourne un nouvel objet FonctionConstante �gal � 0
	 * @param pdComposante
	*/
	Fonction* Derive(double* pdComposante);

	/**
	 * Surcharge de Fonction::Copy()
	 * @brief Retourne un nouvel objet FonctionConstante allou� en m�moire avec la m�me valeur
	*/
	Fonction* Copy();


	/**
	 * Surcharge de Fonction::Show()
	 * @brief Affiche la valeur de la constante
	*/
	void Show();

	/**
	 * Surcharge de Fonction::Zero()
	 * @brief La valeur est-elle �gale � 0 ?
	*/
	bool Zero();

	/**
	 * Surcharge de Fonction::Un()
	 * @brief La valeur est-elle �gale � 1 ?
	*/
	bool Un();

	/**
	 * Surcharge de Fonction::Constante()
	 * @brief Retourne toujours vrai
	*/
	bool Constant();
};
#endif

