#ifndef C_MATRICE_H
#define C_MATRICE_H

#include <iostream>
#include <fstream>
#include "CMatriceBase.h"
#include "CException.h"
#include "DenavitParameter.h"
#include "VariableArticulaire.h"

/**
* @brief Classe permettant de manipuler des matrices 
*/
class CMatrice : public CMatriceBase
{
public:
	/**
	* Constructeur de confort
	 * @brief Cr�ation et initialisation d'un objet CMatrice en appelant le constructeur de confort de CMatriceBase
	 * @param uiLignes
	 * @param uiColonnes
	 * @param pfElements
	*/
	CMatrice(unsigned int uiLignes, unsigned int uiColonnes, double *pfElements = nullptr);

	/**
	* Constructeur par default
	 * @brief Creation d'un objet CMatrice vide
	*/
	CMatrice();

	/**
	* Constructeur de recopie
	 * @brief Cr�ation et initialisation d'un objet CMatrice en appelant le constructeur de recopie de CMatriceBase
	 * @param MATObjet
	*/
	CMatrice(const CMatrice& MATObjet);


	/**
	* Transposition de matrice
	 * @brief Transpose une matrice
	 * @return la matrice transpos�
	*/
	CMatrice MATTranspose();

	/**
	* Surcharge de l'operateur *
	 * @brief Surcharge de l'operateur * pour permettre la multiplication entre 2 matrices
	 * @param MATObjet
	 * @return Le produit de 2 matrices
	*/
	CMatrice operator*(CMatrice MATObjet);

	/**
	* La matrice est-elle vide ?
	 * @brief V�rifie si la matrice est vide
	 * @return true si la matrice est vide sinon false
	*/
	bool MATIsEmpty();

	/**
	* Surcharge de l'operateur -
	 * @brief Surcharge de l'op�rateur -
	 * @param MATObjet
	 * @return La diff�rence entre 2 matrices
	*/
	CMatrice operator-(CMatrice MATObjet);

	/**
	* Surcharge de l'operateur *
	 * @brief Surcharge de l'operateur * pour permettre la multiplication d'une matrice avec un double
	 * @param fValeur
	 * @return la matrice r�sultat multip�e par le double
	*/
	CMatrice operator*(double fValeur);

	/**
	* Surcharge de l'operateur /
	 * @brief Surcharge de l'operateur / pour permettre la division d'une matrice avec un double
	 * @param fValeur
	 * @return
	*/
	CMatrice operator/(double fValeur);

	/**
	* Surcharge de l'operateur +
	 * @brief Surcharge de l'o^perateur + pour
	 * @param MATObjet
	 * @return
	*/
	CMatrice operator+(CMatrice MATObjet);

	/**
	 * @brief Matrice de greville permettant de calculer l'inverse (ou pseudo-inverse) de la matrice
	 * @return l'inverse (ou pseudo-inverse) de cette matrice
	*/
	CMatrice Greville();

	/**
	 * @brief Destructeur par default qui desalloue et detruit l'objet CMatrice
	*/
	~CMatrice();
	/**
	 * @brief Matrice colonne a l'indice numColonne
	 * @param numColonne l'indice de la colonne
	 * @return une matrice colonne a l'indice numColonne
	*/
	CMatrice MATFromColonne(unsigned int numColonne);
	/**
	 * @brief Matrice identite
	 * @param nbLignes nombre de ligne dans la matrice
	 * @param nbColonnes nombre de colonne dans la matrice
	 * @return une matrice de nbLignes lignes et nbColonnes colonnes 
	*/
	static CMatrice MATIdentity(unsigned int nbLignes, unsigned int nbColonnes);
	/**
	 * @brief Ajouter des lignes a la matrice 
	 * @param number le nombre de ligne a ajouter 
	*/
	void MATAjouterLignes(unsigned int number);
	/**
	 * @brief Ajouter des colonnes a la matrice
	 * @param number niombre de colonnes a ajouter
	*/
	void MATAjouterColonnes(unsigned int number);
	/**
	 * @brief Ajouter une matrice a la suite de cette matrice
	 * Il faut que la matrice a ajouter aie le meme nombre de colonnes que cette matrice
	 * @param Objet la matrice a ajouter a la suite
	*/
	void MATAjouerLignesMatrice(CMatrice Objet);
	/**
	 * @brief Ajouter des colonnes a la suite de cette matrice
	 * Il faut que la matrice a ajouter aie le meme nombre de lignes
	 * @param Objet La matrice a ajouter
	*/
	void MATAjouerColonnesMatrice(CMatrice Objet);

	




};
#endif