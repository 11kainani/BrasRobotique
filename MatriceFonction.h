#pragma once

#include "DenavitParameter.h"
#include "ListFonction.h"
#include "FonctionProduit.h"
#include "FonctionSomme.h"
#include "FonctionCos.h"
#include "FonctionSin.h"
#include "CMatrice.h"

/**
 * Classe représentant une matrice de formules mathématiques quelconques
 * Une taille fixe est définie lors de son initialisation
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
	 * Constructeur par défaut
	 * @brief Crée un objet vide
	*/
	MatriceFonction();

	/**
	 * Constructeur de matrice identité
	 * @brief Crée une matrice identité composée de formule constante
	 * @param nbLignes : nombre de lignes de la matrice
	 * @param nbColonnes : nombre de colonnes de la matrice
	*/
	MatriceFonction(unsigned int nbLignes, unsigned int nbColonnes);

	/**
	 * Constructeur de comfort
	 * @brief Crée une matrice de formules ayant récupéré par délégation les éléments de la liste fournie
	 * Les (nbColonnes) premiers éléments sont affectés à la première ligne
	 * @param fonctions : liste de (nbLignes*nbColonnes) formules mathématiques
	 * @param nbLignes : nombre de lignes de la matrice
	 * @param nbColonnes : nombre de colonnes de la matrice
	*/
	MatriceFonction(ListFonction fonctions, unsigned int nbLignes, unsigned int nbColonnes);

	/**
	 * Constructeur de matrice élémentaire de Denavit
	 * @brief Crée une matrice élémentaire de Denavit dont les variables sont reliées au paramètre Denavit donné
	 * @param param : paramètre de Denavit à relier à la matrice 
	 * @param num : numéro compris entre 0 et 9 du paramètre Denavit utilisé pour l'affichage (0 par défaut)
	*/
	MatriceFonction(DenavitParameter& param, unsigned int num = 0);

	/**
	 * Constructeur de recopie
	 * @brief Crée une matrice dont les éléments pointent ceux de la matrice fournie
	 * @param MATCopie : Objet à copier
	*/
	MatriceFonction(MatriceFonction& MATCopie);

	/**
	 * Constructeur de déplacement
	 * @brief Crée une matrice dont les éléments ont récupéré ceux de la matrice temporaire donnée
	 * @param MATCopie : Objet temporaire à copier
	*/
	MatriceFonction(MatriceFonction&& MATCopie);

	/**
	 * Destructeur
	 * @brief Détruis la liste d'éléments puis l'objet MatriceFonction
	*/
	~MatriceFonction();




	/**
	 * Initialiseur de matrice identité
	 * @brief Détruis et recrée la matrice pour devenir une matrice identité composée de formule constante
	 * @param nbLignes : nombre de lignes de la matrice
	 * @param nbColonnes : nombre de colonnes de la matrice
	*/
	void init(unsigned int nbLignes, unsigned int nbColonnes);

	/**
	 * Initialiseur de comfort
	 * @brief Détruis et recrée une matrice de formules ayant récupéré par délégation les éléments de la liste fournie
	 * Les (nbColonnes) premiers éléments sont affectés à la première ligne
	 * @param fonctions : liste de (nbLignes*nbColonnes) formules mathématiques
	 * @param nbLignes : nombre de lignes de la matrice
	 * @param nbColonnes : nombre de colonnes de la matrice
	*/
	void init(ListFonction fonctions, unsigned int nbLignes, unsigned int nbColonnes);

	/**
	 * Initialiseur de matrice élémentaire de Denavit
	 * @brief Détruis l'objet et recrée une matrice élémentaire de Denavit
	 * @param param : paramètre de Denavit à relier à la matrice
	 * @param num : numéro compris entre 0 et 9 du paramètre Denavit utilisé pour l'affichage (0 par défaut)
	*/
	void init(DenavitParameter& param, unsigned int num = 0);

	/**
	 * Initialiseur de recopie
	 * @brief Détruis l'objet et recrée la matrice dont les éléments récupère ceux de la matrice fournie
	 * @param MATCopie : Objet à copier
	*/
	void init(MatriceFonction MATCopie);


	/**
	 * Résultat des formules de la matrice
	 * @brief Retourne une matrice de réel contenant le résultat de chaque élément
	*/
	CMatrice Result();


	/**
	 * Surcharge de l'opérateur =
	 * @brief Redéfinie la matrice pour pointer les mêmes formules que ceux de la matrice fournie 
	 * @param MATMatrice : Matrice à copier
	*/
	MatriceFonction& operator=(MatriceFonction& MATMatrice);

	/**
	 * Surcharge de l'opérateur *
	 * @brief Retourne une nouvelle matrice égale au produit matriciel entre deux matrices
	 * @param MATMatrice : Matrice à droite de l'opérateur *
	*/
	MatriceFonction operator*(MatriceFonction& MATMatrice);

	/**
	 * Surcharge de l'opérateur []
	 * @brief Retourne la liste de formules appartenant à la ligne d'indice donné
	 * @param uiIndice : indice de la ligne [0, n-1]
	*/
	ListFonction operator[](unsigned int uiIndice);

	/**
	 * Copie des éléments de la matrice
	 * @brief Alloue une copie des éléments contenus dans la matrice
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
	 * @brief Crée un objet FonctionInterface représentant la variable articulaire d'indice donné d'un paramètre de Denavit donné
	 * @param param : paramètre de Denavit contenant la variable articulaire recherchée 
	 * @param uiIndice : indice de la variable articulaire à lier [0, 3]
	 * @param nom : nom de la variable articulaire à utiliser lors de l'affichage ("?" par défaut)
	*/
	FonctionInterface Param(DenavitParameter& param, unsigned int uiIndice, const char* nom = "?");
};

