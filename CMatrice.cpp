#include <iostream>
#include <iomanip>
#include <fstream>

#include "CMatrice.h"
#define OperationInfaisable 10
#define ERREUR_MATRICE_VIDE 6
#define DIVISION_PAR_ZERO 10
#define TAILLE_INCOMPATIBLE 11
#define MATRICEVIDE 12
#include <math.h>

#define precision 0.0001   // Chiffres significatifs
/**
* @Brief Fonction qui permet de v�rifier si des double sont �gaux en prenant compte de la pr�cision. En effet, les fractions en double sont directement convertit en d�cimal avec une pr�cision de 0.0000001. Par cons�quence certaines �galit�s sont fausse � cause de la conversion du compilateur.
*/
#define FloatIsEqual(x,v) (((v - precision) < x) && (x <( v + precision)))

using namespace std;
using std::setprecision;


CMatrice::CMatrice(unsigned int uiLignes, unsigned int uiColonnes, double * pfElements) : CMatriceBase(uiLignes, uiColonnes, pfElements)
{

}

CMatrice::CMatrice()
{

}



CMatrice::CMatrice(const CMatrice& MATObjet) : CMatriceBase(MATObjet)
{

}

/*
CMatrice CMatrice::MATDenavit(DenavitParameter DENObject)
{
	double * pfMATElementaire = (double*)malloc(sizeof(double) * 16);

	pfMATElementaire[0] = cos(DENObject.DENLireVariable(0)->LireValeur());
	pfMATElementaire[1] = -sin(DENObject.DENLireVariable(0)->LireValeur()) * cos(DENObject.DENLireVariable(2)->LireValeur());
	pfMATElementaire[2] = sin(DENObject.DENLireVariable(0)->LireValeur()) * cos(DENObject.DENLireVariable(2)->LireValeur());
	pfMATElementaire[3] = DENObject.DENLireVariable(3)->LireValeur() * cos(DENObject.DENLireVariable(0)->LireValeur());
	pfMATElementaire[4] = sin(DENObject.DENLireVariable(0)->LireValeur());
	pfMATElementaire[5] = cos(DENObject.DENLireVariable(0)->LireValeur()) * cos(DENObject.DENLireVariable(2)->LireValeur());
	pfMATElementaire[6] = -cos(DENObject.DENLireVariable(0)->LireValeur()) * sin(DENObject.DENLireVariable(2)->LireValeur());
	pfMATElementaire[7] = (DENObject.DENLireVariable(3)->LireValeur()) * sin(DENObject.DENLireVariable(2)->LireValeur());
	pfMATElementaire[8] = 0;
	pfMATElementaire[9] = sin(DENObject.DENLireVariable(2)->LireValeur());
	pfMATElementaire[10] = cos(DENObject.DENLireVariable(2)->LireValeur());
	pfMATElementaire[11] = (DENObject.DENLireVariable(1)->LireValeur());
	pfMATElementaire[12] = 0;
	pfMATElementaire[13] = 0;
	pfMATElementaire[14] = 0;
	pfMATElementaire[15] = 1;

	CMatrice MATResultat(4, 4, pfMATElementaire);

	free(pfMATElementaire);
	return MATResultat;

}
*/

CMatrice CMatrice::MATTranspose()
{
	unsigned int uiBoucle;
	unsigned int uiLigne;
	unsigned int uiColonne;
	unsigned int uiNbLignes = this->MATLireNbLigne();
	unsigned int uiNbColonnes = this->MATLireNbColonne();
	double* pfElements = (double*)malloc(sizeof(double) * uiNbColonnes * uiNbLignes);
	double Element;

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
	free(pfElements);
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

	double* pfElements = (double*)malloc(sizeof(double) * uiNbLignes * uiNbColonnes);
	double fElement;

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
	return MATResultat; // pointeur d�truit apr�s retour par r�f�rence
}

