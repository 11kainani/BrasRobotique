#pragma once

#include "FonctionMath.h"
#include "FonctionSin.h"

class FonctionCos : public FonctionMath
{

public:


	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	FonctionCos();

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	FonctionCos(FonctionInterface& FONInterface);

	/**
	 * Surcharge de Fonction::
	 * @brief
	 * @param
	*/
	~FonctionCos();


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


