#include "CTrajectoire.h"

CTrajectoire::CTrajectoire() : CLecteurBase()
{
	TRAMatrice = nullptr;
	uiMatriceLues = 0;
	uiNbPoints = 0;
}

CTrajectoire::CTrajectoire(const char* pcCheminFicher) : CLecteurBase(pcCheminFicher)
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
	unsigned int uiNbVecteur = 4;
	unsigned int uiNbComposants = 3;
	unsigned int uiBoucle, uiBoucle2, uiNbElements;
	int iNbPoints;
	double dValeur;
	char* pcTexte;
	bool bSuccess;


	Load(); //Ouverture du fichier (sera ferm� lorsque le destructeur sera appel�)

	// Lecture du nombre de points
	pcTexte = FindIntInLine('\0');
	bSuccess = ToInt(pcTexte, iNbPoints);
	free(pcTexte);

	if (bSuccess == false)
	{
		// Exception : Le nombre de points n'est pas sp�cifi�
		cout << "Erreur de Trajectoire : Le nombre de points n'est pas dans le fichier";
		return;
	}
	else if (iNbPoints < 1)
	{
		// Exception : Le nombre de variable n'est pas correct (iNbPoints > 0)
		cout << "Erreur de Trajectoire : Le nombre de points est inferieur ou egal a 0";
		return;
	}

	// On enregistre le nombre de points
	uiNbPoints = iNbPoints;

	// Allocation de la liste de matrice
	TRAMatrice = new CMatrice[uiNbPoints];
	

	// Pour chaque point Et s'il existe une ligne pour ce point
	for (uiNbElements = 0; uiNbElements < uiNbPoints && NextLine(); uiNbElements++)
	{
		// Cr�ation d'une matrice identit� 4x4
		TRAMatrice[uiNbElements] = CMatrice::MATIdentity(uiNbComposants+1, uiNbVecteur);

		// Pour chaque vecteur du point
		for (uiBoucle = 0; uiBoucle < uiNbVecteur; uiBoucle++)
		{
			// Lecture des composantes du vecteur
			for (uiBoucle2 = 0; uiBoucle2 < uiNbComposants; uiBoucle2++)
			{
				// Recherche d'un r�el suivit d'un '/' si dernier composant sinon r�el suivit d'un ','
				pcTexte = FindDoubleInLine((uiBoucle2 == uiNbComposants-1 ? '/' : ','));
				bSuccess = ToDouble(pcTexte, dValeur);

				if (bSuccess == false)
				{
					// Exception : Valeur r�elle incorrecte
					cout << "Erreur de Trajectoire au point " << uiNbElements + 1 <<
						" a la composante " << uiNbComposants + 1 << " : Valeur reelle incorrecte\n";
					cout << "Valeur lue : " << pcTexte;
					free(pcTexte);
					return;
				}
				free(pcTexte);

				// Affectation du r�el dans la matrice 4x4
				TRAMatrice[uiNbElements].MATModiferElement(uiBoucle2, uiBoucle, dValeur);
			}

			// Affectation en derni�re ligne de la matrice (Si derni�re colonne 1 sinon 0)
			TRAMatrice[uiNbElements].MATModiferElement(uiNbComposants, uiBoucle, (uiBoucle == uiNbVecteur-1 ? 1 : 0));
		}

		uiMatriceLues++;

	}


	if (uiMatriceLues != uiNbPoints)
	{
		// Exception : Le nombre de points lus ne correspond pas
		cout << "Erreur de Trajectoire : Le nombre de points lu ne correspond pas au nombre de matrices lues\n";
		return;
	}
	
	



}


void CTrajectoire::AffichierMatrices()
{
	for (unsigned int uiBoucle = 0; uiBoucle < uiNbPoints; uiBoucle++)
	{
		cout << TRAMatrice[uiBoucle].MATLireNbLigne() << '\n'; 
		TRAMatrice[uiBoucle].MATAffiche();
		
	}
}

