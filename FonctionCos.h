#pragma once

#include "FonctionMath.h"
#include "FonctionSin.h"

/**
 * Classe h�ritant de FonctionMath
 * Repr�sente une fonction f(g) = cos(g)  o� g est une formule math�matique quelconque
 */
class FonctionCos : public FonctionMath
{

public:


	/**
	 * Constructeur par d�faut
	 * @brief Cr�e un objet vide
	*/
	FonctionCos();

	/**
	 * Constructeur de comfort
	 * @brief Cr�e l'objet et initialise par d�l�gation son objet FonctionInterface 
	 * @param FONInterface : Objet dont la formule sera r�cup�r�e par d�l�gation
	*/
	FonctionCos(FonctionInterface& FONInterface);

	/**
	 * Constructeur de d�placement
	 * @brief Cr�e l'objet et initialise par d�l�gation son objet FonctionInterface
	 * @param FONInterface : Objet temporaire dont la formule sera r�cup�r�e
	*/
	FonctionCos(FonctionInterface&& FONInterface);

	/**
	 * Destructeur
	 * @brief Appel le destructeur de FonctionMath
	*/
	~FonctionCos();


	/**
	 * Surcharge de Fonction::Result()
	 * @brief Retourne le r�sultat de f(g) = cos(g)
	*/
	double Result();

	/**
	 * Surcharge de Fonction::Derive(double*)
	 * @brief Retourne la d�riv� de f(g) = cos(g) soit une fonction produit -1*sin(g)*g'
	 * @param pdComposant : adresse de la variable de d�rivation
	*/
	Fonction* Derive(double* pdComposant);

	/**
	 * Surcharge de Fonction::Copy()
	 * @brief Retourne un objet FonctionCos allou� et dont son objet FONInterface pointe la m�me formule g
	*/
	Fonction* Copy();


	/**
	 * Surcharge de Fonction::Show()
	 * @brief Affiche la formule cos(g) o� g est une formule quelconque
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


