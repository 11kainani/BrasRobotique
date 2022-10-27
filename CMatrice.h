#ifndef C_MATRICE_H
#define C_MATRICE_H

#include <iostream>
#include <assert.h>
#include <fstream>

#include "CMatriceExtension.h"
#include "CMatriceBase.h"
#include "CException.h"

class CMatrice : public CMatriceBase
{
public:
	CMatrice(unsigned int uiLignes, unsigned int uiColonnes, float *pfElements = nullptr);

	CMatrice();

	CMatrice(CMatrice& MATObjet);

	CMatrice MATTranspose();

	CMatrice& operator*(CMatriceBase MATObjet);

	bool MATIsEmpty();

	CMatrice& operator-(CMatriceBase MATObjet);

	CMatrice& operator*(double dValeur);

	CMatrice operator/(double dValeur);

	CMatrice& operator+(CMatriceBase MATObjet);

	CMatrice Greville(CMatrice MATObjet);

	~CMatrice();

};
#endif
