#include <iostream>
#include <assert.h>
#include <fstream>

#include "CMatrice.h"
#define OperationInfaisable 10
#define ERREUR_MATRICE_VIDE 6
#define DIVISION_PAR_ZERO 10
#define TAILLE_INCOMPATIBLE 11
#define MATRICEVIDE 12

using namespace std;

CMatrice Exe;

CMatrice::CMatrice(unsigned int uiLignes, unsigned int uiColonnes, float * pfElements) : CMatriceBase(uiLignes,uiColonnes,pfElements)
{
	
}

CMatrice::CMatrice() 
{
	
}



CMatrice::CMatrice(const CMatrice& MATObjet) : CMatriceBase(MATObjet)
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

	//	cout << Element << " en position (" << uiLigne << ", " << uiColonne << ") >> ";
		pfElements[uiBoucle] = Element;
	//	cout << " (" << uiColonne << ", " << uiLigne << ")\n";

	}


	CMatrice MATResultat(uiNbColonnes, uiNbLignes, pfElements);
	return MATResultat; // Objet détruit
}



CMatrice CMatrice::operator*(CMatrice MATObjet)
{
	CException mistake;
	// Dimensions de la nouvelle matrice
	/*unsigned int uiNbLignes = this->MATLireNbLigne();
	unsigned int uiNbColonnes = MATObjet.MATLireNbColonne();*/
	unsigned int uiNbLignes = MATObjet.MATLireNbLigne();
	unsigned int uiNbColonnes = this->MATLireNbColonne();
	unsigned int uiLigne;
	unsigned int uiColonne;

	// Sont égaux normalement sinon lancer une exception
	unsigned int uiLignes = MATObjet.MATLireNbLigne();
	unsigned int uiColonnes = this->MATLireNbColonne();

	//Verification de la faisabilité du calcul
	if (this->MATLireNbColonne() != MATObjet.MATLireNbLigne())
	{
		mistake.EXCModifierValeur(OperationInfaisable);
		throw mistake;
	}

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
	
	

	CMatrice MATResultat(uiNbLignes, uiNbColonnes, pfElements);
	free(pfElements);
	return MATResultat ; // pointeur détruit après retour par référence
}

CMatrice CMatrice::Greville()
{
	unsigned int i = 0; /*itérateur boucle*/
	unsigned int uiboucle = 1; /*itérateur boucle*/
	unsigned int indice = 0; /*Indice dans le psuedo-matrice*/
	float* coef = (float*)malloc(sizeof(float) * 1);
	CMatrice temp;

	float* AMatrice = (float*)malloc(sizeof(float) * 1* this->MATLireNbLigne());
	/*Initialisation*/
	bool verif = false; /*Booléean qui est à faux tant que les élements d'une matrice sont égaux à 0*/
	for (i = 0; i < this->MATLireNbLigne() || verif==false; i++)
	{
		if (this->MATLireElement(i, 0) != 0)
		{
			verif = true;
		}
	}
	if (verif != true)
	{
		for (i = 0; i < this->MATLireNbColonne() ; i++)
		{
			AMatrice[i] = 0;
		}
	}
	else {
		for (i = 0; i <  this->MATLireNbLigne(); i++)
		{
			AMatrice[i] = this->MATLireElement(i,0);
		}
		
	}
	CMatrice psuedoMatrice(this->MATLireNbColonne(), this->MATLireNbLigne(), AMatrice);
	/*Créarion des variables nécéssaires pour appliquer l'aglorithme*/

	CMatrice a,b,c,d;
	/*Application de l'algorithme*/
	for (uiboucle = 1; uiboucle < this->MATLireNbColonne(); uiboucle++)
	{
		temp = this->MATFromColonne(uiboucle);
		d = psuedoMatrice * temp;
		c = temp - (psuedoMatrice * d);
		c.MATAffiche();
		verif = false;
		for (i = 0; i < c.MATLireNbLigne()* c.MATLireNbColonne() || verif == false; i++)
		{
			if (this->MATLireElement(i, 0) != 0)
			{
				verif = true;
			}
		}if (verif != true)
		{
			*coef = 1 / (CMatrice::MATIdentity(d.MATLireNbLigne(), d.MATLireNbColonne()) + d.MATTranspose() * d).MATLireElement(0, 0);
			b =  CMatrice(1,1,coef) * d.MATTranspose() * psuedoMatrice;
		}
		else {
			*coef = (c.MATTranspose() * c).MATLireElement(0,0);
			b = CMatrice(1,1,coef) * c.MATTranspose();
		}
		
	}
	
	
	return Exe;
}

CMatrice::~CMatrice()
{

}

CMatrice CMatrice::MATFromColonne(unsigned int numColonne)
{
	CException mistake;
	/*Vérification de l'existance du matrice et de la colonne*/
	if (this->MATIsEmpty() == true)
	{
		mistake.EXCModifierValeur(MATRICEVIDE);
		throw mistake;
	}
	if (numColonne >= this->MATLireNbColonne())
	{
		mistake.EXCModifierValeur(TAILLE_INCOMPATIBLE);
		throw mistake;
	}
	
	float* tab; /*Tableau de float qui servira a recuperer les données d'une colonne*/
	tab = (float*)malloc(sizeof(float) * this->MATLireNbLigne()); /*Initialisation de taab pour acceuilir le bon nombre d'élément*/

	for (int i = 0; i < this->MATLireNbLigne(); i++)
	{
		tab[i] = this->MATLireElement(i, numColonne);
	}

	CMatrice resultat(this->MATLireNbLigne(), 1, tab);
	free(tab);

	return resultat;
}

CMatrice CMatrice::MATIdentity(unsigned int nbLignes, unsigned int nbColonnes)
{
	unsigned int uiboucle = 0;
	float* tab = (float*)malloc(sizeof(float) * nbColonnes * nbLignes);
	if (nbLignes != 0 || nbColonnes != 0)
	{
		for (uiboucle = 0; uiboucle < nbColonnes * nbLignes; uiboucle++)
		{
			tab[uiboucle] = 0;
		}

		for (uiboucle = 0; uiboucle < nbLignes && uiboucle < nbColonnes; uiboucle++)
		{
			tab[uiboucle * nbColonnes + uiboucle] = 1;
		}
	}

	CMatrice resultat(nbLignes, nbColonnes, tab);
	free(tab);

	return resultat;
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

CMatrice CMatrice::operator-(CMatrice MATObjet)
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


	CMatrice MATResultatDifference(uiCompteurLigne, uiCompteurColonne, MATTableau);
	free(MATTableau);
	return MATResultatDifference;
}

CMatrice CMatrice::operator*(double dValeur)
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

	CMatrice MATResultatProduit(uiCompteurLignes, uiCompteurColonne, MATTableau);
	free(MATTableau);
	return MATResultatProduit;
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

	CMatrice MATResultatDivison(uiCompteurLignes, uiCompteurColonne, MATTableau);

	free(MATTableau);
	return MATResultatDivison;
}

CMatrice CMatrice::operator+(CMatrice MATObjet)
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


	CMatrice MATResultatSomme(uiCompteurLigne, uiCompteurColonne, MATTableau);
	free(MATTableau);
	return MATResultatSomme;
}

