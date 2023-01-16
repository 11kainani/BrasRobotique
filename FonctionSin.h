#ifndef FONCTION_SINCOS_H
#define FONCTION_SINCOS_H

#include "FonctionMath.h"
#include "FonctionCos.h"

/**
 * @brief Classe heritant de FonctionMath
 * Represente une fonction f(g) = sin(g)  ou g est une formule mathematique quelconque
 */
class FonctionSin : public FonctionMath
{
public:


	/**
	 * Constructeur par defaut
	 * @brief Cree un objet vide
	*/
	FonctionSin();

	/**
	 * Constructeur de comfort
	 * @brief Cree l'objet et initialise par delegation son objet FonctionInterface
	 * @param FONInterface : Objet dont la formule sera recuperee par delegation
	*/
	FonctionSin(FonctionInterface& FONInterface);

	/**
	 * Constructeur de deplacement
	 * @brief Cree l'objet et initialise par delegation son objet FonctionInterface
	 * @param FONInterface : Objet temporaire dont la formule sera recuperee
	*/
	FonctionSin(FonctionInterface&& FONInterface);

	/**
	 * Destructeur
	 * @brief Appel le destructeur de FonctionMath
	*/
	~FonctionSin();


	/**
	 * Surcharge de Fonction::Result()
	 * @brief Retourne le resultat de f(g) = sin(g)
	*/
	double Result();

	/**
	 * Surcharge de Fonction::Derive(double*)
	 * @brief Alloue la derive de f(g) = sin(g) soit une fonction produit cos(g)*g'
	 * @param pdComposant : adresse de la variable de derivation
	*/
	Fonction* Derive(double* pdComposant);

	/**
	 * Surcharge de Fonction::Copy()
	 * @brief Retourne un objet FonctionSin alloue et dont son objet FONInterface pointe la meme formule g
	*/
	Fonction* Copy();


	/**
	 * Surcharge de Fonction::Show()
	 * @brief Affiche la formule sin(g) ou g est une formule quelconque
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


