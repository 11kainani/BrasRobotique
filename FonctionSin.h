#ifndef FONCTION_SINCOS_H
#define FONCTION_SINCOS_H

#include "FonctionMath.h"
#include "FonctionCos.h"

class FonctionSin : public FonctionMath
{
public:


	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	FonctionSin();

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	FonctionSin(FonctionInterface& FONInterface);

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	FonctionSin(FonctionInterface&& FONInterface);

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	~FonctionSin();


	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	double Result();

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	Fonction* Derive(double* pdComposant);

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	Fonction* Copy();


	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	void Show();

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	bool Zero();

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	bool Un();
};
#endif


