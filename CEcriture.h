#ifndef CECRITUREH
#define CECRITUREH

#include <iostream>
#include <fstream>
#include "DenavitParameter.h"
using namespace std;
#endif

/**
 * @brief Classe permettant d'écrire dans un fichier texte des paramètres Denavit
*/
class CEcriture
{

private:
	const char* pcECRCheminFichier;
	ofstream fichier;

public:
	/**
	* Constrcuteur par default
	 * @brief Constructeur par default qui crée un objet CEcriture et qui initialise tous les élement de CEcriture à null
	*/
	CEcriture();
	/**
	* Costructeur de confort
	 * @brief Constructeur de confort qui crée un objet CEcriture et qui initialise pcECRCheminFichier
	 * @param pcChemin
	 * @param truncMode
	*/
	CEcriture(const char* pcChemin, bool truncMode = true);
	/**
	* Destructeur
	* @Brief Destructeur par default qui s'occupe de désallouer et détruire l'objet CEcriture
	*/
	~CEcriture();

	/**
	* Ecrire
	* @Brief Ecrit un texte dans le fichier en mode append
	* @param texte
	*/
	void Ecrire(const char* texte);

	/**
	* ECREcrireNouveauFiche
	 * @brief Méthode qui écrit sur un nouveau fichier texte.
	 Si le fichier existe déjà: les données existant seront supprimées
	 Si le fichier n'existe pas : un nouveau fichier avec le nom choisit.
	*/
	void EcrireParametre(DenavitParameter parametre);

	void Ecrire(DenavitParameter DENparametre, double dEcrire, int indice);


private:
	/**
	* Open
	 * @brief Ouvre un fichier texte. Si le fichier texte n'existe pas, on le crée.
	 * @param newFile vaut true si on veut ouvrir en mode trunc sinon on ouvre le fichier en mode append
	 *
	*/
	void open(bool newFile = false);

	/**
	 * @brief methode pour fermer un fichier
	*/
	void close();

};