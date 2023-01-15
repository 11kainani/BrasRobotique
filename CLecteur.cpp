#include <iostream>
#include <fstream>

#include "CLecteur.h"


CLecteur::CLecteur(const char* pcCheminFichier) : CLecteurBase(pcCheminFichier)
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
		delete[] pVARListe;
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

unsigned int CLecteur::LireNbParametres()
{
	return uiNbParametres;
}

VariableArticulaire& CLecteur::LireElement(unsigned int uiIndice)
{
	return pVARListe[uiIndice];
}

VariableArticulaire& CLecteur::LireVariable(unsigned int uiIndice)
{
	return *(ppVARVariables[uiIndice]);
}

DenavitParameter& CLecteur::LireParametre(unsigned int uiIndice)
{
	return pDENParametres[uiIndice];
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

	unsigned int uiBoucle;
	int iNbParametres;
	unsigned int uiElement = 0; // Elements créés
	unsigned int uiVariables = 0; // Eléments variables détéctés
	double dValeur;
	char* pcTexte;
	bool bSuccess;
	CException exc;

	// Lecture du nombre de variable
	pcTexte = FindIntInLine('\0');
	bSuccess = ToInt(pcTexte, iNbParametres);
	free(pcTexte);

	if (bSuccess == false)
	{
		// Exception : Le nombre de paramètres n'est pas spécifié
		cout << "Nombre de parametres introuvable dans le fichier\n";
		exc.EXCModifierValeur(EXC_NB_PARAMS_MANQUANT);
		throw exc;
	}
	else if (iNbParametres < 1)
	{
		// Exception : Le nombre de paramètres n'est pas correct (iNbParametres >= 1)
		cout << "Nombre de parametres negatif ou egal a 0\n";
		exc.EXCModifierValeur(EXC_NB_PARAMS_NEGATIF);
		throw exc;
	}

	// Allocation du tableau de variable
	pVARListe = new VariableArticulaire[iNbParametres * 4];

	NextLine();

	while (EmptyLine() == false && (int)uiNbParametres < iNbParametres) // Tant que la ligne n'est pas vide
	{
		// Lecture des 4 premières variables de la ligne
		while (((uiElement > 0 && (uiElement % 4) == 0) == false))
		{

			// Recherche d'un réel
			pcTexte = FindDoubleInLine(',');
			bSuccess = ToDouble(pcTexte, dValeur);
			free(pcTexte);

			// S'il n'y a pas pu avoir de conversion
			if (bSuccess == false)
			{
				RewindTo(',', 1 + (EmptyLine() ? 0 : 1), true); // On revient en arrière d'un ou deux cran si suite vide ou non
				bSuccess = FindWordInFileLine("X", '[');  // S'agit-il d'une valeur variable ?

				if (bSuccess == false)
				{
					// Exception : Format non respecté	
					cout << "Format Variable incorrect\n";
					exc.EXCModifierValeur(EXC_VARIABLE_X_ABSENTE);
					throw exc;
				}


				// Recherche de la valeur minimale de l'interval
				pcTexte = FindDoubleInLine(',');
				bSuccess = ToDouble(pcTexte, dValeur);
				free(pcTexte);

				if (bSuccess == false)
				{
					// Exception : Format non respecté
					cout << "Format valeur min incorrect\n";
					exc.EXCModifierValeur(EXC_VARIABLE_MIN);
					throw exc;
				}

				// conversion en radian si première et troisième variable du paramètre denavit
				if (uiElement % 2 == 0)
				{
					pVARListe[uiNbParametres * 4 + uiElement].ModifierBAngulaire(true);
					dValeur = dValeur * PI / 180; 
				}

				pVARListe[uiNbParametres* 4 + uiElement].ModifierValeur(dValeur);
				pVARListe[uiNbParametres* 4 + uiElement].ModifierMin(dValeur);

				// Recherche de la valeur maximal de l'interval
				pcTexte = FindDoubleInLine(']');
				bSuccess = ToDouble(pcTexte, dValeur);
				free(pcTexte);

				if (bSuccess && dValeur >= pVARListe[uiNbParametres* 4 + uiElement].LireMin())
				{
					pVARListe[uiNbParametres* 4 + uiElement].ModifierMax(dValeur);
					pVARListe[uiNbParametres* 4 + uiElement].ModifierBVariable(true);
				}
				else
				{
					// Exception : Format non respecté
					cout << "Format valeur max incorrect\n";
					exc.EXCModifierValeur(EXC_VARIABLE_MAX);
					throw exc;
				}

				uiVariables++; // Un élément variable a été détecté dans le format correct	

				FindWordInFileLine("", ','); // On passe à l'élément suivant dans le fichier

			}
			else
			{
				// conversion en radian si première et troisième variable du paramètre denavit
				if (uiElement % 2 == 0)
				{
					pVARListe[uiNbParametres * 4 + uiElement].ModifierBAngulaire(true);
					dValeur = dValeur * PI / 180;
				}

				pVARListe[uiNbParametres * 4 + uiElement].ModifierMin(dValeur);
				pVARListe[uiNbParametres * 4 + uiElement].ModifierMax(dValeur);
				pVARListe[uiNbParametres * 4 + uiElement].ModifierValeur(dValeur);
				pVARListe[uiNbParametres * 4 + uiElement].ModifierBVariable(false);
			}

			uiElement++; // Un élément a été créé

		}

		// Remise à zéro du nombre d'éléments créés
		uiElement = 0;

		// S'il reste des variables sur la ligne
		if (EmptyLine() == false)
		{

			// Exception : Il n'y a pas exactement 4 variables par ligne dans le fichier	
			cout << "Erreur Parametre " << (uiNbParametres+1) << " incomplet\n";
			exc.EXCModifierValeur(EXC_PARAMETRE_INCOMPLET);
			throw exc;
		}


		// Création d'un parametre de Denavit
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
			pDENParametres[uiNbParametres - 1].SetVariable(uiBoucle, &(pVARListe[(uiNbParametres-1)*4 + uiBoucle]));
		}

		NextLine();  // Passage à la ligne suivante


	}



	// Enregistrement des éléments variables
	uiNbElements = uiNbParametres*4;
	uiNbVariables = uiVariables;


	if (uiNbVariables <= 0) { return; }
	// Allocation du tableau de pointeurs
	ppVARVariables = (VariableArticulaire**)malloc(sizeof(VariableArticulaire*)*uiNbVariables);
	uiVariables = 0;

	// uiVariables = variable i du tableau ppVARVariables
	// uiElement = element j du tableau pVARListe

	// Ajout des adresses des éléments variables dans le tableau
	for (uiElement = 0; uiElement < uiNbElements; uiElement++)
	{
		// Si l'élément est variable
		if (pVARListe[uiElement].LireBVariable())
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