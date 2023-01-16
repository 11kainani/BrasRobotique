#ifndef FONCTION_MATH_H
#define FONCTION_MATH_H

#include "FonctionProduit.h"
//* #include <math.h>
#include <cmath>

#define PI 3.14159265

/**
 * @brief  Classe heritant de Fonction
 * Represente une fonction f(g)  ou g est une formule mathematique quelconque
 */
class FonctionMath : public Fonction
{
protected:
	FonctionInterface FONInterface;  // Formule mathematique g quelconque

public:

	/**
	 * Constructeur par defaut
	 * @brief Cree un objet vide
	*/
	FonctionMath();

	/**
	 * Constructeur de comfort
	 * @brief Cree l'objet FonctionMath et initialise son objet FonctionInterface par delegation
	 * @param FONInterface : Objet dont la formule sera recupere par delegation
	*/
	FonctionMath(FonctionInterface& FONInterface);

	/**
	 * Constructeur de recopie
	 * @brief Cree l'objet FonctionMath et son objet FonctionInterface pointe la meme formule g que FONMath.FONInterface
	 * @param FONMath : Objet a copier
	*/
	FonctionMath(FonctionMath& FONMath);

	/**
	 * Destructeur 
	 * @brief Detruis l'objet FONInterface puis l'objet FonctionMath
	*/
	~FonctionMath();


	/**
	 * Surcharge de l'operateur =
	 * @brief Affecte FONInterface pour pointer la meme formule g que FONMath.FONInterface
	 * @param FONMath : Objet a copier
	*/
	FonctionMath& operator=(FonctionMath& FONMath);

	/**
	 * Surcharge de Fonction::Constant()
	 * @brief Retourne vrai si l'objet FONInterface est constant
	*/
	bool Constant();

};
#endif

