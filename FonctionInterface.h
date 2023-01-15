#ifndef FONCTION_INTERFACE_H
#define FONCTION_INTERFACE_H

#include "FonctionConstante.h"

/**
 * Classe contenant un pointeur polymorphique d'un objet Fonction
 * Elle permet de représenter n'importe quel objet héritant de la classe Fonction
 * Le pointeur est géré dynamiquement par la classe
*/
class FonctionInterface
{
	Fonction* pnFONFonction; // pointeur polymorphique d'une fonction
	bool bDynamique;  // Le pointeur est-il alloué par new ?
	bool bTemporaire; // L'objet est-il temporaire ?

public:


	/**
	 * Constructeur par défaut
	 * @brief Crée un objet FonctionInterface ne contenant aucun objet Fonction
	*/
	FonctionInterface();

	/**
	 * Constructeur de comfort
	 * @brief Crée un objet FonctionInterface contenant un objet Fonction (ou classe fille)
	 * @param fonction : adresse d'un objet Fonction ou pointeur Fonction*
	 * @param bTemp : L'objet créé est-il temporaire ? (vrai par défaut)
	*/
	FonctionInterface(Fonction* pFonction, bool bTemp = true);

	/**
	 * Constructeur de recopie
	 * @brief Crée un objet temporaire ayant récupéré l'objet Fonction contenu dans un autre objet FonctionInterface
	 * @param FONInterface : Objet FonctionInterface dont le contenu sera récupéré par délégation
	*/
	FonctionInterface(FonctionInterface& FONInterface);

	/**
	 * Constructeur de déplacement
	 * @brief Crée un objet temporaire ayant récupéré l'objet Fonction contenu dans un autre objet temporaire FonctionInterface
	 * @param FONInterface : Objet temporaire FonctionInterface dont le contenu sera récupéré par délégation
	*/
	FonctionInterface(FonctionInterface&& FONInterface);

	/**
	 * Destructeur
	 * @brief Détruis l'objet et, si bDynamique est vrai, l'objet Fonction contenu est désalloué de la mémoire
	*/
	~FonctionInterface();

	/**
	 * Initialiseur de comfort
	 * @brief Recrée l'objet FonctionInterface pour contenir un objet Fonction (ou classe fille) donné
	 * @param fonction : adresse d'un objet Fonction ou pointeur Fonction*
	 * @param bTemp : L'objet recréé est-il temporaire ? (vrai par défaut)
	*/
	void init(Fonction* pFonction, bool bTemp = true);

	
	/**
	 * Initialiseur de recopie
	 * @brief Récupère l'objet Fonction contenu dans un autre objet FonctionInterface
	 * @param FONInterface : Objet FonctionInterface dont le contenu sera récupéré par délégation
	*/
	void init(FonctionInterface FONInterface);


	/**
	 * Surcharge de l'opérateur =
	 * @brief Récupère l'objet Fonction contenu dans l'objet de droite si celui-ci est temporaire
	 * @param FONInterface : Objet FonctionInterface dont le contenu sera récupéré par délégation si celui-ci est temporaire
	*/
	FonctionInterface& operator=(FonctionInterface& FONInterface);

	/**
	 * Surcharge de l'opérateur =
	 * @brief Récupère l'objet Fonction contenu dans l'objet temporaire de droite
	 * @param FONInterface : Objet temporaire FonctionInterface dont le contenu sera récupéré par délégation
	*/
	FonctionInterface& operator=(FonctionInterface&& FONInterface);

	/**
	 * Surcharge de l'opérateur =
	 * @brief Affecte le pointeur fournit à l'objet FonctionInterface qui gèrera sa désallocation
	 * @param fonction : pointeur Fonction* alloué par new
	*/
	FonctionInterface& operator=(Fonction* fonction);


	/**
	 * Resultat de fonction
	 * @brief Retourne le résultat de l'objet Fonction contenu
	*/
	double Result();

	/**
	 * Dérivée de fonction
	 * @brief Retourne la dérivée de l'objet Fonction contenu par rapport à l'adresse d'une variable donnée
	 * @param pdComposant : adresse de la variable pour dériver la fonction
	*/
	FonctionInterface Derive(double* pdComposant);

	/**
	 * Copie de fonction
	 * @brief Retourne un objet FonctionInterface contenant une copie de l'objet Fonction
	*/
	FonctionInterface Copy();


	/**
	 * Affichage de fonction
	 * @brief Affiche la formule de l'objet Fonction pointé par pnFONFonction
	*/
	void Show();

	/**
	 * Constante égal à 0
	 * @brief Retourne vrai si l'objet Fonction contenu est constamment égal à 0
	*/
	bool Zero();

	/**
	 * Constante égal à 1
	 * @brief Retourne vrai si l'objet Fonction contenu est constamment égal à 1
	*/
	bool Un();

	/**
	 * Résultat constant
	 * @brief Retourne vrai si l'objet Fonction contenu peut être représenté par une constante
	*/
	bool Constant();

private:

	/**
	 * Allocation mémoire de l'objet Fonction contenu
	 * @brief Si dynamique est vrai, alors l'objet Fonction est une copie allouée en mémoire
	 * @brief Sinon l'objet Fonction contenu est une référence à l'objet Fonction donné.
	 * @param pFonction : pointeur d'un objet Fonction
	 * @param dynamique : Y a-t-il allocation d'une copie en mémoire ?
	*/
	void Alloc(Fonction* pFonction, bool dynamique);

	/**
	 * Desallocation mémoire de l'objet Fonction contenu
	 * @brief Desalloue l'objet Fonction contenu si bDynamique est vrai
	*/
	void Desalloc();
};
#endif;

