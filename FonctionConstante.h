#ifndef FONCTION_CONSTANTE_H
#define FONCTION_CONSTANTE_H
#include "Fonction.h"

/**
 * @brief Classe heritant de Fonction
 * Represente une valeur constante c
 */
class FonctionConstante : public Fonction
{
	double dValeur;

public:

	/**
	 * Constructeur par defaut
	 * @brief Cree un objet FonctionConstante dont la valeur est 0
	*/
	FonctionConstante();

	/**
	 * Contructeur de comfort
	 * @brief Cree un objet FonctionConstante avec une valeur donnee
	 * @param valeur
	*/
	FonctionConstante(double valeur);

	/**
	 * Destructeur
	 * @brief Detruis l'objet FonctionConstante
	*/
	~FonctionConstante();


	/**
	 * Surcharge de Fonction::Result()
	 * @brief Retourne la valeur de la constante
	*/
	double Result();

	/**
	 * Surcharge de Fonction::Derive(double*)
	 * @brief Retourne un nouvel objet FonctionConstante egal a 0
	 * @param pdComposante
	*/
	Fonction* Derive(double* pdComposante);

	/**
	 * Surcharge de Fonction::Copy()
	 * @brief Retourne un nouvel objet FonctionConstante alloue en memoire avec la meme valeur
	*/
	Fonction* Copy();


	/**
	 * Surcharge de Fonction::Show()
	 * @brief Affiche la valeur de la constante
	*/
	void Show();

	/**
	 * Surcharge de Fonction::Zero()
	 * @brief La valeur est-elle egale a 0 ?
	*/
	bool Zero();

	/**
	 * Surcharge de Fonction::Un()
	 * @brief La valeur est-elle egale a 1 ?
	*/
	bool Un();

	/**
	 * Surcharge de Fonction::Constante()
	 * @brief Retourne toujours vrai
	*/
	bool Constant();
};
#endif

