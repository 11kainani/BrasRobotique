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
	pfMATElement = nullptr;
	uiMATNbColonne = 0;
	uiMATNbLigne = 0;
}

CMatriceBase::CMatriceBase(const CMatriceBase& MATObjet)
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
	uiMATNbColonne = 0;
	uiMATNbLigne = 0;

	

}

unsigned int CMatriceBase::MATLireNbColonne()
{
	return uiMATNbColonne;
}

unsigned int CMatriceBase::MATLireNbLigne()
{
	return uiMATNbLigne;
}

float CMatriceBase::MATLireElement(unsigned int uiLigne, unsigned int uiColonne)

{
	CException EXCObjet;
	if (uiLigne < 0 || uiLigne >= uiMATNbLigne)
	{
		// Exception Ligne invalide
		cout << "Erreur : Ligne " << uiLigne << " invalide (0 <= uiLigne < nombre de lignes de la matrice)" << endl;
		EXCObjet.EXCModifierValeur(EXC1);
		throw EXCObjet;
	}

	if (uiColonne < 0 || uiColonne >= uiMATNbColonne)
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
	if (pfMATElement)
	{
		if (pfMATElement == NULL)
		{
			cout << "Erreur\n";
		}

		for (uiBoucle = 0; uiBoucle < uiMATNbLigne * uiMATNbColonne; uiBoucle++)
		{
			pfMATElement[uiBoucle] = pfElements[uiBoucle];
		}
	}
	return;
}

void CMatriceBase::operator=(const CMatriceBase& MATObjet)
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

void CMatriceBase::MATModiferElement(unsigned int indiceLigne, unsigned int indiceColonne, float element)
{
	CException mistake;
	unsigned int indice = indiceLigne * uiMATNbColonne + indiceColonne;
	if (uiMATNbColonne * uiMATNbLigne <= indice)
	{
		mistake.EXCModifierValeur(EXC3);
		throw mistake;

	}

	pfMATElement[indice] = element;
}

void CMatriceBase::MATModifierNbLignes(unsigned int number)
{
	uiMATNbLigne = number;
}

void CMatriceBase::MATModifierNbColonnes(unsigned int number)
{
	uiMATNbColonne = number;
}

void CMatriceBase::MATReallocMatrice(unsigned int element)
{
	CException mistake;

	//S'occuper des cas d'erreur
	unsigned int uiboucle, uiboucle2;
	float* resultat = (float*)malloc(sizeof(float)*uiMATNbColonne*uiMATNbLigne + sizeof(float) * element);

	if (resultat)
	{
		if (resultat == nullptr)
			{
				cout << "bleuk";
			}
			else
			{

				for (uiboucle = 0; uiboucle < uiMATNbLigne; uiboucle++)
				{
					for (uiboucle2 = 0; uiboucle2 <uiMATNbLigne; uiboucle2++)
					{
						resultat[uiboucle * uiMATNbColonne + uiboucle2]=pfMATElement[uiboucle*uiMATNbColonne+uiboucle2];
					}
				}
			}
		free(pfMATElement);
		pfMATElement = resultat;
	}
	
	

	
	
	

}

