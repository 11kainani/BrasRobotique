#include <iostream>
#include <assert.h>
#include <fstream>

#include "CMatriceExtension.h"

CMatriceExtension mmis;

CMatriceExtension::CMatriceExtension(CMatriceExtension& MATObjet)
{
}

CMatriceExtension::CMatriceExtension()
{
}

CMatriceExtension::CMatriceExtension(unsigned int uiLignes, unsigned int uiColonnes, int* pTElements)
{
}

bool CMatriceExtension::MATIsEmpty()
{
	return false;
}

CMatriceExtension& CMatriceExtension::operator-(CMatriceBase MATObjet)
{
	return *this;
}

CMatriceExtension& CMatriceExtension::operator*(double dValeur)
{
	return *this;
}

CMatriceExtension CMatriceExtension::operator/(double dValeur)
{
	return mmis;
}

CMatriceExtension& CMatriceExtension::operator+(CMatriceBase MATObjet)
{
	return *this;
}
