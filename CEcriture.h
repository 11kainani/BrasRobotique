#ifndef CECRITUREH
#define CECRITUREH

#include <iostream>
#include <assert.h>
#include <fstream>
#include "DenavitParameter.h"
using namespace std;
#endif

/**
 * @brief Classe permettant d'écrire dans un fichier texte des paramètres Denavit
*/
class CEcriture
{
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
	*/
	CEcriture(char* pcChemin);
	/**
	* Constructeur de confort
	 * @brief Constructeur de confort qui crée et initialise tous les membres de l'objet CEcriture
	 * @param pcChemin 
	 * @param pDENParameter 
	 * @param uiNbParameter 
	*/
	CEcriture(char* pcChemin, DenavitParameter** pDENParameter, unsigned int uiNbParameter);
	/**
	* Destructeur 
	* @Brief Destructeur par default qui s'occupe de désallouer et détruire l'objet CEcriture
	*/
	~CEcriture();

	/**
	* ECREcrireNouveauFiche
	 * @brief Méthode qui écrit sur un nouveau fichier texte. 
	 Si le fichier existe déjà: les données existant seront supprimées  
	 Si le fichier n'existe pas : un nouveau fichier avec le nom choisit.
	*/
	void ECREcrireNouveauFichier();

	/**
	* ECRContinuerEcriture
	 * @brief  Méthode qui écrit sur un fichier txt.
	 * Si le fichier existe déjà: On écrirera à la suite 
	 * Si le fichier n'existe pas : un nouveau fichier sera crée.
	*/
	void ECRContinuerEcriture();


	/**
	* Open
	 * @brief Ouvre un fichier texte. Si le fichier texte n'existe pas, on le crée. 
	 * @param newFile vaut true si on veut ouvrir en mode trunc sinon on ouvre le fichier en mode append
	 * 
	*/
	void open(bool newFile);

	/**
	 * @brief methode pour fermer un fichier
	*/
	void close();

private:
	char* pcECRCheminFichier;
	DenavitParameter** ppDENListe;
	unsigned int uiECRNbDenavit;
	ofstream fichier;
};

