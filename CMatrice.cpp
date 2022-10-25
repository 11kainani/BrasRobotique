#include <iostream>
#include <assert.h>
#include <fstream>

#include "CMatrice.h"

CMatrice Exe;

CMatrice::CMatrice(unsigned int uiLignes, unsigned int uiColonnes, int pTElements)
{
}

CMatrice::CMatrice()
{
}

CMatrice::CMatrice(CMatrice& MATObjet)
{
}

CMatrice CMatrice::MATTranspose()
{
	return Exe ;
}

CMatrice CMatrice::operator*(double dValeur)
{
	return Exe;
}

CMatrice CMatrice::operator*(CMatriceBase MATObjet)
{
	return Exe;
}

CMatrice CMatrice::Greville(CMatrice MATObjet)
{
	return Exe;
}
