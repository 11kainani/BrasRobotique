#include "CEcriture.h"
#include "CException.h"
#include <ostream>
using namespace std;

#define ERREUR_LORS_DE_L_OUVERTURE 1
#define ERREUR_LORS_DE_LA_FERMETURE 2

CEcriture::CEcriture()
{
	pcECRCheminFichier = nullptr;

}

CEcriture::CEcriture(const char* pcChemin, bool truncMode)
{
	pcECRCheminFichier = pcChemin;
	open(truncMode);
	close();
}

CEcriture::~CEcriture()
{
	if (fichier.is_open())
	{
		close();
	}
}

void CEcriture::Ecrire(const char* texte)
{
	unsigned int taille = 0;
	open();

	while (texte[taille] != '\0')
	{
		taille++;
	}

	fichier.write(texte, taille);

	close();
}

void CEcriture::EcrireParametre(DenavitParameter parametre)
{
	/*Sauvgarde de la sortie standard*/
	streambuf* standardOut = cout.rdbuf();
	/*Ouverture du fichier en mode append*/
	open();
	/*Redirection de la sortie standard*/
	cout.rdbuf(fichier.rdbuf());

	parametre.Affiche();

	/*Reset de la sortie standard*/
	cout.rdbuf(standardOut);
	/*Fermeture du ofstream*/
	close();


}

void CEcriture::Ecrire(DenavitParameter DENparametre, double dEcrire, int indice)
{
	unsigned int uiBoucle;
	unsigned int uiChoix=0;
	char buffer[20];
	
	DENparametre.UpdateDENVariables();
	if (DENparametre.LireNbVariables() == 0 || indice > DENparametre.LireNbVariables())
	{
		cout << "Ce parametre de Denavit n'a pas de variable articuaire qui varie."; 
	}
	else
	{
		for (uiBoucle = 0; uiBoucle < NB_VARIABLES; uiBoucle++)
		{
			if (DENparametre.LireBVariable(uiBoucle) == true)
			{
				uiChoix++;
				
			}
			if (uiChoix == indice)
			{
				break;
			}

		}

		switch (uiBoucle)
		{
		case 0: //Ecriture du double en char*
			sprintf_s(buffer, "Theta %f", dEcrire);
			break;
		case 1://Ecriture du double en char*
			sprintf_s(buffer, "D %f", dEcrire);
			break;
		case 2://Ecriture du double en char*
			sprintf_s(buffer, "Alpha %f", dEcrire);
			break;
		case 3://Ecriture du double en char*
			sprintf_s(buffer, "A %f", dEcrire);
			break;

		default:
			break;
		}
		cout << buffer;
	}

	
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