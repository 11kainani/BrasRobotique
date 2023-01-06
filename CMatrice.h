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

	CMatrice Greville();

	~CMatrice();

	CMatrice MATFromColonne(unsigned int numColonne);

	static CMatrice MATIdentity(unsigned int nbLignes, unsigned int nbColonnes);

	void MATAjouterLignes(unsigned int number);

	void MATAjouterColonnes(unsigned int number);

	void MATAjouerLignesMatrice(CMatrice Objet);

	void MATAjouerColonnesMatrice(CMatrice Objet);

	// static CMatrice MATDenavit(DenavitParameter DENObject);





};
#endif
