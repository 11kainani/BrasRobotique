#ifndef FONCTION_INTERFACE_H
#define FONCTION_INTERFACE_H

#include "FonctionConstante.h"

/**
 * Classe contenant un pointeur polymorphique d'un objet Fonction
 * Elle permet de repr�senter n'importe quel objet h�ritant de la classe Fonction
 * Le pointeur est g�r� dynamiquement par la classe
*/
class FonctionInterface
{
	Fonction* pnFONFonction; // pointeur polymorphique d'une fonction
	bool bDynamique;  // Le pointeur est-il allou� par new ?
	bool bTemporaire; // L'objet est-il temporaire ?

public:


	/**
	 * Constructeur par d�faut
	 * @brief Cr�e un objet FonctionInterface ne contenant aucun objet Fonction
	*/
	FonctionInterface();

	/**
	 * Constructeur de comfort
	 * @brief Cr�e un objet FonctionInterface contenant un objet Fonction (ou classe fille)
	 * @param fonction : adresse d'un objet Fonction ou pointeur Fonction*
	 * @param bTemp : L'objet cr�� est-il temporaire ? (vrai par d�faut)
	*/
	FonctionInterface(Fonction* pFonction, bool bTemp = true);

	/**
	 * Constructeur de recopie
	 * @brief Cr�e un objet temporaire ayant r�cup�r� l'objet Fonction contenu dans un autre objet FonctionInterface
	 * @param FONInterface : Objet FonctionInterface dont le contenu sera r�cup�r� par d�l�gation
	*/
	FonctionInterface(FonctionInterface& FONInterface);

	/**
	 * Constructeur de d�placement
	 * @brief Cr�e un objet temporaire ayant r�cup�r� l'objet Fonction contenu dans un autre objet temporaire FonctionInterface
	 * @param FONInterface : Objet temporaire FonctionInterface dont le contenu sera r�cup�r� par d�l�gation
	*/
	FonctionInterface(FonctionInterface&& FONInterface);

	/**
	 * Destructeur
	 * @brief D�truis l'objet et, si bDynamique est vrai, l'objet Fonction contenu est d�sallou� de la m�moire
	*/
	~FonctionInterface();

	/**
	 * Initialiseur de comfort
	 * @brief Recr�e l'objet FonctionInterface pour contenir un objet Fonction (ou classe fille) donn�
	 * @param fonction : adresse d'un objet Fonction ou pointeur Fonction*
	 * @param bTemp : L'objet recr�� est-il temporaire ? (vrai par d�faut)
	*/
	void init(Fonction* pFonction, bool bTemp = true);

	
	/**
	 * Initialiseur de recopie
	 * @brief R�cup�re l'objet Fonction contenu dans un autre objet FonctionInterface
	 * @param FONInterface : Objet FonctionInterface dont le contenu sera r�cup�r� par d�l�gation
	*/
	void init(FonctionInterface FONInterface);


	/**
	 * Surcharge de l'op�rateur =
	 * @brief R�cup�re l'objet Fonction contenu dans l'objet de droite si celui-ci est temporaire
	 * @param FONInterface : Objet FonctionInterface dont le contenu sera r�cup�r� par d�l�gation si celui-ci est temporaire
	*/
	FonctionInterface& operator=(FonctionInterface& FONInterface);

	/**
	 * Surcharge de l'op�rateur =
	 * @brief R�cup�re l'objet Fonction contenu dans l'objet temporaire de droite
	 * @param FONInterface : Objet temporaire FonctionInterface dont le contenu sera r�cup�r� par d�l�gation
	*/
	FonctionInterface& operator=(FonctionInterface&& FONInterface);

	/**
	 * Surcharge de l'op�rateur =
	 * @brief Affecte le pointeur fournit � l'objet FonctionInterface qui g�rera sa d�sallocation
	 * @param fonction : pointeur Fonction* allou� par new
	*/
	FonctionInterface& operator=(Fonction* fonction);


	/**
	 * Resultat de fonction
	 * @brief Retourne le r�sultat de l'objet Fonction contenu
	*/
	double Result();

	/**
	 * D�riv�e de fonction
	 * @brief Retourne la d�riv�e de l'objet Fonction contenu par rapport � l'adresse d'une variable donn�e
	 * @param pdComposant : adresse de la variable pour d�river la fonction
	*/
	FonctionInterface Derive(double* pdComposant);

	/**
	 * Copie de fonction
	 * @brief Retourne un objet FonctionInterface contenant une copie de l'objet Fonction
	*/
	FonctionInterface Copy();


	/**
	 * Affichage de fonction
	 * @brief Affiche la formule de l'objet Fonction point� par pnFONFonction
	*/
	void Show();

	/**
	 * Constante �gal � 0
	 * @brief Retourne vrai si l'objet Fonction contenu est constamment �gal � 0
	*/
	bool Zero();

	/**
	 * Constante �gal � 1
	 * @brief Retourne vrai si l'objet Fonction contenu est constamment �gal � 1
	*/
	bool Un();

	/**
	 * R�sultat constant
	 * @brief Retourne vrai si l'objet Fonction contenu peut �tre repr�sent� par une constante
	*/
	bool Constant();

private:

	/**
	 * Allocation m�moire de l'objet Fonction contenu
	 * @brief Si dynamique est vrai, alors l'objet Fonction est une copie allou�e en m�moire
	 * @brief Sinon l'objet Fonction contenu est une r�f�rence � l'objet Fonction donn�.
	 * @param pFonction : pointeur d'un objet Fonction
	 * @param dynamique : Y a-t-il allocation d'une copie en m�moire ?
	*/
	void Alloc(Fonction* pFonction, bool dynamique);

	/**
	 * Desallocation m�moire de l'objet Fonction contenu
	 * @brief Desalloue l'objet Fonction contenu si bDynamique est vrai
	*/
	void Desalloc();
};
#endif;

