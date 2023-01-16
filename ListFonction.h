#ifndef LIST_FONCTION_H
#define LIST_FONCTION_H

#include "FonctionInterface.h"

/**
 * @brief Classe permettant de creer des liste de FonctionInterface
*/
class ListFonction
{
	FonctionInterface* pLISFonctions; // Liste de fonctions
	unsigned int uiTaille;		// Taille de la liste de fonctions
	unsigned int uiNbFonctions; // Nombre de fonctions initialisees

public:

	/**
	 * Constructeur par defaut
	 * @brief Cree une liste vide de FonctionInterface
	*/
	ListFonction();

	/**
	 * Contructeur de comfort
	 * @brief Cree une liste de FonctionInterface avec une taille donnee (Les fonctions ne sont pas initialisees)
	 * @param taille : Nombre d'emplacements dans la liste
	*/
	ListFonction(unsigned int taille);

	/**
	 * Constructeur de recopie
	 * @brief Cree une liste de FonctionInterface ayant recupere par delegation les objets Fonction des elements de la liste fournit
	 * @param LISCopie : Liste contenant les elements a transmettre
	*/
	ListFonction(ListFonction& LISCopie);

	/**
	 * Destructeur
	 * @brief Detruis la liste de FonctionInterface
	*/
	~ListFonction();

	void init(unsigned int taille);

	void init(ListFonction LISCopie);

	/**
	 * Surcharge de l'operateur =
	 * @brief Recree la liste et recupere par delegation les objets Fonction des elements de la liste de droite
	 * @param LISCopie : Liste contenant les elements a transmettre
	*/
	ListFonction& operator=(ListFonction& LISCopie);

	/**
	 * Surcharge de l'operateur []
	 * @brief Retourne l'element d'indice donne
	 * @param indice : indice de l'element recherche (entre 0 et uiNbFonctions-1)
	*/
	FonctionInterface& operator[](int indice);

	/**
	 * Ajout de fonction
	 * @brief Ajoute, par delegation ou reference, l'objet Fonction contenu dans l'objet FonctionInterface fournit 
	 * @param pFonction : Objet FonctionInterface
	 * @param delegation : Y a-t-il delegation de l'objet Fonction contenu dans pFonction ? (vrai par defaut)
	*/
	void AddFonction(FonctionInterface& pFonction, bool delegation = true);

	/**
	 * Ajout de fonction
	 * @brief Ajoute, par delegation ou reference, l'objet Fonction contenu dans l'objet temporaire FonctionInterface fournit
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
	 * Allocation memoire
	 * @brief Alloue la liste de FonctionInterface pour contenir un nombre donne d'objets
	 * @param taille : Nombre d'emplacements dans la liste
	*/
	void Alloc(unsigned int taille);

	/**
	 * Desallocation memoire
	 * @brief Desalloue la liste de FonctionInterface
	*/
	void Desalloc();

};
#endif

