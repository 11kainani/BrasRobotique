#include <iostream>
#include <iomanip>
#include <assert.h>
#include <fstream>

#include "CMatrice.h"
#define OperationInfaisable 10
#define ERREUR_MATRICE_VIDE 6
#define DIVISION_PAR_ZERO 10
#define TAILLE_INCOMPATIBLE 11
#define MATRICEVIDE 12

#define precision 0.0001   // Define your own tolerance
/**
* @Brief Fonction qui permet de v�rifier si des float sont �gaux en prenant compte de la pr�cision. En effet, les fractions en float sont directement convertit en d�cimal avec une pr�cision de 0.0000001. Par cons�quence certaines �galit�s sont fausse � cause de la conversion du compilateur. 
*/
#define FloatIsEqual(x,v) (((v - precision) < x) && (x <( v + precision)))

using namespace std;
using std::setprecision;

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
		uiLigne = uiBoucle % uiNbLignes; // Ligne de l'�l�ment � �changer
		uiColonne = uiBoucle / uiNbLignes; // Colonne de l'�l�ment � �changer
		Element = this->MATLireElement(uiLigne, uiColonne);

	//	cout << Element << " en position (" << uiLigne << ", " << uiColonne << ") >> ";
		pfElements[uiBoucle] = Element;
	//	cout << " (" << uiColonne << ", " << uiLigne << ")\n";

	}


	CMatrice MATResultat(uiNbColonnes, uiNbLignes, pfElements);
	return MATResultat; // Objet d�truit
}



CMatrice CMatrice::operator*(CMatrice MATObjet)
{
	CException mistake;
	// Dimensions de la nouvelle matrice
	unsigned int uiNbLignes = this->MATLireNbLigne();
	unsigned int uiNbColonnes = MATObjet.MATLireNbColonne();
	//unsigned int uiNbLignes = MATObjet.MATLireNbLigne();
	//unsigned int uiNbColonnes = this->MATLireNbColonne();
	unsigned int uiLigne;
	unsigned int uiColonne;

	// Sont �gaux normalement sinon lancer une exception
	unsigned int uiLignes = MATObjet.MATLireNbLigne();
	unsigned int uiColonnes = this->MATLireNbColonne();

	//Verification de la faisabilit� du calcul
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
	return MATResultat ; // pointeur d�truit apr�s retour par r�f�rence
}

CMatrice CMatrice::Greville()
{
	unsigned int i = 0; /*it�rateur boucle*/
	unsigned int uiboucle = 1; /*it�rateur boucle*/
	unsigned int indice = 0; /*Indice dans le psuedo-matrice*/
	float* coef = (float*)malloc(sizeof(float) * 1);
	CMatrice temp;
	CMatrice kPremieresColonnes;
	CMatrice psuedoMatrice;

	float* AMatrice = (float*)malloc(sizeof(float) * 1* this->MATLireNbLigne());
	/*Initialisation*/
	bool verif = false; /*Bool�ean qui est � faux tant que les �lements d'une matrice sont �gaux � 0*/
	for (i = 0; i < this->MATLireNbLigne() && verif==false; i++)
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
			CMatrice MATTemp (1, this->MATLireNbLigne(), AMatrice);
			psuedoMatrice = MATTemp;
		}
	}
	else {
		for (i = 0; i <  this->MATLireNbLigne(); i++)
		{
			AMatrice[i] = this->MATLireElement(i,0);
			CMatrice MATTemp = this->MATFromColonne(0);
			float def = (MATTemp.MATTranspose() * MATTemp).MATLireElement(0,0);
			psuedoMatrice = MATTemp.MATTranspose() / def;
		

		}
		
	}
