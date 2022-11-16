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

	CMatrice MATTranspose();

	CMatrice operator*(CMatrice MATObjet);

	bool MATIsEmpty();

	CMatrice operator-(CMatrice MATObjet);

	CMatrice operator*(double dValeur);

	CMatrice operator/(double dValeur);

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
