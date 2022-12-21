#ifndef CECRITUREH
#define CECRITUREH

#include <iostream>
#include <assert.h>
#include <fstream>
#include "DenavitParameter.h"
using namespace std;
#endif

/**
 * @brief Classe permettant d'�crire dans un fichier texte des param�tres Denavit
*/
class CEcriture
{
public:
	/**
	* Constrcuteur par default
	 * @brief Constructeur par default qui cr�e un objet CEcriture et qui initialise tous les �lement de CEcriture � null
	*/
	CEcriture();
	/**
	* Costructeur de confort
	 * @brief Constructeur de confort qui cr�e un objet CEcriture et qui initialise pcECRCheminFichier
	 * @param pcChemin 
	*/
	CEcriture(char* pcChemin);
	/**
	* Constructeur de confort
	 * @brief Constructeur de confort qui cr�e et initialise tous les membres de l'objet CEcriture
	 * @param pcChemin 
	 * @param pDENParameter 
	 * @param uiNbParameter 
	*/
	CEcriture(char* pcChemin, DenavitParameter** pDENParameter, unsigned int uiNbParameter);
	/**
	* Destructeur 
	* @Brief Destructeur par default qui s'occupe de d�sallouer et d�truire l'objet CEcriture
	*/
	~CEcriture();

	/**
	* ECREcrireNouveauFiche
	 * @brief M�thode qui �crit sur un nouveau fichier texte. 
	 Si le fichier existe d�j�: les donn�es existant seront supprim�es  
	 Si le fichier n'existe pas : un nouveau fichier avec le nom choisit.
	*/
	void ECREcrireNouveauFichier();

	/**
	* ECRContinuerEcriture
	 * @brief  M�thode qui �crit sur un fichier txt.
	 * Si le fichier existe d�j�: On �crirera � la suite 
	 * Si le fichier n'existe pas : un nouveau fichier sera cr�e.
	*/
	void ECRContinuerEcriture();


	/**
	* Open
	 * @brief Ouvre un fichier texte. Si le fichier texte n'existe pas, on le cr�e. 
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