//	CMatrice psuedoMatrice(this->MATLireNbColonne(), this->MATLireNbLigne(), AMatrice);
	//CMatrice psuedoMatrice(1,this->MATLireNbLigne(), AMatrice);
	/*Cr�arion des variables n�c�ssaires pour appliquer l'aglorithme*/

	CMatrice a, b,c,cTemp,d, dbtemp;
	/*Application de l'algorithme*/
	for (uiboucle = 1; uiboucle < this->MATLireNbColonne(); uiboucle++)
	{
		cout << "La pseudo matrice :"  <<  uiboucle << "\n" ;
		psuedoMatrice.MATAffiche();
		cout << "matrice  a : " << uiboucle +1 << "\n";
		a = this->MATFromColonne(uiboucle);
		a.MATAffiche();
		d = psuedoMatrice * a;
		cout << "La matrice d" << uiboucle + 1 << ":\n";
		d.MATAffiche();
		if (uiboucle == 1)
		{
			kPremieresColonnes = this->MATFromColonne(uiboucle-1);
		}
		else
		{
			kPremieresColonnes.MATAjouerColonnesMatrice(this->MATFromColonne(uiboucle - 1));
		}
		
		cout << "La matrice A" << uiboucle + 1 << ":\n";
		(kPremieresColonnes).MATAffiche();
		
		c = a - (kPremieresColonnes * d); //K premiers colonnes de la matrice A
		cout << "La matrice c" << uiboucle+1 << ":\n";
		c.MATAffiche();
	
		
		verif = false;
		for (i = 0; i < c.MATLireNbLigne()* c.MATLireNbColonne() && verif == false; i++)
		{
			if (FloatIsEqual(c.MATLireElement(i, 0), 0) )
			{
				
			}
			else
			{
				verif = true;
			}
		}if (verif != true)
		{
			/**coef = 1 / (CMatrice::MATIdentity(d.MATLireNbLigne(), d.MATLireNbColonne()) + d.MATTranspose() * d).MATLireElement(0, 0);
			b =  CMatrice(1,1,coef) * d.MATTranspose() * psuedoMatrice;*/
			CMatrice temp = (CMatrice::MATIdentity(1, 1) + d.MATTranspose() * d);
			float fintermediaire = 1 / temp.MATLireElement(0, 0);
			b =  (d.MATTranspose()* fintermediaire) * psuedoMatrice;
		}
		else {
			*coef = 1/(c.MATTranspose() * c).MATLireElement(0,0);
			b = CMatrice(1,1,coef) * c.MATTranspose();
			
		}
		cout << "Matrice b " << uiboucle - 1 << "\n";
		b.MATAffiche();
		psuedoMatrice = psuedoMatrice - d * b;
		psuedoMatrice.MATAjouerLignesMatrice(b);
	}
	
	
	return psuedoMatrice;
	
}



CMatrice::~CMatrice()
{

}

