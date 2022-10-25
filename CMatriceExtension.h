#ifndef C_MATRICE_EXTENSION_H
#define C_MATRICE_EXTENSION_H

#include <iostream>
#include <assert.h>
#include <fstream>

#include "CMatriceBase.h"

class CMatriceExtension : public CMatriceBase
{
public:
	CMatriceExtension(CMatriceExtension& MATObjet);

	CMatriceExtension();

	CMatriceExtension(unsigned int uiLignes, unsigned int uiColonnes, int* pTElements);

	bool MATIsEmpty();

	CMatriceExtension& operator-(CMatriceBase MATObjet);

	CMatriceExtension& operator*(double dValeur);

	CMatriceExtension operator/(double dValeur);

	CMatriceExtension& operator+(CMatriceBase MATObjet);

};
#endif
