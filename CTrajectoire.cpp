#include "CTrajectoire.h"

CTrajectoire::CTrajectoire() : CLecteurBase()
{
	TRAMatrice = nullptr;
	uiMatriceLues = 0;
	uiNbPoints = 0;
}

CTrajectoire::CTrajectoire(char* pcCheminFicher) : CLecteurBase(pcCheminFicher)
{
	TRAMatrice = nullptr;
	uiMatriceLues = 0;
	uiNbPoints = 0;
}

CTrajectoire::~CTrajectoire() 
{
	delete[] (TRAMatrice);
	uiMatriceLues = 0;
	uiNbPoints = 0;
}

CMatrice CTrajectoire::TRALireMatrice(unsigned int uiIndice)
{
	return TRAMatrice[uiIndice];
}

unsigned int CTrajectoire::LireNbPoints()
{
	return uiNbPoints;
}

unsigned int CTrajectoire::LireNbLu()
{
	return uiMatriceLues;
}

void CTrajectoire::ModifierFichier(const char* pcFichier)
{
	LECModifierFichier(pcFichier);
}

void CTrajectoire::LireFichier()
{
	Load(); //Ouverture du fichier (sera fermé lorsque le destructeur sera appelé)

	unsigned int uiBoucle;
	unsigned int uiBoucle2;
	unsigned int uiNbVecteur = 4;
	int uiNbElements;
	unsigned int uiElement = 0; // Elements créés
	unsigned int uiVariables = 0; // Eléments variables détéctés
	double dValeur;
	char* pcTexte;
	bool bSuccess;

	// Lecture du nombre de variable
	pcTexte = FindIntInLine('\0');
	bSuccess = ToInt(pcTexte, uiNbElements);
	free(pcTexte);

	TRAMatrice = (CMatrice*)malloc(sizeof(CMatrice) * 4);
	if (bSuccess == false)
	{
		// Exception : Le nombre de variable n'est pas spécifié
		return;
	}
	else if (uiNbElements < 1)
	{
		// Exception : Le nombre de variable n'est pas correct (iNbElements > 1)
		return;
	}

	uiNbPoints = uiNbElements;

	//Allocation de a liste de matrice
	TRAMatrice = new CMatrice[4];


	NextLine();
	//¨Premier point du trajectoire
	
	//pcTexte = SplitLineBySlash(4);
	char** ppcSplit;
	char** ppcVecteurs;

	for (uiNbElements = 0; uiNbElements < uiNbPoints; uiNbElements++)
	{
		char** ppcSplit = SplitLineBySeparateur(uiNbVecteur , 47);
		TRAMatrice[uiNbElements].MATAjouterColonnes(4);
		TRAMatrice[uiNbElements].MATAjouterLignes(4);
		for (uiBoucle = 0; uiBoucle < uiNbVecteur  ; uiBoucle++)
		{
			ppcVecteurs = SplitWordBySeparateur(ppcSplit[uiBoucle], uiNbVecteur , 44);
			
			for (uiBoucle2 = 0; uiBoucle2 < uiNbVecteur -1 ; uiBoucle2++)
			{
				TRAMatrice[uiNbElements].MATModiferElement(uiBoucle2, uiBoucle, atof(ppcVecteurs[uiBoucle2]));

			}
			



		}
		if (uiBoucle = uiBoucle2)
		{
			TRAMatrice[uiNbElements].MATModiferElement(uiBoucle2, uiBoucle, 1);
		}
		NextLine();

	}
	
	



}


void CTrajectoire::AffichierMatrices()
{
	for (unsigned int uiBoucle = 0; uiBoucle < uiNbPoints; uiBoucle++)
	{
		TRAMatrice[uiBoucle].MATLireNbLigne() << '\n'; 
		TRAMatrice[uiBoucle].MATAffiche();
		
	}
}

