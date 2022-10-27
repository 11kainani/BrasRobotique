#include <iostream>
#include <assert.h>
#include <fstream>

#include "CMatrice.h"
#define OperationInfaisable 10
#define ERREUR_MATRICE_VIDE 6
#define DIVISION_PAR_ZERO 10
#define TAILLE_INCOMPATIBLE 11

using namespace std;

CMatrice Exe;

CMatrice::CMatrice(unsigned int uiLignes, unsigned int uiColonnes, float * pfElements) : CMatriceBase(uiLignes,uiColonnes,pfElements)
{
	
}

CMatrice::CMatrice() 
{
	return;
}

CMatrice::CMatrice(CMatrice& MATObjet) : CMatriceBase(MATObjet)
{
}

CMatrice CMatrice::MATTranspose()
{
	unsigned int uiBoucle;
	unsigned int uiLigne;
	unsigned int uiColonne;
	unsigned int uiNbLignes = this->MATLireNbLigne();
	unsigned int uiNbColonnes = this->MATLireNbColonne();
	float* pfElements = (float*)malloc(sizeof(float) * uiNbColonnes * uiNbLignes);
	float Element;

	// Transposition
	for (uiBoucle = 0; uiBoucle < uiNbLignes * uiNbColonnes; uiBoucle++)
	{
		uiLigne = uiBoucle % uiNbLignes; // Ligne de l'élément à échanger
		uiColonne = uiBoucle / uiNbLignes; // Colonne de l'élément à échanger
		Element = this->MATLireElement(uiLigne, uiColonne);

		cout << Element << " en position (" << uiLigne << ", " << uiColonne << ") >> ";
		pfElements[uiBoucle] = Element;
		cout << " (" << uiColonne << ", " << uiLigne << ")\n";

	}


	CMatrice MATResultat(uiNbColonnes, uiNbLignes, pfElements);
	free(pfElements);
	MATResultat.MATAffiche();
	return MATResultat; // Objet détruit
}


/**
 * @brief 
 * @param MATObjet 
 * @return pointeur sur matrice resultat
*/
CMatrice& CMatrice::operator*(CMatriceBase MATObjet)
{
	// Dimensions de la nouvelle matrice
	unsigned int uiNbLignes = this->MATLireNbLigne();
	unsigned int uiNbColonnes = MATObjet.MATLireNbColonne();
	unsigned int uiLigne;
	unsigned int uiColonne;

	// Sont égaux normalement sinon lancer une exception
	unsigned int uiLignes = MATObjet.MATLireNbLigne();
	unsigned int uiColonnes = this->MATLireNbColonne();

	float* pfElements = (float*)malloc(sizeof(float) * uiNbLignes * uiNbColonnes);
	float fElement;

	for (unsigned int uiBoucle = 0; uiBoucle < uiNbColonnes * uiNbLignes; uiBoucle++)
	{
		uiLigne = uiBoucle / uiNbColonnes;
		uiColonne = uiBoucle % uiNbColonnes;

		fElement = this->MATLireElement(uiLigne, 0) * MATObjet.MATLireElement(0, uiColonne);
		for (unsigned int uiBoucle2 = 1; uiBoucle2 < uiColonnes; uiBoucle2++)
		{
			fElement = fElement + this->MATLireElement(uiLigne, uiBoucle2) * MATObjet.MATLireElement(uiBoucle2, uiColonne);
		}
		pfElements[uiBoucle] = fElement;
	}
	
	CMatrice* pMATResultat = new CMatrice(uiNbLignes, uiNbColonnes, pfElements);
	free(pfElements);
	return *pMATResultat ; // pointeur détruit après retour par référence
}
/**
 * @brief 
 * @param MATObjet 
 * @return 
*/
CMatrice CMatrice::Greville(CMatrice MATObjet)
{
	return Exe;
}

CMatrice::~CMatrice()
{

}

