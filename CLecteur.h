#ifndef C_LECTEUR_H
#define C_LECTEUR_H

#include <iostream>
#include <fstream>

#include "CLecteurBase.h"
#include "VariableArticulaire.h"
#include "DenavitParameter.h"


#define PI 3.14159265


using std::ifstream;
using namespace std;

#define EXC_NB_PARAMS_MANQUANT 1
#define EXC_NB_PARAMS_NEGATIF 2
#define EXC_VARIABLE_X_ABSENTE 3
#define EXC_VARIABLE_MIN 4
#define EXC_VARIABLE_MAX 5
#define EXC_PARAMETRE_INCOMPLET 6

class CLecteur : public CLecteurBase
{
private:

	VariableArticulaire* pVARListe; 		// Liste dynamique d'objet VariableArticulaire
	VariableArticulaire** ppVARVariables; 	// Liste dynamique de pointeurs d'objet VariableArticulaire
	DenavitParameter* pDENParametres; 	// Liste dynamique de param�tres de Denavit
	unsigned int uiNbElements; 		// Nombre d'objets contenus dans pVARListe
	unsigned int uiNbVariables; 		// Nombre de pointeurs contenus dans ppVARVariables
	unsigned int uiNbParametres;		// Nombre de param�tres de Denavit dans pDENParametres



public:
	CLecteur(const char* pcCheminFichier);

	CLecteur();

	~CLecteur();

	unsigned int LireNbElements();

	unsigned int LireNbVariables();

	unsigned int LireNbParametres();

	VariableArticulaire& LireElement(unsigned int uiIndice);

	VariableArticulaire& LireVariable(unsigned int uiIndice);

	DenavitParameter& LireParametre(unsigned int uiIndice);

	// bool LECFindElement(char* pcLigne, char* pccMot);

	// int LECFindColonneEtLigne(char* pcPhrase);

	void LireFichier();

	void ModifierFichier(const char* pcFichier);

};
#endif
