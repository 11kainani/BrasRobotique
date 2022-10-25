#include <iostream>
#include <assert.h>
#include <fstream>

#include "CLecteur.h"


CMatrice mis;

CLecteur::CLecteur(char* ppcCheminFichier)
{
}

CLecteur::CLecteur()
{
}

CLecteur::~CLecteur()
{
}

CMatrice CLecteur::LECLireNbMatrice()
{
	return mis;
}

unsigned int& CLecteur::LECLireMatrice(unsigned int uiIndice)
{
	return *(new unsigned int());
}

bool CLecteur::LECFindElement(char* pcLigne, char* pccMot)
{
	return false;
}

int CLecteur::LECFindColonneEtLigne(char* pcPhrase)
{
	return 0;
}

int& CLecteur::LECLireFichier()
{
	return *(new int());
}

void CLecteur::LECModifierFichier(const char* pcFichier)
{
}
