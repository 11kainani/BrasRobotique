#ifndef C_MATRICE_H
#define C_MATRICE_H

#include <iostream>
#include <fstream>
#include "CMatriceBase.h"
#include "CException.h"
#include "DenavitParameter.h"
#include "VariableArticulaire.h"

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
	 * @return la matrice transposée
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
	* Algorithme de Greville 
	 * @brief ALgortime de Greveille qui permet de calculer l'inverse (ou pseudoInverse) d'une matrice 
	 * @return CMatrice qui correspond à l'inverse.
	*/
	CMatrice Greville();

	/**
	 * Destructeur par default
	 * @brief Cette méthode appelle au destructeur de sa classe mère (CMatriceBase)
	*/
	~CMatrice();

	/**
	* MATFromColonne
	 * @brief Retourne une matrice colonne correspondant à la matrice colonne à l'indice numColonne 
	 * @param numColonne qui correspond à l'indice de la colonne a retourner
	 * @return Une matrice colonne à l'indice numColonne
	*/
	CMatrice MATFromColonne(unsigned int numColonne);

	/**
	* MATIdentity
	 * @brief Permet de générer une matrice identity 
	 * @param nbLignes nombre de lignes dans la matrice identité à générer
	 * @param nbColonnes nombre de colonnes dans la matrice identité à générer 
	 * @return Une matrice identité de nbLignes Lignes de nbColonnes Colonnes
	*/
	static CMatrice MATIdentity(unsigned int nbLignes, unsigned int nbColonnes);

	/**
	* MATAjouterLignes
	 * @brief Permet d'ajouter des lignes vides à la matrice  
	 * @param number qui correspond au nombre de lignes à ajouter
	*/
	void MATAjouterLignes(unsigned int number);
	/**
	* MATAjouterColonnes
	 * @brief Permet d'ajouter des colonnes vides à la matrice
	 * @param number qui correspond au nombre de Colonnes à ajouter
	*/
	void MATAjouterColonnes(unsigned int number);
	/**
	* MATAjouterLignesMatrice
	 * @brief Ajouter des lignes de matrice à la suite du "this" matrice
	 * @param Objet un object CMatrice qui correspond à la matrice a ajouter 
	*/
	void MATAjouerLignesMatrice(CMatrice Objet);
	/**
	* MATAjouterColonnesMatrice
	 * @brief Ajouter des colonnes de matrice à la suite du "this" matrice
	 * @param Objet un object CMatrice qui correspond à la matrice a ajouter
	*/
	void MATAjouerColonnesMatrice(CMatrice Objet);

	// static CMatrice MATDenavit(DenavitParameter DENObject);
	
	/**
	* Operator ==
	 * @brief Surcharge de l'operateur== qui permet de comparer 2 matrices
	 * @param MATObjet Matrice à comparer
	 * @return true si les deux matrice sont identiques sinon false
	*/
	bool operator==(CMatrice MATObjet);
	/**
	* Operator !=
	 * @brief Surcharge de l'operateur!= qui permet de comparer 2 matrices
	 * @param MATObjet Matrice à comparer
	 * @return false si les deux matrice sont identiques sinon true
	*/
	bool operator!=(CMatrice MATObjet);
	/**
	* bMATOrthonormal
	 * @brief Permet de savoir si la matrice est orthonormal
	 * @return true si la matrice est orthonormal sinon false
	*/
	bool bMATOrthonormal();
	/**
	* dMATNorme
	 * @brief Savoir la norme d'une matrice colonne 
	 * @param MATObjet la matrice colonne qu'il faut calculer la norme
	 * @return la norme de la matrice colonnes
	*/
	double static dMATNorme(CMatrice MATObjet);


};
#endif
