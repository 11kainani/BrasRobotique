#ifndef C_MATRICE_BASE_H
#define C_MATRICE_BASE_H

#include <iostream>
#include <fstream>

class CMatriceBase
{
private:
	unsigned int uiMATNbLigne;

	unsigned int uiMATNbColonne;

	double* pdMATElement;


public:
	/**
	* Constructeur par default
	 * @brief Constructeur par default qui cr�e l'objet et initialise ses membres � null.
	*/
	CMatriceBase();

	/**
	* Constructeur de recopie
	 * @brief Constructeur qui cr�e l'objet CMatriceBase et initialise ses membres en recopiant les membres d'un autre objet CMatriceBase.
	 * @param MATObjet
	*/
	CMatriceBase(const CMatriceBase& MATObjet);

	/**
	* Constructeur de confort
	 * @brief Constructeur qui cr�e et initialise un object CMatriceBase
	 * @param uiLignes
	 * @param uiColonnes
	 * @param pfElements
	*/
	CMatriceBase(unsigned int uiLignes, unsigned int uiColonnes, double* pfElements = NULL);

	/**
	* Destructeur
	* @brief Destructeur qui d�salloue pdMATElement et d�truit l'objet CMatriceBase
	*/
	~CMatriceBase();

	/**
	* Lire le nombre de colonnes dans la matrice
	 * @brief Ce m�thode permet de savoir combien de colonne cette matrice poss�de
	 * @return unsigned int qui correspond au nombre de colonnes dans la matrice
	*/
	unsigned int MATLireNbColonne();

	/**
	* Lire le nombre de lignes dans la matrice
	 * @brief Ce m�thode permet de savoir combien de lignes cette matrice poss�de
	 * @return unsigned int qui correspond au nombre de lignes dans la matrice
	*/
	unsigned int MATLireNbLigne();

	/**
	* Lire un element de la matrice
	 * @brief Lire l'�l�ment � la ligne uiLigne et dans le colonne uiColonne de la matrice.
	 * @param uiLigne
	 * @param uiColonne
	 * @return double correspondant � l'�l�ment lu
	*/
	double MATLireElement(unsigned int uiLigne, unsigned int uiColonne);

	/**
	* Afficher la matrice
	 * @brief Affiche la matrice dans la sortie standard.
	*/
	void MATAffiche();

	/**
	* Surcharge d'operateur �gal
	 * @brief La m�thode pour surcharger l'op�rateur = permettant une recopie d'�l�ment � �l�ment
	 * @param MATObjet
	*/
	void operator=(const CMatriceBase& MATObjet);

	void MATModiferElement(unsigned int indiceLigne, unsigned int indiceColonne, double element);


protected:

	void MATReallocMatrice(unsigned int element);

	void MATModifierNbLignes(unsigned int number);

	void MATModifierNbColonnes(unsigned int number);

	// A supprimer
	double Superieur(double, double);
	double Precision(double, int);


};
#endif