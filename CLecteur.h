#ifndef C_LECTEUR_H
#define C_LECTEUR_H

#include <iostream>
#include <fstream>

#include "CLecteurBase.h"
#include "VariableArticulaire.h"
#include "DenavitParameter.h"

using std::ifstream;
using namespace std;

class CLecteur : public CLecteurBase
{
private:

	VariableArticulaire* pVARListe; 		// Liste dynamique d'objet VariableArticulaire
	VariableArticulaire** ppVARVariables; 	// Liste dynamique de pointeurs d'objet VariableArticulaire
	DenavitParameter* pDENParametres; 	// Liste dynamique de paramètres de Denavit
	unsigned int uiNbElements; 		// Nombre d'objets contenus dans pVARListe
	unsigned int uiNbVariables; 		// Nombre de pointeurs contenus dans ppVARVariables
	unsigned int uiNbParametres;		// Nombre de paramètres de Denavit dans pDENParametres



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
