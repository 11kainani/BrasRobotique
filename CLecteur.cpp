#include <iostream>
#include <assert.h>
#include <fstream>

#include "CLecteur.h"


CLecteur::CLecteur(char* pcCheminFichier) : CLecteurBase(pcCheminFichier)
{
	pVARListe = nullptr;
	ppVARVariables = nullptr;
	uiNbVariables = uiNbElements = 0;
}

CLecteur::CLecteur()
{
	pVARListe = nullptr;
	ppVARVariables = nullptr;
	uiNbVariables = uiNbElements = 0;
}

CLecteur::~CLecteur()
{
	unsigned int uiBoucle = 0;
	if(ppVARVariables != nullptr)
	{
		for(uiBoucle = 0; uiBoucle < uiNbVariables; uiBoucle++)
		{
			ppVARVariables[uiBoucle] = nullptr;
		}
		free(ppVARVariables);
	}
	
	if(pVARListe != nullptr)
	{
		for(uiBoucle = 0; uiboucle < uiNbElements; uiBoucle++)
		{
			pVARListe[uiBoucle].~Destroy();
		}
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
	if(uiIndice > uiNbElements) { return nullptr; }
	return pVARListe[uiIndice];
}

VariableArticulaire& CLecteur::LireVariable(unsigned int uiIndice)
{
	if(uiIndice > uiNbVariables) { return nullptr; }
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
	Load(); // Ouverture du fichier (sera fermé lorsque le destructeur sera appelé)
	
	// Lecture du nombre de variable
	int iNbElements;
	unsigned int uiElement = 0; // Elements créés
	unsigned int uiVariables = 0; // Eléments variables détéctés
	double dValeur;
	char* pcTexte;
	bool bSuccess;
	
	pcTexte = FindIntInLine('\0');
	bSuccess = ToInt(pcTexte, iNbElements);
	free(pcTexte);
	
	if(bSuccess == false)
	{
		// Exception : Le nombre de variable n'est pas spécifié
		return;
	}
	else if(iNbElements < 1)
	{
		// Exception : Le nombre de variable n'est pas correct (iNbElements >= 1)
		return;
	}
	
	// Allocation du tableau de variable
	pVARListe = (VariableArticulaire*)malloc(sizeof(VariableArticulaire)*iNbElements);
	
	NextLine();
	
	// Lecture des variables
	while(EmptyLine() == false)
	{
		
		// Recherche d'un réel
		pcTexte = FindDoubleInLine(',');
		bSuccess = ToDouble(pcTexte, dValeur);
		free(pcTexte);
		
		// S'il n'y a pas pu avoir de conversion
		if(bSuccess == false)
		{
			RewindTo(',', 1+(EmptyLine() ? 0 : 1), true); // On revient en arrière d'un ou deux cran si suite vide ou non
			bSuccess = FindWordInFileLine("X", '[');  // S'agit-il d'une valeur variable ?
			
			if(bSuccess)
			{
				// Recherche de la valeur minimale de l'interval
				pcTexte = FindDoubleInLine(',');
				bSuccess = ToDouble(pcTexte, dValeur);
				free(pcTexte);
				
				if(bSuccess)
				{
					pVARListe[uiElement].ModifierValeur(dValeur);
					pVARListe[uiElement].ModifierMin(dValeur);
				}
				else
				{
					// Exception : Format non respecté
				}
				
				// Recherche de la valeur maximal de l'interval
				pcTexte = FindDoubleInLine(']');
				bSuccess = ToDouble(pcTexte, dValeur);
				free(pcTexte);
				
				if(bSuccess && dValeur >= pVARListe[uiElement].LireMin())
				{
					pVARListe[uiElement].ModifierMax(dValeur);
					pVARListe[uiElement].ModifierVariable = (dValeur > pVARListe[uiElement].LireMin());
				}
				else
				{
					// Exception : Format non respecté
				}
				
				uiVariables++; // Un élément variable a été détecté dans le format correct	
			}
			else
			{
				// Exception : Format non respecté	
			}
			
			FindWordInFileLine("", ','); // On passe à l'élément suivant dans le fichier
			
		}
		else
		{
			pVARListe[uiElement].ModifierValeur(dValeur);
			pVARListe[uiElement].ModifierMin(dValeur);
			pVARListe[uiElement].ModifierMax(dValeur);
			pVarListe[uiElement].ModifierVariable(false);
		}
		
		uiElement++; // Un élément a été créé
		
	}
	
	
	uiNbElements = uiElement;
	uiNbVariables = uiVariables;
	
	// Allocation du tableau de pointeurs
	ppVARVariables = (VariableArticulaire**)malloc(sizeof(VariableArticulaire*)*uiNbVariables);
	uiVariables = 0;
	
	// uiVariables = variable i du tableau ppVARVariables
	// uiElement = element j du tableau pVARListe
	
	// Ajout des adresses des éléments variables dans le tableau
	for(uiElement = 0; uiElement < uiNbElements; uiElement++)
	{
		// Si l'élément est variable
		if(pVARListe[uiElement].LireVariable())
		{
			// Ajout de l'élément dans le tableau
			ppVARVariables[uiVariables] = &(pVARListe[uiElement]);
			uiVariables++;
		}
	}
	
}

void CLecteur::ModifierFichier(const char* pcFichier)
{
}
