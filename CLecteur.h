#ifndef C_LECTEUR_H
#define C_LECTEUR_H

#include <iostream>
#include <fstream>

#include "CLecteurBase.h"
#include "VariableArticulaire.h"
#include "DenavitParameter.h"


#define PI 3.14159265


using std::ifstream;
using namespace std;

#define EXC_NB_PARAMS_MANQUANT 1
#define EXC_NB_PARAMS_NEGATIF 2
#define EXC_VARIABLE_X_ABSENTE 3
#define EXC_VARIABLE_MIN 4
#define EXC_VARIABLE_MAX 5
#define EXC_PARAMETRE_INCOMPLET 6

class CLecteur : public CLecteurBase
{
private:

	VariableArticulaire* pVARListe; 		// Liste dynamique d'objet VariableArticulaire
	VariableArticulaire** ppVARVariables; 	// Liste dynamique de pointeurs d'objet VariableArticulaire
	DenavitParameter* pDENParametres; 	// Liste dynamique de paramètres de Denavit
	unsigned int uiNbElements; 		// Nombre d'objets contenus dans pVARListe
	unsigned int uiNbVariables; 		// Nombre de pointeurs contenus dans ppVARVariables
	unsigned int uiNbParametres;		// Nombre de paramètres de Denavit dans pDENParametres



public:
	/**
	 * @brief Constructeur de confort qui crée et initialise l'objet CLecteur avec le chemin du fichier
	 * @param pcCheminFichier 
	*/
	CLecteur(const char* pcCheminFichier);
	/**
	 * @brief Constructeur par default qui crée l'objet CLecteur
	*/
	CLecteur();
	/**
	 * @brief Destructeur par default
	*/
	~CLecteur();
	/**
	 * @brief Lire le nombre d'element
	 * @return le nombre lu
	*/
	unsigned int LireNbElements();
	/**
	 * @brief Lire le nombre de variable
	 * @return 
	*/
	unsigned int LireNbVariables();
	/**
	 * @brief Lire le nombre de parametre
	 * @return 
	*/
	unsigned int LireNbParametres();
	/**
	 * @brief Lire le variable Articulaire à l'indice uiIndice dans la liste dynamique d'objet VariableArticulaire
	 * @param uiIndice indice de l'element
	 * @return VariableArticulaire lue
	*/
	VariableArticulaire& LireElement(unsigned int uiIndice);
	/**
	 * @brief Lire le variable Articulaire à l'indice uiIndice dans la liste dynamique de pointeurs d'objet VariableArticulaire
	 * @param uiIndice indice de l'element
	 * @return VariableArticulaire lue
	*/
	VariableArticulaire& LireVariable(unsigned int uiIndice);
	/**
	 * @brief Lire le denavitParameter dans la liste dynamique de paramètres de Denavit
	 * @param uiIndice l'indice de l'élément
	 * @return le denavitParameter lu 
	*/
	DenavitParameter& LireParametre(unsigned int uiIndice); 
	/**
	 * @brief Lire le fichier
	*/
	void LireFichier();
	/**
	 * @brief Modifier l'adressse du fichier
	 * @param pcFichier l'adresse du nouveau fichier
	*/
	void ModifierFichier(const char* pcFichier);

};
#endif