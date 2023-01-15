#ifndef FONCTION_MATH_H
#define FONCTION_MATH_H

#include "FonctionProduit.h"
//* #include <math.h>
#include <cmath>

#define PI 3.14159265

/**
 * Classe héritant de Fonction
 * Représente une fonction f(g)  où g est une formule mathématique quelconque
 */
class FonctionMath : public Fonction
{
protected:
	FonctionInterface FONInterface;  // Formule mathématique g quelconque

public:

	/**
	 * Constructeur par défaut
	 * @brief Crée un objet vide
	*/
	FonctionMath();

	/**
	 * Constructeur de comfort
	 * @brief Crée l'objet FonctionMath et initialise son objet FonctionInterface par délégation
	 * @param FONInterface : Objet dont la formule sera récupéré par délégation
	*/
	FonctionMath(FonctionInterface& FONInterface);

	/**
	 * Constructeur de recopie
	 * @brief Crée l'objet FonctionMath et son objet FonctionInterface pointe la même formule g que FONMath.FONInterface
	 * @param FONMath : Objet à copier
	*/
	FonctionMath(FonctionMath& FONMath);

	/**
	 * Destructeur 
	 * @brief Détruis l'objet FONInterface puis l'objet FonctionMath
	*/
	~FonctionMath();


	/**
	 * Surcharge de l'opérateur =
	 * @brief Affecte FONInterface pour pointer la même formule g que FONMath.FONInterface
	 * @param FONMath : Objet à copier
	*/
	FonctionMath& operator=(FonctionMath& FONMath);

	/**
	 * Surcharge de Fonction::Constant()
	 * @brief Retourne vrai si l'objet FONInterface est constant
	*/
	bool Constant();

};
#endif

