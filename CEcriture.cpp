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