bool CMatrice::MATIsEmpty()
{
	if (this->MATLireNbColonne() == 0 || this->MATLireNbLigne() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

CMatrice& CMatrice::operator-(CMatriceBase MATObjet)
{
	unsigned int uiCompteurLigne = 0; //itarateurs de boucles
	unsigned int uiCompteurColonne = 0; //itarateurs de boucles
	CException EXCObjet;

	if (this->MATLireNbColonne() != MATObjet.MATLireNbColonne() || this->MATLireNbLigne() != MATObjet.MATLireNbLigne())
	{
		EXCObjet.EXCModifierValeur(TAILLE_INCOMPATIBLE);
		std::cout << "Taille imcompatible";
		throw EXCObjet;
	}
	float* MATTableau = (float*)malloc(sizeof(float) * this->MATLireNbLigne() * this->MATLireNbColonne());

	for (uiCompteurLigne = 0; uiCompteurLigne < this->MATLireNbLigne(); uiCompteurLigne++)
	{
		for (uiCompteurColonne = 0; uiCompteurColonne < this->MATLireNbColonne(); uiCompteurColonne++)
		{
			MATTableau[uiCompteurLigne * this->MATLireNbLigne() + uiCompteurColonne] = this->MATLireElement(uiCompteurLigne, uiCompteurColonne) - MATObjet.MATLireElement(uiCompteurLigne, uiCompteurColonne);
		}

	}


	CMatrice* pMATResultatDifference = new CMatrice(uiCompteurLigne, uiCompteurColonne, MATTableau);

	return *pMATResultatDifference;
}

CMatrice& CMatrice::operator*(double dValeur)
{
	unsigned int uiCompteurLignes = 0; //Itérateur de boucles
	unsigned int uiCompteurColonne = 0; //Itérateur de boucles
	CException EXCObjet;
	float* MATTableau = (float*)malloc(sizeof(float) * this->MATLireNbLigne() * this->MATLireNbColonne());
	if (this->MATIsEmpty() == true)
	{
		EXCObjet.EXCModifierValeur(ERREUR_MATRICE_VIDE);
		std::cout << "La matrice est vide donc on ne peut pas faire l'operation";
		throw EXCObjet;
	}

	for (uiCompteurLignes = 0; uiCompteurLignes < this->MATLireNbLigne(); uiCompteurLignes++)
	{
		for (uiCompteurColonne = 0; uiCompteurColonne < this->MATLireNbColonne(); uiCompteurColonne++)
		{
			MATTableau[uiCompteurLignes * this->MATLireNbColonne() + uiCompteurColonne] = this->MATLireElement(uiCompteurLignes, uiCompteurColonne) * dValeur;
		}
	}

	CMatrice* pMATResultatProduit = new CMatrice(uiCompteurLignes, uiCompteurColonne, MATTableau);

	return *pMATResultatProduit;
}

CMatrice CMatrice::operator/(double dValeur)
{
	unsigned int uiCompteurLignes = 0; //Iterateur de boucle
	unsigned int uiCompteurColonne = 0; //Iterateur de boucle
	CException EXCObjet;
	float* MATTableau = (float*)malloc(sizeof(float) * this->MATLireNbLigne() * this->MATLireNbColonne());
	if (this->MATIsEmpty() == true)
	{
		EXCObjet.EXCModifierValeur(ERREUR_MATRICE_VIDE);
		std::cout << "La matrice est vide donc on ne peut pas faire l'operation";
		throw EXCObjet;
	}

	if (dValeur == 0)
	{
		EXCObjet.EXCModifierValeur(DIVISION_PAR_ZERO);
		std::cout << "Divison par 0. Impossible";
		throw EXCObjet;
	}

	for (uiCompteurLignes = 0; uiCompteurLignes < this->MATLireNbLigne(); uiCompteurLignes++)
	{
		for (uiCompteurColonne = 0; uiCompteurColonne < this->MATLireNbColonne(); uiCompteurColonne++)
		{
			MATTableau[uiCompteurLignes * this->MATLireNbColonne() + uiCompteurColonne] = this->MATLireElement(uiCompteurLignes, uiCompteurColonne) / dValeur;
		}
	}

	CMatrice* pMATResultatDivison = new CMatrice(uiCompteurLignes, uiCompteurColonne, MATTableau);

	return *pMATResultatDivison;
}

CMatrice& CMatrice::operator+(CMatriceBase MATObjet)
{
	unsigned int uiCompteurLigne, uiCompteurColonne;
	CException EXCObjet;

	if (this->MATLireNbColonne() != MATObjet.MATLireNbColonne() || this->MATLireNbLigne() != MATObjet.MATLireNbLigne())
	{
		EXCObjet.EXCModifierValeur(TAILLE_INCOMPATIBLE);
		std::cout << "Taille imcompatible";
		throw EXCObjet;
	}
	float* MATTableau = (float*)malloc(sizeof(float) * this->MATLireNbLigne() * this->MATLireNbColonne());

	for (uiCompteurLigne = 0; uiCompteurLigne < this->MATLireNbLigne(); uiCompteurLigne++)
	{
		for (uiCompteurColonne = 0; uiCompteurColonne < this->MATLireNbColonne(); uiCompteurColonne++)
		{
			MATTableau[uiCompteurLigne * this->MATLireNbLigne() + uiCompteurColonne] = this->MATLireElement(uiCompteurLigne, uiCompteurColonne) + MATObjet.MATLireElement(uiCompteurLigne, uiCompteurColonne);
		}

	}


	CMatrice* pMATResultatSomme = new CMatrice(uiCompteurLigne, uiCompteurColonne, MATTableau);

	return *pMATResultatSomme;
}