CMatrice CMatrice::MATFromColonne(unsigned int numColonne)
{
	CException mistake;
	/*V�rification de l'existance du matrice et de la colonne*/
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
	
	float* tab; /*Tableau de float qui servira a recuperer les donn�es d'une colonne*/
	tab = (float*)malloc(sizeof(float) * this->MATLireNbLigne()); /*Initialisation de taab pour acceuilir le bon nombre d'�l�ment*/

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

void CMatrice::MATAjouterLignes(unsigned int number)
{
	CMatrice temp = *this;
	unsigned int uiboucle, uiboucle2;
	MATReallocMatrice(number * MATLireNbColonne());
	MATModifierNbLignes(MATLireNbLigne() + number);

	for (uiboucle = 0; uiboucle < temp.MATLireNbLigne(); uiboucle++)
	{
		for (uiboucle2 = 0; uiboucle2 < temp.MATLireNbColonne(); uiboucle2++)
		{
			this->MATModiferElement(uiboucle, uiboucle2, temp.MATLireElement(uiboucle, uiboucle2));
		}
	}

	for (uiboucle; uiboucle < this->MATLireNbLigne(); uiboucle++)
	{
		for (uiboucle2 = 0; uiboucle2 < temp.MATLireNbColonne(); uiboucle2++)
		{
			this->MATModiferElement(uiboucle, uiboucle2, 0);
		}
	}
	
	
}

void CMatrice::MATAjouterColonnes(unsigned int number)
{
	CMatrice temp = *this;
	unsigned int uiboucle, uiboucle2;
	float* resultat;
	MATReallocMatrice(number * MATLireNbLigne());
	MATModifierNbColonnes(MATLireNbColonne() + number);
	/*Decalage*/
	resultat = (float*)malloc(sizeof(float) * this->MATLireNbColonne() * this->MATLireNbLigne());
	for (uiboucle = 0; uiboucle < temp.MATLireNbLigne() ; uiboucle++)
	{
		for (uiboucle2 = 0; uiboucle2 <  temp.MATLireNbColonne(); uiboucle2++)
		{
			resultat[uiboucle * this->MATLireNbColonne() + uiboucle2] = temp.MATLireElement(uiboucle, uiboucle2);
		}
	}
	CMatrice MATResultat(this->MATLireNbLigne(), this->MATLireNbColonne(), resultat);
	

	for (uiboucle = 0; uiboucle < MATResultat.MATLireNbLigne(); uiboucle++)
	{
		for (uiboucle2 = 0; uiboucle2 < MATResultat.MATLireNbColonne(); uiboucle2++)
		{
			this->MATModiferElement(uiboucle, uiboucle2, MATResultat.MATLireElement(uiboucle, uiboucle2));
		}
	}	
	free(resultat); 
}

void CMatrice::MATAjouerLignesMatrice(CMatrice Objet)
{
	unsigned int nbColonnes = Objet.MATLireNbColonne();
	unsigned int nbLignes = Objet.MATLireNbLigne();
	unsigned int thisNbColonnes = this->MATLireNbColonne();
	unsigned int thisNbLignes = this->MATLireNbLigne();
	unsigned int uiBoucle, uiBoucle2;
	float element;

	if (nbColonnes != thisNbColonnes)
	{
		cout << "erreur";
	}
	else
	{
		if (nbLignes != 0)
			{
				this->MATAjouterLignes(nbLignes);
				for (uiBoucle = thisNbLignes; uiBoucle < this->MATLireNbLigne(); uiBoucle++)
				{
					for (uiBoucle2 = 0; uiBoucle2 < thisNbColonnes; uiBoucle2++)
					{
						element = Objet.MATLireElement(uiBoucle - thisNbLignes, uiBoucle2);
						this->MATModiferElement(uiBoucle, uiBoucle2,element);
					}
				}
		

			}
	}
}


void CMatrice::MATAjouerColonnesMatrice(CMatrice Objet)
{
	unsigned int nbColonnes = Objet.MATLireNbColonne();
	unsigned int nbLignes = Objet.MATLireNbLigne();
	unsigned int thisNbColonnes = this->MATLireNbColonne();
	unsigned int thisNbLignes = this->MATLireNbLigne();
	unsigned int uiBoucle, uiBoucle2;
	float element;

	if (nbLignes != thisNbLignes)
	{
		cout << "erreur";
	}
	else
	{
		if (nbColonnes != 0)
		{
			this->MATAjouterColonnes(nbColonnes);
			for (uiBoucle2 = thisNbColonnes; uiBoucle2 < this->MATLireNbColonne(); uiBoucle2++)
			{
				for (uiBoucle = 0; uiBoucle < thisNbLignes; uiBoucle++)
				{
					element = Objet.MATLireElement(uiBoucle, uiBoucle2-thisNbColonnes);
					this->MATModiferElement(uiBoucle, uiBoucle2, element);
				}
			}


		}
	}
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
	float* MATTableau = (float*)malloc(sizeof(float) * this->MATLireNbLigne() * this->MATLireNbColonne() );

	for (uiCompteurLigne = 0; uiCompteurLigne < this->MATLireNbLigne(); uiCompteurLigne++)
	{
		for (uiCompteurColonne = 0; uiCompteurColonne < this->MATLireNbColonne(); uiCompteurColonne++)
		{
			MATTableau[uiCompteurLigne * this->MATLireNbColonne() + uiCompteurColonne] = this->MATLireElement(uiCompteurLigne, uiCompteurColonne) - MATObjet.MATLireElement(uiCompteurLigne, uiCompteurColonne);
			
		}

	}



	CMatrice MATResultatDifference(uiCompteurLigne, uiCompteurColonne, MATTableau);
	free(MATTableau);
	return MATResultatDifference;
}

CMatrice CMatrice::operator*(double dValeur)
{
	unsigned int uiCompteurLignes = 0; //It�rateur de boucles
	unsigned int uiCompteurColonne = 0; //It�rateur de boucles
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
			MATTableau[uiCompteurLigne * this->MATLireNbColonne() + uiCompteurColonne] = this->MATLireElement(uiCompteurLigne, uiCompteurColonne) + MATObjet.MATLireElement(uiCompteurLigne, uiCompteurColonne);
		}

	}


	CMatrice MATResultatSomme(uiCompteurLigne, uiCompteurColonne, MATTableau);
	free(MATTableau);
	return MATResultatSomme;
}

