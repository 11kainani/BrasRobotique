#include <iostream>
#include <fstream>

#include "CLecteur.h"


CLecteur::CLecteur(char* pcCheminFichier) : CLecteurBase(pcCheminFichier)
{
	pVARListe = nullptr;
	ppVARVariables = nullptr;
	pDENParametres = nullptr;
	uiNbVariables = uiNbElements = uiNbParametres = 0;
}

CLecteur::CLecteur()
{
	pVARListe = nullptr;
	ppVARVariables = nullptr;
	pDENParametres = nullptr;
	uiNbVariables = uiNbElements = uiNbParametres = 0;
}

CLecteur::~CLecteur()
{
	unsigned int uiBoucle = 0;
	if (ppVARVariables != nullptr)
	{
		for (uiBoucle = 0; uiBoucle < uiNbVariables; uiBoucle++)
		{
			ppVARVariables[uiBoucle] = nullptr;
		}
		free(ppVARVariables);
	}

	if (pDENParametres != nullptr)
	{
		delete[] pDENParametres;
	}

	if (pVARListe != nullptr)
	{
		free(pVARListe);
	}

}

unsigned int CLecteur::LireNbElements()
{
	return uiNbElements;
}

unsigned int CLecteur::LireNbVariables()
{
	return uiNbVariables;
}

VariableArticulaire& CLecteur::LireElement(unsigned int uiIndice)
{
	return pVARListe[uiIndice];
}

VariableArticulaire& CLecteur::LireVariable(unsigned int uiIndice)
{
	return *(ppVARVariables[uiIndice]);
}

/*
bool CLecteur::LECFindElement(char* pcLigne, char* pccMot)
{
	return false;
}

int CLecteur::LECFindColonneEtLigne(char* pcPhrase)
{
	return 0;
}
*/

void CLecteur::LireFichier()
{
	Load(); // Ouverture du fichier (sera ferm� lorsque le destructeur sera appel�)

	unsigned int uiBoucle;
	int iNbElements;
	unsigned int uiElement = 0; // Elements cr��s
	unsigned int uiVariables = 0; // El�ments variables d�t�ct�s
	double dValeur;
	char* pcTexte;
	bool bSuccess;

	// Lecture du nombre de variable
	pcTexte = FindIntInLine('\0');
	bSuccess = ToInt(pcTexte, iNbElements);
	free(pcTexte);

	if (bSuccess == false)
	{
		// Exception : Le nombre de variable n'est pas sp�cifi�
		return;
	}
	else if (iNbElements < 1)
	{
		// Exception : Le nombre de variable n'est pas correct (iNbElements >= 1)
		return;
	}

	// Allocation du tableau de variable
	pVARListe = (VariableArticulaire*)malloc(sizeof(VariableArticulaire)*iNbElements*4);

	NextLine();

	while (EmptyLine() == false) // Tant que la ligne n'est pas vide
	{
		// Lecture des variables jusqu'� la fin de la ligne
		while (EmptyLine() == false)
		{

			// Recherche d'un r�el
			pcTexte = FindDoubleInLine(',');
			bSuccess = ToDouble(pcTexte, dValeur);
			free(pcTexte);

			// S'il n'y a pas pu avoir de conversion h
			if (bSuccess == false)
			{
				RewindTo(',', 1 + (EmptyLine() ? 0 : 1), true); // On revient en arri�re d'un ou deux cran si suite vide ou non
				bSuccess = FindWordInFileLine("X", '[');  // S'agit-il d'une valeur variable ?

				if (bSuccess)
				{
					// Recherche de la valeur minimale de l'interval
					pcTexte = FindDoubleInLine(',');
					bSuccess = ToDouble(pcTexte, dValeur);
					free(pcTexte);

					if (bSuccess)
					{
						pVARListe[uiElement].ModifierValeur(dValeur);
						pVARListe[uiElement].ModifierMin(dValeur);
					}
					else
					{
						// Exception : Format non respect�
					}

					// Recherche de la valeur maximal de l'interval
					pcTexte = FindDoubleInLine(']');
					bSuccess = ToDouble(pcTexte, dValeur);
					free(pcTexte);

					if (bSuccess && dValeur >= pVARListe[uiElement].LireMin())
					{
						pVARListe[uiElement].ModifierMax(dValeur);
						pVARListe[uiElement].ModifierBVariable(dValeur > pVARListe[uiElement].LireMin());
					}
					else
					{
						// Exception : Format non respect�
					}

					uiVariables++; // Un �l�ment variable a �t� d�tect� dans le format correct	
				}
				else
				{
					// Exception : Format non respect�	
				}

				FindWordInFileLine("", ','); // On passe � l'�l�ment suivant dans le fichier

			}
			else
			{
				pVARListe[uiElement].ModifierValeur(dValeur);
				pVARListe[uiElement].ModifierMin(dValeur);
				pVARListe[uiElement].ModifierMax(dValeur);
				pVARListe[uiElement].ModifierBVariable(false);
			}

			uiElement++; // Un �l�ment a �t� cr��

		}


		// Cr�ation d'un parametre de Denavit apr�s lecture de 4 variables sur la ligne
		if (uiElement > 0 && (uiElement % 4) == 0)
		{
			uiNbParametres++;
			if (pDENParametres == nullptr)
			{
				pDENParametres = new DenavitParameter[1];
			}
			else
			{
				// Reallocation
				DenavitParameter* temp = new DenavitParameter[uiNbParametres];
				for (uiBoucle = 0; uiBoucle < uiNbParametres - 1; uiBoucle++)
				{
					temp[uiBoucle] = pDENParametres[uiBoucle];
				}
				delete[] pDENParametres;
				pDENParametres = temp;
			}

			for (uiBoucle = 0; uiBoucle < 4; uiBoucle++)
			{
				pDENParametres[uiNbParametres - 1].SetVariable(uiBoucle, &(pVARListe[uiElement - 4 + uiBoucle]));
			}

			NextLine();  // Passage � la ligne suivante
		}
		else
		{
			// Exception : Il n'y a pas exactement 4 variables par ligne dans le fichier	
		}

	}



	// Enregistrement des �l�ments variables
	uiNbElements = uiElement;
	uiNbVariables = uiVariables;


	if (uiNbVariables <= 0) { return; }
	// Allocation du tableau de pointeurs
	ppVARVariables = (VariableArticulaire**)malloc(sizeof(VariableArticulaire*)*uiNbVariables);
	uiVariables = 0;

	// uiVariables = variable i du tableau ppVARVariables
	// uiElement = element j du tableau pVARListe

	// Ajout des adresses des �l�ments variables dans le tableau
	for (uiElement = 0; uiElement < uiNbElements; uiElement++)
	{
		// Si l'�l�ment est variable
		if (pVARListe[uiElement].LireBVariable())
		{
			// Ajout de l'�l�ment dans le tableau
			ppVARVariables[uiVariables] = &(pVARListe[uiElement]);
			uiVariables++;
		}
	}

}

void CLecteur::ModifierFichier(const char* pcFichier)
{
}