CMatrice CMatrice::Greville()
{
	/**Declaration*/
	unsigned int i = 0; /*it�rateur boucle*/
	unsigned int uiboucle = 1; /*it�rateur boucle*/
	unsigned int indice = 0; /*Indice dans le psuedo-matrice*/
	double* coef = (double*)malloc(sizeof(double) * 1); /*Valeur interm�diare n�cessaire pour le calcul de b lorsque c n'est pas une matrice null*/
	CMatrice kPremieresColonnes; /*Matrice des k premi�res colonnes de la matrice A*/
	CMatrice psuedoMatrice; /*La matrice inverse de A (dans certains cas : pseudoMatrice)*/
	CMatrice a, b, c, d;
	double* AMatrice = (double*)malloc(sizeof(double) * 1 * this->MATLireNbLigne()); /**Initialisation d'un pointeur de double de la taille de la premi�re colonne de A n�cessaire pour l'initialisation de la pseudomatrice*/

	/**Initialisation*/
	bool verif = false; /**Bool�ean qui est � faux tant que les �lements d'une matrice sont �gaux � 0*/
	for (i = 0; i < this->MATLireNbLigne() && verif == false; i++) /**tant qu'on a pas trouv� un �l�ment non nul dans la premi�re colonne de la matrice A et qu'il y a encore des element dans la matrice A*/
	{
		if (this->MATLireElement(i, 0) != 0)
		{
			verif = true; /**On a trouv� un �l�ment non null dans la premi�re colonne de la matrice A. */
		}
	}
	if (verif != true) /**Si dans la premi�re colonne de A, tous les �l�ments sont �gaux � 0 exactement*/
	{
		for (i = 0; i < this->MATLireNbColonne(); i++)
		{
			AMatrice[i] = 0;
		}

		/*On cr�e une matrice de taille 1xNombreDeLignesDansA null qu'on affecte � la matrice pseudoMatrice*/
		CMatrice MATTemp(1, this->MATLireNbLigne(), AMatrice);
		psuedoMatrice = MATTemp;
	}
	else { /*Sinon, pseudoMatrice vaut: (a1.transpose*a)^-1 * a.transpose*/
		
		CMatrice MATTemp = this->MATFromColonne(0);
		double def = (MATTemp.MATTranspose() * MATTemp).MATLireElement(0, 0);
		psuedoMatrice = MATTemp.MATTranspose() / def;

	}


	/*Application de l'algorithme*/
	for (uiboucle = 1; uiboucle < this->MATLireNbColonne(); uiboucle++)
	{
		// psuedoMatrice.MATAffiche();
		a = this->MATFromColonne(uiboucle);
		// a.MATAffiche();
		d = psuedoMatrice * a;
		// d.MATAffiche();
		if (uiboucle == 1)
		{
			kPremieresColonnes = this->MATFromColonne(uiboucle - 1);
		}
		else
		{
			kPremieresColonnes.MATAjouerColonnesMatrice(this->MATFromColonne(uiboucle - 1));
		}

		c = a - (kPremieresColonnes * d);

		/**
		 * @brief Est ce que la matrice c
		 * @return false si la matrice c est null sinon true
		*/
		verif = false;
		for (i = 0; i < c.MATLireNbLigne()* c.MATLireNbColonne() && verif == false; i++)
		{
			if (FloatIsEqual(c.MATLireElement(i, 0), 0))
			{

			}
			else
			{
				verif = true;
			}
		}
		/**
		 * Selon les valeurs de la matrice C, on calcule b de mani�re diff�rente
		*/
		if (verif != true)
		{

			CMatrice temp = (CMatrice::MATIdentity(1, 1) + d.MATTranspose() * d);
			double fintermediaire = 1 / temp.MATLireElement(0, 0);
			b = (d.MATTranspose()* fintermediaire) * psuedoMatrice;
		}
		else {
			*coef = 1 / (c.MATTranspose() * c).MATLireElement(0, 0);
			b = CMatrice(1, 1, coef) * c.MATTranspose();

		}
		psuedoMatrice = psuedoMatrice - d * b;
		psuedoMatrice.MATAjouerLignesMatrice(b);
	}

	/**
	 *Lib�ration
	*/
	free(coef);
	free(AMatrice);
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

	double* tab; /*Tableau de double qui servira a recuperer les donn�es d'une colonne*/
	tab = (double*)malloc(sizeof(double) * this->MATLireNbLigne()); /*Initialisation de taab pour acceuilir le bon nombre d'�l�ment*/

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
	double* tab = (double*)malloc(sizeof(double) * nbColonnes * nbLignes);
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
	double* resultat;
	MATReallocMatrice(number * MATLireNbLigne());
	MATModifierNbColonnes(MATLireNbColonne() + number);
	/*Decalage*/
	resultat = (double*)malloc(sizeof(double) * this->MATLireNbColonne() * this->MATLireNbLigne());
	for (uiboucle = 0; uiboucle < temp.MATLireNbLigne(); uiboucle++)
	{
		for (uiboucle2 = 0; uiboucle2 < temp.MATLireNbColonne(); uiboucle2++)
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
	double element;

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
					this->MATModiferElement(uiBoucle, uiBoucle2, element);
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
	double element;

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
					element = Objet.MATLireElement(uiBoucle, uiBoucle2 - thisNbColonnes);
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
	double* MATTableau = (double*)malloc(sizeof(double) * this->MATLireNbLigne() * this->MATLireNbColonne());

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

CMatrice CMatrice::operator*(double fValeur)
{
	unsigned int uiCompteurLignes = 0; //It�rateur de boucles
	unsigned int uiCompteurColonne = 0; //It�rateur de boucles
	CException EXCObjet;
	double* MATTableau = (double*)malloc(sizeof(double) * this->MATLireNbLigne() * this->MATLireNbColonne());
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
			MATTableau[uiCompteurLignes * this->MATLireNbColonne() + uiCompteurColonne] = this->MATLireElement(uiCompteurLignes, uiCompteurColonne) * fValeur;
		}
	}

	CMatrice MATResultatProduit(uiCompteurLignes, uiCompteurColonne, MATTableau);
	free(MATTableau);
	return MATResultatProduit;
}

