#pragma once

#include "DenavitParameter.h"
#include "ListFonction.h"
#include "FonctionProduit.h"
#include "FonctionSomme.h"
#include "FonctionCos.h"
#include "FonctionSin.h"
#include "CMatrice.h"

/**
 * Classe repr�sentant une matrice de formules math�matiques quelconques
 * Une taille fixe est d�finie lors de son initialisation
 */
class MatriceFonction
{

	// Liste de FonctionInterface
	ListFonction LISFonctions;

	// Nombre de lignes strictement positif
	unsigned int uiNbLignes;
	
	// Nombre de colonnes strictement positif
	unsigned int uiNbColonnes;

public:

	/**
	 * Constructeur par d�faut
	 * @brief Cr�e un objet vide
	*/
	MatriceFonction();

	/**
	 * Constructeur de matrice identit�
	 * @brief Cr�e une matrice identit� compos�e de formule constante
	 * @param nbLignes : nombre de lignes de la matrice
	 * @param nbColonnes : nombre de colonnes de la matrice
	*/
	MatriceFonction(unsigned int nbLignes, unsigned int nbColonnes);

	/**
	 * Constructeur de comfort
	 * @brief Cr�e une matrice de formules ayant r�cup�r� par d�l�gation les �l�ments de la liste fournie
	 * Les (nbColonnes) premiers �l�ments sont affect�s � la premi�re ligne
	 * @param fonctions : liste de (nbLignes*nbColonnes) formules math�matiques
	 * @param nbLignes : nombre de lignes de la matrice
	 * @param nbColonnes : nombre de colonnes de la matrice
	*/
	MatriceFonction(ListFonction fonctions, unsigned int nbLignes, unsigned int nbColonnes);

	/**
	 * Constructeur de matrice �l�mentaire de Denavit
	 * @brief Cr�e une matrice �l�mentaire de Denavit dont les variables sont reli�es au param�tre Denavit donn�
	 * @param param : param�tre de Denavit � relier � la matrice 
	 * @param num : num�ro compris entre 0 et 9 du param�tre Denavit utilis� pour l'affichage (0 par d�faut)
	*/
	MatriceFonction(DenavitParameter& param, unsigned int num = 0);

	/**
	 * Constructeur de recopie
	 * @brief Cr�e une matrice dont les �l�ments pointent ceux de la matrice fournie
	 * @param MATCopie : Objet � copier
	*/
	MatriceFonction(MatriceFonction& MATCopie);

	/**
	 * Constructeur de d�placement
	 * @brief Cr�e une matrice dont les �l�ments ont r�cup�r� ceux de la matrice temporaire donn�e
	 * @param MATCopie : Objet temporaire � copier
	*/
	MatriceFonction(MatriceFonction&& MATCopie);

	/**
	 * Destructeur
	 * @brief D�truis la liste d'�l�ments puis l'objet MatriceFonction
	*/
	~MatriceFonction();




	/**
	 * Initialiseur de matrice identit�
	 * @brief D�truis et recr�e la matrice pour devenir une matrice identit� compos�e de formule constante
	 * @param nbLignes : nombre de lignes de la matrice
	 * @param nbColonnes : nombre de colonnes de la matrice
	*/
	void init(unsigned int nbLignes, unsigned int nbColonnes);

	/**
	 * Initialiseur de comfort
	 * @brief D�truis et recr�e une matrice de formules ayant r�cup�r� par d�l�gation les �l�ments de la liste fournie
	 * Les (nbColonnes) premiers �l�ments sont affect�s � la premi�re ligne
	 * @param fonctions : liste de (nbLignes*nbColonnes) formules math�matiques
	 * @param nbLignes : nombre de lignes de la matrice
	 * @param nbColonnes : nombre de colonnes de la matrice
	*/
	void init(ListFonction fonctions, unsigned int nbLignes, unsigned int nbColonnes);

	/**
	 * Initialiseur de matrice �l�mentaire de Denavit
	 * @brief D�truis l'objet et recr�e une matrice �l�mentaire de Denavit
	 * @param param : param�tre de Denavit � relier � la matrice
	 * @param num : num�ro compris entre 0 et 9 du param�tre Denavit utilis� pour l'affichage (0 par d�faut)
	*/
	void init(DenavitParameter& param, unsigned int num = 0);

	/**
	 * Initialiseur de recopie
	 * @brief D�truis l'objet et recr�e la matrice dont les �l�ments r�cup�re ceux de la matrice fournie
	 * @param MATCopie : Objet � copier
	*/
	void init(MatriceFonction MATCopie);


	/**
	 * R�sultat des formules de la matrice
	 * @brief Retourne une matrice de r�el contenant le r�sultat de chaque �l�ment
	*/
	CMatrice Result();


	/**
	 * Surcharge de l'op�rateur =
	 * @brief Red�finie la matrice pour pointer les m�mes formules que ceux de la matrice fournie 
	 * @param MATMatrice : Matrice � copier
	*/
	MatriceFonction& operator=(MatriceFonction& MATMatrice);

	/**
	 * Surcharge de l'op�rateur *
	 * @brief Retourne une nouvelle matrice �gale au produit matriciel entre deux matrices
	 * @param MATMatrice : Matrice � droite de l'op�rateur *
	*/
	MatriceFonction operator*(MatriceFonction& MATMatrice);

	/**
	 * Surcharge de l'op�rateur []
	 * @brief Retourne la liste de formules appartenant � la ligne d'indice donn�
	 * @param uiIndice : indice de la ligne [0, n-1]
	*/
	ListFonction operator[](unsigned int uiIndice);

	/**
	 * Copie des �l�ments de la matrice
	 * @brief Alloue une copie des �l�ments contenus dans la matrice
	*/
	ListFonction getElements();



	/**
	 * Affichage
	 * @brief Affiche les formules dans la matrice
	*/
	void Show();

private:

	/**
	 * Liaison des variables articulaires
	 * @brief Cr�e un objet FonctionInterface repr�sentant la variable articulaire d'indice donn� d'un param�tre de Denavit donn�
	 * @param param : param�tre de Denavit contenant la variable articulaire recherch�e 
	 * @param uiIndice : indice de la variable articulaire � lier [0, 3]
	 * @param nom : nom de la variable articulaire � utiliser lors de l'affichage ("?" par d�faut)
	*/
	FonctionInterface Param(DenavitParameter& param, unsigned int uiIndice, const char* nom = "?");
};

