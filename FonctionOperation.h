#ifndef FONCTION_OPERATION_H
#define FONCTION_OPERATION_H

#include "ListFonction.h"
#include "FonctionVariable.h"
#include "FonctionConstante.h"

/**
 * @brief Classe heritant de Fonction
 * Represente l'application d'une operation entre plusieurs formules f quelconques
 */
class FonctionOperation : public Fonction
{

protected:
	// Liste de sous fonctions f
	ListFonction LISFonctions;

public:

	/**
	 * Constructeur par defaut
	 * @brief Cree un objet vide
	*/
	FonctionOperation();

	/**
	 * Constructeur de recopie
	 * @brief Cree l'objet dont les elements de sa liste ont recupere par delegation les elements contenus dans la liste fournie
	 * @param fonctions : Liste de fonctions a recuperer
	*/
	FonctionOperation(ListFonction& fonctions);

	/**
	 * Constructeur de recopie
	 * @brief Cree l'objet dont les elements de sa liste pointent les elements contenus dans la liste de l'objet a copier
	 * @param FONOperationCopie : Objet a copier
	*/
	FonctionOperation(FonctionOperation& FONOperationCopie);

	/**
	 * Destructeur
	 * @brief Detruis la liste de fonction puis l'objet FonctionInterface
	*/
	~FonctionOperation();


	/**
	 * Surcharge de l'operateur =
	 * @brief Affecte les elements de sa liste pour pointer ceux dans la liste de l'objet a copier
	 * @param FONOperationCopie : Objet a copier
	*/
	FonctionOperation& operator=(FonctionOperation& FONOperationCopie);

	/**
	 * Surcharge de Fonction::Constant()
	 * @brief Retourne vrai si tous les elements de sa liste sont constants
	*/
	bool Constant();

protected:
	/**
	 * Creation d'une copie des sous fonctions
	 * @brief Retourne une copie de la liste de sous fonctions
	*/
	ListFonction Copies();

	/**
	 * Methode virtuelle pure
	 * @brief Retourne une fonction constante egale a l'application d'une operation entre deux fonctions constantes
	 * @param constante1 : Objet FonctionInterface representant une formule constante
	 * @param constante2 : Objet FonctionInterface representant une formule constante
	*/
	virtual FonctionConstante OperationConstante(FonctionInterface& constante1, FonctionInterface& constante2) = 0;

	/**
	 * Methode virtuelle pure
	 * @brief Retourne l'element neutre de l'operation
	*/
	virtual double ElementNeutre() = 0;
};
#endif

