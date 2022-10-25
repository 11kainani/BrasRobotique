#ifndef C_MATRICE_BASE_H
#define C_MATRICE_BASE_H

#include <iostream>
#include <assert.h>
#include <fstream>

class CMatriceBase
{
private:
	unsigned int uiMATNbLigne;

	unsigned int uiMATNbColonne;

	float* pfMATElement;


public:
	CMatriceBase() ;

	CMatriceBase(CMatriceBase& MATObjet);

	~CMatriceBase();

	unsigned int MATLireNbColonne();

	unsigned int MATLireNbLigne();

	int MATLireElement(unsigned int uiLigne, unsigned int uiColonne);

	void MATAffiche();

	CMatriceBase(unsigned int uiLignes, unsigned int uiColonnes, int* pTElements);

	void operator=(CMatriceBase& MATObjet);

};
#endif
