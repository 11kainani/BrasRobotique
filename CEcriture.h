#ifndef CECRITUREH
#define CECRITUREH
#include <iostream>
#include <fstream>
#include "DenavitParameter.h"
using namespace std;


/**
 * @brief Classe permettant d'ecrire dans un fichier texte des parametres Denavit
*/
class CEcriture
{

private:
	const char* pcECRCheminFichier;
	ofstream fichier;

public:
	/**
	* Constrcuteur par default
	 * @brief Constructeur par default qui cree un objet CEcriture et qui initialise tous les element de CEcriture a null
	*/
	CEcriture();
	/**
	* Costructeur de confort
	 * @brief Constructeur de confort qui cree un objet CEcriture et qui initialise pcECRCheminFichier
	 * @param pcChemin
	 * @param truncMode
	*/
	CEcriture(const char* pcChemin, bool truncMode = true);
	/**
	* Destructeur
	* @Brief Destructeur par default qui s'occupe de desallouer et detruire l'objet CEcriture
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
	 * @brief Methode qui ecrit sur un nouveau fichier texte.
	 Si le fichier existe deja: les donnees existant seront supprimees
	 Si le fichier n'existe pas : un nouveau fichier avec le nom choisit.
	*/
	void EcrireParametre(DenavitParameter parametre);


private:
	/**
	* Open
	 * @brief Ouvre un fichier texte. Si le fichier texte n'existe pas, on le cree.
	 * @param newFile vaut true si on veut ouvrir en mode trunc sinon on ouvre le fichier en mode append
	 *
	*/
	void open(bool newFile = false);

	/**
	 * @brief methode pour fermer un fichier
	*/
	void close();

};
#endif