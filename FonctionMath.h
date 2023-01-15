#ifndef FONCTION_MATH_H
#define FONCTION_MATH_H

#include "FonctionProduit.h"
//* #include <math.h>
#include <cmath>

#define PI 3.14159265

/**
 * Classe h�ritant de Fonction
 * Repr�sente une fonction f(g)  o� g est une formule math�matique quelconque
 */
class FonctionMath : public Fonction
{
protected:
	FonctionInterface FONInterface;  // Formule math�matique g quelconque

public:

	/**
	 * Constructeur par d�faut
	 * @brief Cr�e un objet vide
	*/
	FonctionMath();

	/**
	 * Constructeur de comfort
	 * @brief Cr�e l'objet FonctionMath et initialise son objet FonctionInterface par d�l�gation
	 * @param FONInterface : Objet dont la formule sera r�cup�r� par d�l�gation
	*/
	FonctionMath(FonctionInterface& FONInterface);

	/**
	 * Constructeur de recopie
	 * @brief Cr�e l'objet FonctionMath et son objet FonctionInterface pointe la m�me formule g que FONMath.FONInterface
	 * @param FONMath : Objet � copier
	*/
	FonctionMath(FonctionMath& FONMath);

	/**
	 * Destructeur 
	 * @brief D�truis l'objet FONInterface puis l'objet FonctionMath
	*/
	~FonctionMath();


	/**
	 * Surcharge de l'op�rateur =
	 * @brief Affecte FONInterface pour pointer la m�me formule g que FONMath.FONInterface
	 * @param FONMath : Objet � copier
	*/
	FonctionMath& operator=(FonctionMath& FONMath);

	/**
	 * Surcharge de Fonction::Constant()
	 * @brief Retourne vrai si l'objet FONInterface est constant
	*/
	bool Constant();

};
#endif

