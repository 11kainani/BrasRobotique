#ifndef C_LECTEUR_H
#define C_LECTEUR_H

#include <iostream>
#include <assert.h>
#include <fstream>

#include "CLecteurBase.h"
#include "VariableArticulaire.h"

using std::ifstream;

class CLecteur : public CLecteurBase
{
private:

	VariableArticlaire* pVARListe; 		// Liste dynamique d'objet VariableArticulaire
	VariableArticulaire** ppVARVariables; 	// Liste dynamique de pointeurs d'objet VariableArticulaire
	unsigned int uiNbElements; 		// Nombre d'objets contenus dans pVARListe
	unsigned int uiNbVariables; 		// Nombre de pointeurs contenus dans ppVARVariables


public:
	CLecteur(char* pcCheminFichier);

	CLecteur();

	~CLecteur();

	unsigned int LireNbElements();
	
	unsigned int LireNbVariables();

	VariableArticulaire& LireElement(unsigned int uiIndice);
	
	VariableArticulaire& LireVariable(unsigned int uiIndice);

	// bool LECFindElement(char* pcLigne, char* pccMot);

	// int LECFindColonneEtLigne(char* pcPhrase);

	void LireFichier();

	void ModifierFichier(const char* pcFichier);

};
#endif
