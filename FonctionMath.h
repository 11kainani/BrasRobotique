#ifndef FONCTION_MATH_H
#define FONCTION_MATH_H

#include "FonctionProduit.h"
//* #include <math.h>
#include <cmath>

#define PI 3.14159265

class FonctionMath : public Fonction
{
protected:
	FonctionInterface FONInterface;

public:

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	FonctionMath();

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	FonctionMath(FonctionInterface& FONInterface);

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	FonctionMath(FonctionMath& FONCopie);

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	~FonctionMath();


	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	FonctionMath& operator=(FonctionMath& FONMath);

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	bool Constant();

};
#endif