CMatrice CMatrice::operator/(double fValeur)
{
	unsigned int uiCompteurLignes = 0; //Iterateur de boucle
	unsigned int uiCompteurColonne = 0; //Iterateur de boucle
	CException EXCObjet;
	double* MATTableau = (double*)malloc(sizeof(double) * this->MATLireNbLigne() * this->MATLireNbColonne());
	if (this->MATIsEmpty() == true)
	{
		EXCObjet.EXCModifierValeur(ERREUR_MATRICE_VIDE);
		std::cout << "La matrice est vide donc on ne peut pas faire l'operation";
		throw EXCObjet;
	}

	if (fValeur == 0)
	{
		EXCObjet.EXCModifierValeur(DIVISION_PAR_ZERO);
		std::cout << "Divison par 0. Impossible";
		throw EXCObjet;
	}

	for (uiCompteurLignes = 0; uiCompteurLignes < this->MATLireNbLigne(); uiCompteurLignes++)
	{
		for (uiCompteurColonne = 0; uiCompteurColonne < this->MATLireNbColonne(); uiCompteurColonne++)
		{
			MATTableau[uiCompteurLignes * this->MATLireNbColonne() + uiCompteurColonne] = this->MATLireElement(uiCompteurLignes, uiCompteurColonne) / fValeur;
		}
	}

	CMatrice MATResultatDivison(uiCompteurLignes, uiCompteurColonne, MATTableau);

	free(MATTableau);
	return MATResultatDivison;
}

CMatrice CMatrice::operator+(CMatrice MATObjet)
{
	unsigned int uiCompteurLigne = 0;
	unsigned int uiCompteurColonne = 0;
	CException EXCObjet;

	if (this->MATLireNbColonne() != MATObjet.MATLireNbColonne() || this->MATLireNbLigne() != MATObjet.MATLireNbLigne())
	{
		EXCObjet.EXCModifierValeur(TAILLE_INCOMPATIBLE);
		std::cout << "Taille imcompatible";
		throw EXCObjet;
	}

	double* MATTableau = (double*)malloc(sizeof(double) * this->MATLireNbLigne() * this->MATLireNbColonne());

	if (MATTableau)
	{


		for (uiCompteurLigne = 0; uiCompteurLigne < this->MATLireNbLigne(); uiCompteurLigne++)
		{
			for (uiCompteurColonne = 0; uiCompteurColonne < this->MATLireNbColonne(); uiCompteurColonne++)
			{
				MATTableau[uiCompteurLigne * this->MATLireNbColonne() + uiCompteurColonne] = this->MATLireElement(uiCompteurLigne, uiCompteurColonne) + MATObjet.MATLireElement(uiCompteurLigne, uiCompteurColonne);
			}

		}
	}

	CMatrice MATResultatSomme(uiCompteurLigne, uiCompteurColonne, MATTableau);
	free(MATTableau);
	return MATResultatSomme;
}
