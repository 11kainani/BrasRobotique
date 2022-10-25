#ifndef C_MATRICE_H
#define C_MATRICE_H

#include <iostream>
#include <assert.h>
#include <fstream>

#include "CMatriceExtension.h"
#include "CMatriceBase.h"

class CMatrice : public CMatriceExtension
{
public:
	CMatrice(unsigned int uiLignes, unsigned int uiColonnes, int pTElements);

	CMatrice();

	CMatrice(CMatrice& MATObjet);

	CMatrice MATTranspose();
	
	CMatrice operator*(double dValeur);

	CMatrice operator*(CMatriceBase MATObjet);

	CMatrice Greville(CMatrice MATObjet);

};
#endif
