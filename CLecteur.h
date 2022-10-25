#ifndef C_LECTEUR_H
#define C_LECTEUR_H

#include <iostream>
#include <assert.h>
#include <fstream>

#include "CLecteurBase.h"
#include "CMatrice.h"

using std::ifstream;

class CLecteur : public CLecteurBase
{
private:
	char** ppcLECCheminFichier;

	unsigned int uiLECNbrFichier;

	CMatrice* pMATLECListe;

	unsigned int uiLECnbMAtrice;

	char* pcLECFichier;


public:
	CLecteur(char* ppcCheminFichier);

	CLecteur();

	~CLecteur();

	CMatrice LECLireNbMatrice();

	unsigned int& LECLireMatrice(unsigned int uiIndice);

	bool LECFindElement(char* pcLigne, char* pccMot);

	int LECFindColonneEtLigne(char* pcPhrase);

	int& LECLireFichier();

	void LECModifierFichier(const char* pcFichier);

};
#endif
