#pragma once

#include "DenavitParameter.h"
#include "ListFonction.h"
#include "FonctionProduit.h"
#include "FonctionSomme.h"
#include "FonctionCos.h"
#include "FonctionSin.h"
#include "CMatrice.h"

class MatriceFonction
{

	// Liste de FonctionInterface
	ListFonction LISFonctions;

	// Nombre de lignes strictement positif
	unsigned int uiNbLignes;
	
	// Nombre de colonnes strictement positif
	unsigned int uiNbColonnes;

public:
	MatriceFonction();
	MatriceFonction(unsigned int nbLignes, unsigned int nbColonnes);
	MatriceFonction(ListFonction fonctions, unsigned int nbLignes, unsigned int nbColonnes);
	MatriceFonction(DenavitParameter& param, unsigned int num = 0);
	MatriceFonction(MatriceFonction& MATCopie);
	~MatriceFonction();

	CMatrice Result();

	MatriceFonction& operator=(MatriceFonction& MATMatrice);
	MatriceFonction operator*(MatriceFonction& MATMatrice);
	ListFonction operator[](unsigned int uiIndice);
	ListFonction getElements();


	void Show();

private:
	FonctionInterface Param(DenavitParameter& param, unsigned int uiIndice, const char* nom = "?");
};

