#ifndef FONCTION_SINCOS_H
#define FONCTION_SINCOS_H

#include "FonctionMath.h"
#include "FonctionCos.h"

/**
 * Classe héritant de FonctionMath
 * Représente une fonction f(g) = sin(g)  où g est une formule mathématique quelconque
 */
class FonctionSin : public FonctionMath
{
public:


	/**
	 * Constructeur par défaut
	 * @brief Crée un objet vide
	*/
	FonctionSin();

	/**
	 * Constructeur de comfort
	 * @brief Crée l'objet et initialise par délégation son objet FonctionInterface
	 * @param FONInterface : Objet dont la formule sera récupérée par délégation
	*/
	FonctionSin(FonctionInterface& FONInterface);

	/**
	 * Constructeur de déplacement
	 * @brief Crée l'objet et initialise par délégation son objet FonctionInterface
	 * @param FONInterface : Objet temporaire dont la formule sera récupérée
	*/
	FonctionSin(FonctionInterface&& FONInterface);

	/**
	 * Destructeur
	 * @brief Appel le destructeur de FonctionMath
	*/
	~FonctionSin();


	/**
	 * Surcharge de Fonction::Result()
	 * @brief Retourne le résultat de f(g) = sin(g)
	*/
	double Result();

	/**
	 * Surcharge de Fonction::Derive(double*)
	 * @brief Alloue la dérivé de f(g) = sin(g) soit une fonction produit cos(g)*g'
	 * @param pdComposant : adresse de la variable de dérivation
	*/
	Fonction* Derive(double* pdComposant);

	/**
	 * Surcharge de Fonction::Copy()
	 * @brief Retourne un objet FonctionSin alloué et dont son objet FONInterface pointe la même formule g
	*/
	Fonction* Copy();


	/**
	 * Surcharge de Fonction::Show()
	 * @brief Affiche la formule sin(g) où g est une formule quelconque
	*/
	void Show();

	/**
	 * Surcharge de Fonction::Zero()
	 * @brief Retourne vrai si son objet FonctionInterface vaut constamment 0
	*/
	bool Zero();

	/**
	 * Surcharge de Fonction::Un()
	 * @brief Retourne vrai si son objet FONInterface vaut constamment PI/2 + k*2*PI
	*/
	bool Un();
};
#endif


