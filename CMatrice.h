#ifndef C_MATRICE_H
#define C_MATRICE_H

#include <iostream>
#include <assert.h>
#include <fstream>
#include "CMatriceBase.h"
#include "CException.h"

class CMatrice : public CMatriceBase
{
public:
	/**
	* Constructeur de confort
	 * @brief Création et initialisation d'un objet CMatrice en appelant le constructeur de confort de CMatriceBase
	 * @param uiLignes 
	 * @param uiColonnes 
	 * @param pfElements 
	*/
	CMatrice(unsigned int uiLignes, unsigned int uiColonnes, float *pfElements = nullptr);

	/**
	* Constructeur par default
	 * @brief Creation d'un objet CMatrice vide
	*/
	CMatrice();

	/**
	* Constructeur de recopie
	 * @brief Création et initialisation d'un objet CMatrice en appelant le constructeur de recopie de CMatriceBase
	 * @param MATObjet 
	*/
	CMatrice(const CMatrice& MATObjet);

	/**
	* Transposition de matrice
	 * @brief Transpose une matrice
	 * @return la matrice transposé
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
	 * @brief Vérifie si la matrice est vide
	 * @return true si la matrice est vide sinon false
	*/
	bool MATIsEmpty();

	/**
	* Surcharge de l'operateur -
	 * @brief Surcharge de l'opérateur -
	 * @param MATObjet 
	 * @return La différence entre 2 matrices
	*/
	CMatrice operator-(CMatrice MATObjet);

	/**
	* Surcharge de l'operateur *
	 * @brief Surcharge de l'operateur * pour permettre la multiplication d'une matrice avec un float
	 * @param fValeur 
	 * @return la matrice résultat multipée par le float
	*/
	CMatrice operator*(float fValeur);

	/**
	* Surcharge de l'operateur /
	 * @brief Surcharge de l'operateur / pour permettre la division d'une matrice avec un float
	 * @param fValeur 
	 * @return 
	*/
	CMatrice operator/(float fValeur);

	/**
	* Surcharge de l'operateur +
	 * @brief Surcharge de l'o^perateur + pour 
	 * @param MATObjet 
	 * @return 
	*/
	CMatrice operator+(CMatrice MATObjet);

	CMatrice Greville();

	~CMatrice();

	CMatrice MATFromColonne( unsigned int numColonne);

	static CMatrice MATIdentity(unsigned int nbLignes, unsigned int nbColonnes);

	void MATAjouterLignes(unsigned int number);

	void MATAjouterColonnes(unsigned int number);

	void MATAjouerLignesMatrice(CMatrice Objet);

	void MATAjouerColonnesMatrice(CMatrice Objet);

	

};
#endif
