#ifndef C_MATRICE_H
#define C_MATRICE_H

#include <iostream>
#include <assert.h>
#include <fstream>
#include "CMatriceBase.h"
#include "CException.h"

class CMatrice : public CMatriceBase
{
public:
	/**
	* Constructeur de confort
	 * @brief Création et initialisation d'un objet CMatrice en appelant le constructeur de recopie de CMatriceBase
	 * @param uiLignes 
	 * @param uiColonnes 
	 * @param pfElements 
	*/
	CMatrice(unsigned int uiLignes, unsigned int uiColonnes, float *pfElements = nullptr);

	/**
	* Constructeur 
	 * @brief 
	*/
	CMatrice();

	CMatrice(CMatrice& MATObjet);

	CMatrice& MATTranspose();

	CMatrice& operator*(CMatriceBase MATObjet);

	bool MATIsEmpty();

	CMatrice& operator-(CMatriceBase MATObjet);

	CMatrice& operator*(double dValeur);

	CMatrice operator/(double dValeur);

	CMatrice& operator+(CMatriceBase MATObjet);

	CMatrice& Greville();

	~CMatrice();

	CMatrice& MATFromColonne( unsigned int numColonne);

	static CMatrice& MATIdentity(unsigned int nbLignes, unsigned int nbColonnes);

};
#endif
