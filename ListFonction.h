#ifndef LIST_FONCTION_H
#define LIST_FONCTION_H

#include "FonctionInterface.h"

/**
 * Classe repr�sentant une liste de formules math�matiques quelconques
 * Une capacit� fixe lui est attribu� lors de son initialisation
 */
class ListFonction
{
	FonctionInterface* pLISFonctions; // Liste de fonctions
	unsigned int uiTaille;		// Taille de la liste de fonctions
	unsigned int uiNbFonctions; // Nombre de fonctions initialis�es

public:

	/**
	 * Constructeur par d�faut
	 * @brief Cr�e une liste vide de FonctionInterface
	*/
	ListFonction();

	/**
	 * Contructeur de comfort
	 * @brief Cr�e une liste de FonctionInterface avec une taille donn�e (Les fonctions ne sont pas initialis�es)
	 * @param taille : Nombre d'emplacements dans la liste
	*/
	ListFonction(unsigned int taille);

	/**
	 * Constructeur de recopie
	 * @brief Cr�e une liste de FonctionInterface ayant r�cup�r� par d�l�gation les objets Fonction des �l�ments de la liste fournit
	 * @param LISCopie : Liste contenant les �l�ments � transmettre
	*/
	ListFonction(ListFonction& LISCopie);

	/**
	 * Destructeur
	 * @brief D�truis la liste de FonctionInterface (appel du destructeur de chaque FonctionInterface)
	*/
	~ListFonction();

	/**
	 * Initialiseur de comfort
	 * @brief D�truis et recr�e la liste de FonctionInterface avec une taille donn�e (Les fonctions ne sont pas initialis�es)
	 * @param taille : Nombre d'emplacements dans la liste
	*/
	void init(unsigned int taille);

	/**
	 * Initialiseur de recopie
	 * @brief D�truis et recr�e une liste de FonctionInterface
	 * Chaque �l�ment auront r�cup�r� par d�l�gation les objets Fonction des �l�ments de la liste fournit
	 * @param LISCopie : Liste contenant les �l�ments � transmettre
	*/
	void init(ListFonction LISCopie);

	/**
	 * Surcharge de l'op�rateur =
	 * @brief Recr�e la liste et r�cup�re par d�l�gation les objets Fonction des �l�ments de la liste de droite
	 * @param LISCopie : Liste contenant les �l�ments � transmettre
	*/
	ListFonction& operator=(ListFonction& LISCopie);

	/**
	 * Surcharge de l'op�rateur []
	 * @brief Retourne l'�l�ment d'indice donn�
	 * @param indice : indice de l'�l�ment recherch� (entre 0 et uiNbFonctions-1)
	*/
	FonctionInterface& operator[](int indice);

	/**
	 * Ajout de fonction
	 * @brief Ajoute, par d�l�gation ou r�f�rence, l'objet Fonction contenu dans l'objet FonctionInterface fournit 
	 * @param pFonction : Objet FonctionInterface
	 * @param delegation : Y a-t-il d�l�gation de l'objet Fonction contenu dans pFonction ? (vrai par d�faut)
	*/
	void AddFonction(FonctionInterface& pFonction, bool delegation = true);

	/**
	 * Ajout de fonction
	 * @brief Ajoute, par d�l�gation ou r�f�rence, l'objet Fonction contenu dans l'objet temporaire FonctionInterface fournit
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
	 * Allocation m�moire
	 * @brief Alloue la liste de FonctionInterface pour contenir un nombre donn� d'objets
	 * @param taille : Nombre d'emplacements dans la liste
	*/
	void Alloc(unsigned int taille);

	/**
	 * Desallocation m�moire
	 * @brief Desalloue la liste de FonctionInterface
	*/
	void Desalloc();

};
#endif

