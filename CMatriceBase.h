#ifndef C_MATRICE_BASE_H
#define C_MATRICE_BASE_H

#include <iostream>
#include <assert.h>
#include <fstream>

class CMatriceBase 
{
private:
	unsigned int uiMATNbLigne;

	unsigned int uiMATNbColonne;

	float* pfMATElement;


public:
	/**
	* Constructeur par default
	 * @brief Constructeur par default qui crée l'objet et initialise ses membres à null. 
	*/
	CMatriceBase() ;

	/**
	* Constructeur de recopie
	 * @brief Constructeur qui crée l'objet CMatriceBase et initialise ses membres en recopiant les membres d'un autre objet CMatriceBase.
	 * @param MATObjet 
	*/
	CMatriceBase(const CMatriceBase& MATObjet);

	/**
	* Constructeur de confort 
	 * @brief Constructeur qui crée et initialise un object CMatriceBase
	 * @param uiLignes 
	 * @param uiColonnes 
	 * @param pfElements 
	*/
	CMatriceBase(unsigned int uiLignes, unsigned int uiColonnes, float* pfElements = NULL);

	/**
	* Destructeur
	* @brief Destructeur qui désalloue pfMATElement et détruit l'objet CMatriceBase
	*/
	~CMatriceBase();

	/**
	* Lire le nombre de colonnes dans la matrice
	 * @brief Ce méthode permet de savoir combien de colonne cette matrice possède
	 * @return unsigned int qui correspond au nombre de colonnes dans la matrice 
	*/
	unsigned int MATLireNbColonne();

	/**
	* Lire le nombre de lignes dans la matrice
	 * @brief Ce méthode permet de savoir combien de lignes cette matrice possède
	 * @return unsigned int qui correspond au nombre de lignes dans la matrice
	*/
	unsigned int MATLireNbLigne();

	/**
	* Lire un element de la matrice
	 * @brief Lire l'élément à la ligne uiLigne et dans le colonne uiColonne de la matrice.
	 * @param uiLigne 
	 * @param uiColonne 
	 * @return float correspondant à l'élément lu
	*/
	float MATLireElement(unsigned int uiLigne, unsigned int uiColonne);

	/**
	* Afficher la matrice
	 * @brief Affiche la matrice dans la sortie standard.
	*/
	void MATAffiche();
	
	/**
	* Surcharge d'operateur égal
	 * @brief La méthode pour surcharger l'opérateur = permettant une recopie d'élément à élément
	 * @param MATObjet 
	*/
	void operator=(const CMatriceBase& MATObjet);

	void MATModiferElement(unsigned int indiceLigne,unsigned int indiceColonne, float element);
protected :

	void MATReallocMatrice(unsigned int element);
	
	void MATModifierNbLignes(unsigned int number);

	void MATModifierNbColonnes(unsigned int number);


	
};
#endif
