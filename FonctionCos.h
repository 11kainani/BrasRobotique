#pragma once

#include "FonctionMath.h"
#include "FonctionSin.h"

/**
 * @brief Classe heritant de FonctionMath
 * Represente une fonction f(g) = cos(g)  ou g est une formule mathematique quelconque
 */
class FonctionCos : public FonctionMath
{

public:


	/**
	 * Constructeur par defaut
	 * @brief Cree un objet vide
	*/
	FonctionCos();

	/**
	 * Constructeur de comfort
	 * @brief Cree l'objet et initialise par delegation son objet FonctionInterface 
	 * @param FONInterface : Objet dont la formule sera recuperee par delegation
	*/
	FonctionCos(FonctionInterface& FONInterface);

	/**
	 * Constructeur de deplacement
	 * @brief Cree l'objet et initialise par delegation son objet FonctionInterface
	 * @param FONInterface : Objet temporaire dont la formule sera recuperee
	*/
	FonctionCos(FonctionInterface&& FONInterface);

	/**
	 * Destructeur
	 * @brief Appel le destructeur de FonctionMath
	*/
	~FonctionCos();


	/**
	 * Surcharge de Fonction::Result()
	 * @brief Retourne le resultat de f(g) = cos(g)
	*/
	double Result();

	/**
	 * Surcharge de Fonction::Derive(double*)
	 * @brief Retourne la derive de f(g) = cos(g) soit une fonction produit -1*sin(g)*g'
	 * @param pdComposant : adresse de la variable de derivation
	*/
	Fonction* Derive(double* pdComposant);

	/**
	 * Surcharge de Fonction::Copy()
	 * @brief Retourne un objet FonctionCos alloue et dont son objet FONInterface pointe la meme formule g
	*/
	Fonction* Copy();


	/**
	 * Surcharge de Fonction::Show()
	 * @brief Affiche la formule cos(g) ou g est une formule quelconque
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


