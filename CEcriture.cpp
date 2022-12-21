#include "CEcriture.h"
#include "CException.h"
#include <ostream>
using namespace std;

#define ERREUR_LORS_DE_L_OUVERTURE 1
#define ERREUR_LORS_DE_LA_FERMETURE 2
CEcriture::CEcriture()
{
	pcECRCheminFichier = nullptr;
	ppDENListe = nullptr;
	uiECRNbDenavit = NULL;

}

CEcriture::CEcriture(char* pcChemin)
{
	pcECRCheminFichier = pcChemin;
	ppDENListe = nullptr;
	uiECRNbDenavit = NULL;
	
}

CEcriture::CEcriture(char* pcChemin, DenavitParameter** pDENParameter, unsigned int uiNbParameter)
{
	pcECRCheminFichier = pcChemin;
	ppDENListe = pDENParameter;
	uiECRNbDenavit = uiNbParameter;
}

CEcriture::~CEcriture()
{
	if (fichier.is_open())
	{
		close();
	}

	if (pcECRCheminFichier != nullptr)
	{
		pcECRCheminFichier = nullptr;
	}
	if (ppDENListe != nullptr)
	{
		free(ppDENListe);
	}
	uiECRNbDenavit = NULL;
}

void CEcriture::ECRContinuerEcriture()
{
	unsigned int  uiBoucle;
	/*Sauvgarde de la sortie standard*/
	streambuf* standardOut = cout.rdbuf();
	/*Ouverture du fichier en mode append*/
	open(false);
	/*Redirection de la sortie standard*/
	cout.rdbuf(fichier.rdbuf());

	cout << "Parametre Denavit :" << "\n";

	/*Ecriture dans le text*/
	for (uiBoucle = 0; uiBoucle < uiECRNbDenavit; uiBoucle++)
	{
		ppDENListe[uiBoucle]->Affiche();
	}
	cout << " -------------" << "\n";

	/*Reset de la sortie standard*/
	cout.rdbuf(standardOut);
	/*Fermeture du ofstream*/
	close();
}

void CEcriture::ECREcrireNouveauFichier()
{
	unsigned int  uiBoucle;
	/*Sauvgarde de la sortie standard*/
	streambuf* standardOut = cout.rdbuf();
	/*Ouverture du fichier en mode trunc*/
	open(true);
	/*Redirection de la sortie standard*/
	cout.rdbuf(fichier.rdbuf());

	cout << "Parametre Denavit :" << "\n";

	/*Ecriture dans le text*/
	for (uiBoucle = 0; uiBoucle < uiECRNbDenavit; uiBoucle++)
	{
		ppDENListe[uiBoucle]->Affiche();
	}
	cout << " -------------" << "\n";

		/*Reset de la sortie standard*/
	cout.rdbuf(standardOut);
	/*Fermeture du ofstream*/
	close();
	

}

void CEcriture::open(bool newFile)
{
	CException EXCMistake;
	if (newFile == true)
	{
		fichier.open(pcECRCheminFichier, fstream::trunc);
	}
	else
	{
		fichier.open(pcECRCheminFichier, fstream::app);
	}
	
	if (fichier.is_open() == false)
	{
		EXCMistake.EXCModifierValeur(ERREUR_LORS_DE_L_OUVERTURE);
		throw EXCMistake;
	}

}

void CEcriture::close()
{
	CException EXCMistake;
	fichier.close();
	if (fichier.is_open())
	{
		EXCMistake.EXCModifierValeur(ERREUR_LORS_DE_LA_FERMETURE);
		throw EXCMistake;
	}
}

