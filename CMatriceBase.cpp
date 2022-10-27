#include <iostream>
#include <assert.h>
#include <fstream>

#include "CMatriceBase.h"
#include <assert.h>
#include "CException.h"
using namespace std;
#define EXC1 1
#define EXC2 2
#define EXC3 3


/**
Constructeur par default 
entre : néant
necessite: neant
sortie : neant 
initialisation d'un objet matrice
**/

CMatriceBase::CMatriceBase()
{
	return;
}

CMatriceBase::CMatriceBase(CMatriceBase& MATObjet)
{
	unsigned int uiBoucle;

	uiMATNbLigne = MATObjet.uiMATNbLigne;
	uiMATNbColonne = MATObjet.uiMATNbColonne;

	pfMATElement = (float*)malloc(uiMATNbLigne * uiMATNbColonne * sizeof(float));
	if (pfMATElement == NULL)
	{
		cout << "Erreur\n";
	}

	for (uiBoucle = 0; uiBoucle < uiMATNbLigne * uiMATNbColonne; uiBoucle++)
	{
		pfMATElement[uiBoucle] = MATObjet.pfMATElement[uiBoucle]; // Recopie l'élément du tableau
	}
	return;
}

CMatriceBase::~CMatriceBase()
{
	if (pfMATElement != NULL)
	{
		free(pfMATElement);
	}

}

unsigned int CMatriceBase::MATLireNbColonne()
{
	return uiMATNbLigne;
}

unsigned int CMatriceBase::MATLireNbLigne()
{
	return uiMATNbLigne;
}

float CMatriceBase::MATLireElement(unsigned int uiLigne, unsigned int uiColonne)
{
	CException EXCObjet;
	if (uiLigne < 0 || uiLigne > uiMATNbLigne)
	{
		// Exception Ligne invalide
		cout << "Erreur : Ligne " << uiLigne << " invalide (0 <= uiLigne < nombre de lignes de la matrice)" << endl;
		EXCObjet.EXCModifierValeur(EXC1);
		throw EXCObjet;
	}

	if (uiColonne < 0 || uiColonne > uiMATNbColonne)
	{
		// Exception Colonne invalide
		cout << "Erreur : Colonne " << uiColonne << " invalide (0 <= uiColonne < nombre de colonnes de la matrice)" << endl;
		EXCObjet.EXCModifierValeur(EXC2);
		throw EXCObjet;
	}


	return pfMATElement[uiLigne * uiMATNbColonne + uiColonne];
}

void CMatriceBase::MATAffiche()
{
	// Affiche

	//Erreur de parcours de chaine, la matrice s'affiche transposé donc j'ai modifié le code pour contrer cela
	unsigned int uiBoucleLigne;
	unsigned int uiBoucleColonne;

	cout << MATLireNbLigne() << "x" << MATLireNbColonne() << endl;
	if (uiMATNbLigne == uiMATNbColonne && uiMATNbColonne == 0)
	{
		cout << "Matrice vide" << endl;
		return;
	}

	for (uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
	{
		for (uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
		{
			cout << pfMATElement[uiBoucleLigne * uiMATNbColonne + uiBoucleColonne] << " ";
		}
		cout << endl;
	}
	return;
}

CMatriceBase::CMatriceBase(unsigned int uiLignes, unsigned int uiColonnes, float* pfElements)
{
	unsigned int uiBoucle;

	uiMATNbLigne = uiLignes;
	uiMATNbColonne = uiColonnes;
	pfMATElement = (float*)malloc(uiMATNbLigne * uiMATNbColonne * sizeof(float));
	
	if (pfMATElement == NULL)
	{
		cout << "Erreur\n";
	}

	for (uiBoucle = 0; uiBoucle < uiMATNbLigne * uiMATNbColonne; uiBoucle++)
	{
		pfMATElement[uiBoucle] = pfElements[uiBoucle]; 
	}

	return;
}

void CMatriceBase::operator=(CMatriceBase& MATObjet)
{
	unsigned int uiBoucle;
	uiMATNbLigne = MATObjet.uiMATNbLigne;
	uiMATNbColonne = MATObjet.uiMATNbColonne;
	if (pfMATElement != NULL)
	{
		free(pfMATElement);
	}

	pfMATElement = (float*)malloc(uiMATNbLigne * uiMATNbColonne * sizeof(float));
	if (pfMATElement == NULL)
	{
		cout << "Erreur\n";
	}

	for (uiBoucle = 0; uiBoucle < uiMATNbLigne * uiMATNbColonne; uiBoucle++)
	{
		pfMATElement[uiBoucle] = MATObjet.pfMATElement[uiBoucle]; // Recopie l'élément du tableau
	}
}
