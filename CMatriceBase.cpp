#include <iostream>
#include <fstream>

#include "CMatriceBase.h"
#include "CException.h"
using namespace std;
#define EXC1 1
#define EXC2 2
#define EXC3 3


/**
Constructeur par default
entre : n�ant
necessite: neant
sortie : neant
initialisation d'un objet matrice
**/

CMatriceBase::CMatriceBase()
{
	pdMATElement = nullptr;
	uiMATNbColonne = 0;
	uiMATNbLigne = 0;
}

CMatriceBase::CMatriceBase(const CMatriceBase& MATObjet)
{
	unsigned int uiBoucle;

	uiMATNbLigne = MATObjet.uiMATNbLigne;
	uiMATNbColonne = MATObjet.uiMATNbColonne;

	pdMATElement = (double*)malloc(uiMATNbLigne * uiMATNbColonne * sizeof(double));
	if (pdMATElement == NULL)
	{
		cout << "Erreur\n";
	}

	for (uiBoucle = 0; uiBoucle < uiMATNbLigne * uiMATNbColonne; uiBoucle++)
	{
		pdMATElement[uiBoucle] = MATObjet.pdMATElement[uiBoucle]; // Recopie l'�l�ment du tableau
	}
	return;
}

CMatriceBase::~CMatriceBase()
{
	if (pdMATElement != NULL)
	{
		free(pdMATElement);
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

double CMatriceBase::MATLireElement(unsigned int uiLigne, unsigned int uiColonne)

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


	return pdMATElement[uiLigne * uiMATNbColonne + uiColonne];
}

void CMatriceBase::MATAffiche()
{
	// Affiche

	//Erreur de parcours de chaine, la matrice s'affiche transpos� donc j'ai modifi� le code pour contrer cela
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
			cout << pdMATElement[uiBoucleLigne * uiMATNbColonne + uiBoucleColonne] << "\t";
		}
		cout << endl;
	}
	return;
}

CMatriceBase::CMatriceBase(unsigned int uiLignes, unsigned int uiColonnes, double* pfElements)
{
	unsigned int uiBoucle;

	uiMATNbLigne = uiLignes;
	uiMATNbColonne = uiColonnes;
	pdMATElement = (double*)malloc(uiMATNbLigne * uiMATNbColonne * sizeof(double));
	if (pdMATElement)
	{
		if (pdMATElement == NULL)
		{
			cout << "Erreur\n";
		}

		for (uiBoucle = 0; uiBoucle < uiMATNbLigne * uiMATNbColonne; uiBoucle++)
		{
			pdMATElement[uiBoucle] = pfElements[uiBoucle];
		}
	}
	return;
}

void CMatriceBase::operator=(const CMatriceBase& MATObjet)
{
	unsigned int uiBoucle;
	uiMATNbLigne = MATObjet.uiMATNbLigne;
	uiMATNbColonne = MATObjet.uiMATNbColonne;
	if (pdMATElement != NULL)
	{
		free(pdMATElement);
	}

	pdMATElement = (double*)malloc(uiMATNbLigne * uiMATNbColonne * sizeof(double));
	if (pdMATElement == NULL)
	{
		cout << "Erreur\n";
	}

	for (uiBoucle = 0; uiBoucle < uiMATNbLigne * uiMATNbColonne; uiBoucle++)
	{
		pdMATElement[uiBoucle] = MATObjet.pdMATElement[uiBoucle]; // Recopie l'�l�ment du tableau
	}
}

void CMatriceBase::MATModiferElement(unsigned int indiceLigne, unsigned int indiceColonne, double element)
{
	CException mistake;
	unsigned int indice = indiceLigne * uiMATNbColonne + indiceColonne;
	if (uiMATNbColonne * uiMATNbLigne <= indice)
	{
		mistake.EXCModifierValeur(EXC3);
		throw mistake;

	}

	pdMATElement[indice] = element;
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
	double* resultat = (double*)malloc(sizeof(double)*uiMATNbColonne*uiMATNbLigne + sizeof(double) * element);

	if (resultat)
	{
		if (resultat == nullptr)
		{
			mistake.EXCModifierValeur(EXC3);
				throw mistake;
		}
		else
		{

			for (uiboucle = 0; uiboucle < uiMATNbLigne; uiboucle++)
			{
				for (uiboucle2 = 0; uiboucle2 < uiMATNbColonne; uiboucle2++)
				{
					resultat[uiboucle * uiMATNbColonne + uiboucle2] = pdMATElement[uiboucle*uiMATNbColonne + uiboucle2];
				}
			}
		}
		free(pdMATElement);
		pdMATElement = resultat;
	}







}
