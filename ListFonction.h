#ifndef LIST_FONCTION_H
#define LIST_FONCTION_H

#include "FonctionInterface.h"

/**
 * Classe représentant une liste de formules mathématiques quelconques
 * Une capacité fixe lui est attribué lors de son initialisation
 */
class ListFonction
{
	FonctionInterface* pLISFonctions; // Liste de fonctions
	unsigned int uiTaille;		// Taille de la liste de fonctions
	unsigned int uiNbFonctions; // Nombre de fonctions initialisées

public:

	/**
	 * Constructeur par défaut
	 * @brief Crée une liste vide de FonctionInterface
	*/
	ListFonction();

	/**
	 * Contructeur de comfort
	 * @brief Crée une liste de FonctionInterface avec une taille donnée (Les fonctions ne sont pas initialisées)
	 * @param taille : Nombre d'emplacements dans la liste
	*/
	ListFonction(unsigned int taille);

	/**
	 * Constructeur de recopie
	 * @brief Crée une liste de FonctionInterface ayant récupéré par délégation les objets Fonction des éléments de la liste fournit
	 * @param LISCopie : Liste contenant les éléments à transmettre
	*/
	ListFonction(ListFonction& LISCopie);

	/**
	 * Destructeur
	 * @brief Détruis la liste de FonctionInterface (appel du destructeur de chaque FonctionInterface)
	*/
	~ListFonction();

	/**
	 * Initialiseur de comfort
	 * @brief Détruis et recrée la liste de FonctionInterface avec une taille donnée (Les fonctions ne sont pas initialisées)
	 * @param taille : Nombre d'emplacements dans la liste
	*/
	void init(unsigned int taille);

	/**
	 * Initialiseur de recopie
	 * @brief Détruis et recrée une liste de FonctionInterface
	 * Chaque élément auront récupéré par délégation les objets Fonction des éléments de la liste fournit
	 * @param LISCopie : Liste contenant les éléments à transmettre
	*/
	void init(ListFonction LISCopie);

	/**
	 * Surcharge de l'opérateur =
	 * @brief Recrée la liste et récupère par délégation les objets Fonction des éléments de la liste de droite
	 * @param LISCopie : Liste contenant les éléments à transmettre
	*/
	ListFonction& operator=(ListFonction& LISCopie);

	/**
	 * Surcharge de l'opérateur []
	 * @brief Retourne l'élément d'indice donné
	 * @param indice : indice de l'élément recherché (entre 0 et uiNbFonctions-1)
	*/
	FonctionInterface& operator[](int indice);

	/**
	 * Ajout de fonction
	 * @brief Ajoute, par délégation ou référence, l'objet Fonction contenu dans l'objet FonctionInterface fournit 
	 * @param pFonction : Objet FonctionInterface
	 * @param delegation : Y a-t-il délégation de l'objet Fonction contenu dans pFonction ? (vrai par défaut)
	*/
	void AddFonction(FonctionInterface& pFonction, bool delegation = true);

	/**
	 * Ajout de fonction
	 * @brief Ajoute, par délégation ou référence, l'objet Fonction contenu dans l'objet temporaire FonctionInterface fournit
	 * @param pFonction : Objet temporaire FonctionInterface
	*/
	void AddFonction(FonctionInterface&& pFonction);

	/**
	 * Getter
	 * @brief Retourne le nombre de FonctionInterface que la liste peut contenir
	*/
	unsigned int GetTaille();

	/**
	 * Getter
	 * @brief Retourne le nombre de FonctionInterface actuellement dans la liste
	 * @param
	*/
	unsigned int GetNbFonctions();

private:

	/**
	 * Allocation mémoire
	 * @brief Alloue la liste de FonctionInterface pour contenir un nombre donné d'objets
	 * @param taille : Nombre d'emplacements dans la liste
	*/
	void Alloc(unsigned int taille);

	/**
	 * Desallocation mémoire
	 * @brief Desalloue la liste de FonctionInterface
	*/
	void Desalloc();

};
#endif

