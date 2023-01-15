#ifndef FONCTION_SINCOS_H
#define FONCTION_SINCOS_H

#include "FonctionMath.h"
#include "FonctionCos.h"

/**
 * Classe h�ritant de FonctionMath
 * Repr�sente une fonction f(g) = sin(g)  o� g est une formule math�matique quelconque
 */
class FonctionSin : public FonctionMath
{
public:


	/**
	 * Constructeur par d�faut
	 * @brief Cr�e un objet vide
	*/
	FonctionSin();

	/**
	 * Constructeur de comfort
	 * @brief Cr�e l'objet et initialise par d�l�gation son objet FonctionInterface
	 * @param FONInterface : Objet dont la formule sera r�cup�r�e par d�l�gation
	*/
	FonctionSin(FonctionInterface& FONInterface);

	/**
	 * Constructeur de d�placement
	 * @brief Cr�e l'objet et initialise par d�l�gation son objet FonctionInterface
	 * @param FONInterface : Objet temporaire dont la formule sera r�cup�r�e
	*/
	FonctionSin(FonctionInterface&& FONInterface);

	/**
	 * Destructeur
	 * @brief Appel le destructeur de FonctionMath
	*/
	~FonctionSin();


	/**
	 * Surcharge de Fonction::Result()
	 * @brief Retourne le r�sultat de f(g) = sin(g)
	*/
	double Result();

	/**
	 * Surcharge de Fonction::Derive(double*)
	 * @brief Alloue la d�riv� de f(g) = sin(g) soit une fonction produit cos(g)*g'
	 * @param pdComposant : adresse de la variable de d�rivation
	*/
	Fonction* Derive(double* pdComposant);

	/**
	 * Surcharge de Fonction::Copy()
	 * @brief Retourne un objet FonctionSin allou� et dont son objet FONInterface pointe la m�me formule g
	*/
	Fonction* Copy();


	/**
	 * Surcharge de Fonction::Show()
	 * @brief Affiche la formule sin(g) o� g est une formule quelconque
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


