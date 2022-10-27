#include <iostream>
#include <assert.h>
#include <fstream>

#include "CMatriceExtension.h"
#define ERREUR_MATRICE_VIDE 6
#define DIVISION_PAR_ZERO 10
#define TAILLE_INCOMPATIBLE 11
#include "CException.h"

CMatriceExtension mmis;

CMatriceExtension::CMatriceExtension(CMatriceExtension& MATObjet) : CMatriceBase(MATObjet)
{

}

CMatriceExtension::CMatriceExtension()
{
	return; 
}

CMatriceExtension::CMatriceExtension(unsigned int uiLignes, unsigned int uiColonnes, float* pfElements) : CMatriceBase(uiLignes,uiColonnes,pfElements)
{

}

//bool CMatriceExtension::MATIsEmpty()
//{
//	if (this->MATLireNbColonne() == 0 || this->MATLireNbLigne() == 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//CMatriceExtension& CMatriceExtension::operator-(CMatriceBase MATObjet)
//{
//	unsigned int uiCompteurLigne = 0; //itarateurs de boucles
//	unsigned int uiCompteurColonne = 0; //itarateurs de boucles
//	CException EXCObjet;
//
//	if (this->MATLireNbColonne() != MATObjet.MATLireNbColonne() || this->MATLireNbLigne() != MATObjet.MATLireNbLigne())
//	{
//		EXCObjet.EXCModifierValeur(TAILLE_INCOMPATIBLE);
//		std::cout << "Taille imcompatible";
//		throw EXCObjet;
//	}
//	float* MATTableau = (float*)malloc(sizeof(float) * this->MATLireNbLigne() * this->MATLireNbColonne());
//
//	for (uiCompteurLigne = 0; uiCompteurLigne < this->MATLireNbLigne(); uiCompteurLigne++)
//	{
//		for (uiCompteurColonne = 0; uiCompteurColonne < this->MATLireNbColonne(); uiCompteurColonne++)
//		{
//			MATTableau[uiCompteurLigne * this->MATLireNbLigne() + uiCompteurColonne] = this->MATLireElement(uiCompteurLigne, uiCompteurColonne) - MATObjet.MATLireElement(uiCompteurLigne, uiCompteurColonne);
//		}
//
//	}
//
//
//	CMatriceExtension* pMATResultatDifference = new CMatriceExtension(uiCompteurLigne, uiCompteurColonne, MATTableau);
//
//	return *pMATResultatDifference;
//}
//
//CMatriceExtension& CMatriceExtension::operator*(double dValeur)
//{
//	unsigned int uiCompteurLignes = 0; //Itérateur de boucles
//	unsigned int uiCompteurColonne = 0; //Itérateur de boucles
//	CException EXCObjet;
//	float* MATTableau = (float*)malloc(sizeof(float) * this->MATLireNbLigne() * this->MATLireNbColonne());
//	if (this->MATIsEmpty() == true)
//	{
//		EXCObjet.EXCModifierValeur(ERREUR_MATRICE_VIDE);
//		std::cout << "La matrice est vide donc on ne peut pas faire l'operation";
//		throw EXCObjet;
//	}
//
//	for (uiCompteurLignes = 0; uiCompteurLignes < this->MATLireNbLigne(); uiCompteurLignes++)
//	{
//		for (uiCompteurColonne = 0; uiCompteurColonne < this->MATLireNbColonne(); uiCompteurColonne++)
//		{
//			MATTableau[uiCompteurLignes * this->MATLireNbColonne() + uiCompteurColonne] = this->MATLireElement(uiCompteurLignes, uiCompteurColonne) * dValeur;
//		}
//	}
//
//	CMatriceExtension* pMATResultatProduit = new CMatriceExtension(uiCompteurLignes, uiCompteurColonne, MATTableau);
//
//	return *pMATResultatProduit;
//}
//
//CMatriceExtension CMatriceExtension::operator/(double dValeur)
//{
//	unsigned int uiCompteurLignes = 0; //Iterateur de boucle
//	unsigned int uiCompteurColonne = 0; //Iterateur de boucle
//	CException EXCObjet;
//	float* MATTableau = (float*)malloc(sizeof(float) * this->MATLireNbLigne() * this->MATLireNbColonne());
//	if (this->MATIsEmpty() == true)
//	{
//		EXCObjet.EXCModifierValeur(ERREUR_MATRICE_VIDE);
//		std::cout << "La matrice est vide donc on ne peut pas faire l'operation";
//		throw EXCObjet;
//	}
//
//	if (dValeur == 0)
//	{
//		EXCObjet.EXCModifierValeur(DIVISION_PAR_ZERO);
//		std::cout << "Divison par 0. Impossible";
//		throw EXCObjet;
//	}
//
//	for (uiCompteurLignes = 0; uiCompteurLignes < this->MATLireNbLigne(); uiCompteurLignes++)
//	{
//		for (uiCompteurColonne = 0; uiCompteurColonne < this->MATLireNbColonne(); uiCompteurColonne++)
//		{
//			MATTableau[uiCompteurLignes * this->MATLireNbColonne() + uiCompteurColonne] = this->MATLireElement(uiCompteurLignes, uiCompteurColonne) / dValeur;
//		}
//	}
//
//	CMatriceExtension* pMATResultatDivison = new CMatriceExtension(uiCompteurLignes, uiCompteurColonne, MATTableau);
//
//	return *pMATResultatDivison;
//}
//
//CMatriceExtension& CMatriceExtension::operator+(CMatriceBase MATObjet)
//{
//	unsigned int uiCompteurLigne, uiCompteurColonne; 
//	CException EXCObjet;
//
//	if (this->MATLireNbColonne() != MATObjet.MATLireNbColonne() || this->MATLireNbLigne() != MATObjet.MATLireNbLigne())
//	{
//		EXCObjet.EXCModifierValeur(TAILLE_INCOMPATIBLE);
//		std::cout << "Taille imcompatible";
//		throw EXCObjet;
//	}
//	float* MATTableau = (float*)malloc(sizeof(float) * this->MATLireNbLigne() * this->MATLireNbColonne());
//
//	for (uiCompteurLigne = 0; uiCompteurLigne < this->MATLireNbLigne(); uiCompteurLigne++)
//	{
//		for (uiCompteurColonne = 0; uiCompteurColonne < this->MATLireNbColonne(); uiCompteurColonne++)
//		{
//			MATTableau[uiCompteurLigne * this->MATLireNbLigne() + uiCompteurColonne] = this->MATLireElement(uiCompteurLigne, uiCompteurColonne) + MATObjet.MATLireElement(uiCompteurLigne, uiCompteurColonne);
//		}
//
//	}
//
//
//	CMatriceExtension* pMATResultatSomme = new CMatriceExtension(uiCompteurLigne, uiCompteurColonne, MATTableau); 
//
//	return *pMATResultatSomme;
//}
