#ifndef FONCTION_INTERFACE_H
#define FONCTION_INTERFACE_H

#include "FonctionConstante.h"

/**
 * @brief Classe contenant un pointeur polymorphique d'un objet Fonction
 * Elle permet de representer n'importe quel objet heritant de la classe Fonction
 * Le pointeur est gere dynamiquement par la classe
*/
class FonctionInterface
{
	Fonction* pnFONFonction; // pointeur polymorphique d'une fonction
	bool bDynamique;  // Le pointeur est-il alloue par new ?
	bool bTemporaire; // L'objet est-il temporaire ?

public:


	/**
	 * Constructeur par defaut
	 * @brief Cree un objet FonctionInterface ne contenant aucun objet Fonction
	*/
	FonctionInterface();

	/**
	 * Constructeur de comfort
	 * @brief Cree un objet FonctionInterface contenant un objet Fonction (ou classe fille)
	 * @param fonction : adresse d'un objet Fonction ou pointeur Fonction*
	 * @param bTemp : L'objet cree est-il temporaire ? (vrai par defaut)
	*/
	FonctionInterface(Fonction* pFonction, bool bTemp = true);

	/**
	 * Constructeur de recopie
	 * @brief Cree un objet temporaire ayant recupere l'objet Fonction contenu dans un autre objet FonctionInterface
	 * @param FONInterface : Objet FonctionInterface dont le contenu sera recupere par delegation
	*/
	FonctionInterface(FonctionInterface& FONInterface);

	/**
	 * Constructeur de deplacement
	 * @brief Cree un objet temporaire ayant recupere l'objet Fonction contenu dans un autre objet temporaire FonctionInterface
	 * @param FONInterface : Objet temporaire FonctionInterface dont le contenu sera recupere par delegation
	*/
	FonctionInterface(FonctionInterface&& FONInterface);

	/**
	 * Destructeur
	 * @brief Detruis l'objet et, si bDynamique est vrai, l'objet Fonction contenu est desalloue de la memoire
	*/
	~FonctionInterface();

	/**
	 * Initialiseur de comfort
	 * @brief Recree l'objet FonctionInterface pour contenir un objet Fonction (ou classe fille) donne
	 * @param fonction : adresse d'un objet Fonction ou pointeur Fonction*
	 * @param bTemp : L'objet recree est-il temporaire ? (vrai par defaut)
	*/
	void init(Fonction* pFonction, bool bTemp = true);

	
	/**
	 * Initialiseur de recopie
	 * @brief Recupere l'objet Fonction contenu dans un autre objet FonctionInterface
	 * @param FONInterface : Objet FonctionInterface dont le contenu sera recupere par delegation
	*/
	void init(FonctionInterface FONInterface);


	/**
	 * Surcharge de l'operateur =
	 * @brief Recupere l'objet Fonction contenu dans l'objet de droite si celui-ci est temporaire
	 * @param FONInterface : Objet FonctionInterface dont le contenu sera recupere par delegation si celui-ci est temporaire
	*/
	FonctionInterface& operator=(FonctionInterface& FONInterface);

	/**
	 * Surcharge de l'operateur =
	 * @brief Recupere l'objet Fonction contenu dans l'objet temporaire de droite
	 * @param FONInterface : Objet temporaire FonctionInterface dont le contenu sera recupere par delegation
	*/
	FonctionInterface& operator=(FonctionInterface&& FONInterface);

	/**
	 * Surcharge de l'operateur =
	 * @brief Affecte le pointeur fournit a l'objet FonctionInterface qui gerera sa desallocation
	 * @param fonction : pointeur Fonction* alloue par new
	*/
	FonctionInterface& operator=(Fonction* fonction);


	/**
	 * Resultat de fonction
	 * @brief Retourne le resultat de l'objet Fonction contenu
	*/
	double Result();

	/**
	 * Derivee de fonction
	 * @brief Retourne la derivee de l'objet Fonction contenu par rapport a l'adresse d'une variable donnee
	 * @param pdComposant : adresse de la variable pour deriver la fonction
	*/
	FonctionInterface Derive(double* pdComposant);

	/**
	 * Copie de fonction
	 * @brief Retourne un objet FonctionInterface contenant une copie de l'objet Fonction
	*/
	FonctionInterface Copy();


	/**
	 * Affichage de fonction
	 * @brief Affiche la formule de l'objet Fonction pointe par pnFONFonction
	*/
	void Show();

	/**
	 * Constante egal a 0
	 * @brief Retourne vrai si l'objet Fonction contenu est constamment egal a 0
	*/
	bool Zero();

	/**
	 * Constante egal a 1
	 * @brief Retourne vrai si l'objet Fonction contenu est constamment egal a 1
	*/
	bool Un();

	/**
	 * Resultat constant
	 * @brief Retourne vrai si l'objet Fonction contenu peut etre represente par une constante
	*/
	bool Constant();

private:

	/**
	 * Allocation memoire de l'objet Fonction contenu
	 * @brief Si dynamique est vrai, alors l'objet Fonction est une copie allouee en memoire
	 * @brief Sinon l'objet Fonction contenu est une reference a l'objet Fonction donne.
	 * @param pFonction : pointeur d'un objet Fonction
	 * @param dynamique : Y a-t-il allocation d'une copie en memoire ?
	*/
	void Alloc(Fonction* pFonction, bool dynamique);

	/**
	 * Desallocation memoire de l'objet Fonction contenu
	 * @brief Desalloue l'objet Fonction contenu si bDynamique est vrai
	*/
	void Desalloc();
};
#endif

