#pragma once

#include "FonctionMath.h"
#include "FonctionSin.h"

/**
 * Classe héritant de FonctionMath
 * Représente une fonction f(g) = cos(g)  où g est une formule mathématique quelconque
 */
class FonctionCos : public FonctionMath
{

public:


	/**
	 * Constructeur par défaut
	 * @brief Crée un objet vide
	*/
	FonctionCos();

	/**
	 * Constructeur de comfort
	 * @brief Crée l'objet et initialise par délégation son objet FonctionInterface 
	 * @param FONInterface : Objet dont la formule sera récupérée par délégation
	*/
	FonctionCos(FonctionInterface& FONInterface);

	/**
	 * Constructeur de déplacement
	 * @brief Crée l'objet et initialise par délégation son objet FonctionInterface
	 * @param FONInterface : Objet temporaire dont la formule sera récupérée
	*/
	FonctionCos(FonctionInterface&& FONInterface);

	/**
	 * Destructeur
	 * @brief Appel le destructeur de FonctionMath
	*/
	~FonctionCos();


	/**
	 * Surcharge de Fonction::Result()
	 * @brief Retourne le résultat de f(g) = cos(g)
	*/
	double Result();

	/**
	 * Surcharge de Fonction::Derive(double*)
	 * @brief Retourne la dérivé de f(g) = cos(g) soit une fonction produit -1*sin(g)*g'
	 * @param pdComposant : adresse de la variable de dérivation
	*/
	Fonction* Derive(double* pdComposant);

	/**
	 * Surcharge de Fonction::Copy()
	 * @brief Retourne un objet FonctionCos alloué et dont son objet FONInterface pointe la même formule g
	*/
	Fonction* Copy();


	/**
	 * Surcharge de Fonction::Show()
	 * @brief Affiche la formule cos(g) où g est une formule quelconque
	*/
	void Show();

	/**
	 * Surcharge de Fonction::Zero()
	 * @brief Retourne vrai si son objet FONInterface vaut constamment PI/2 + k*PI
	*/
	bool Zero();

	/**
	 * Surcharge de Fonction::Un()
	 * @brief Retourne vrai si son objet FonctionInterface vaut constamment 0
	*/
	bool Un();
};


