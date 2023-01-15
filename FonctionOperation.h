#ifndef FONCTION_OPERATION_H
#define FONCTION_OPERATION_H

#include "ListFonction.h"
#include "FonctionVariable.h"
#include "FonctionConstante.h"

/**
 * Classe héritant de Fonction
 * Représente l'application d'une operation entre plusieurs formules f quelconques
 */
class FonctionOperation : public Fonction
{

protected:
	// Liste de sous fonctions f
	ListFonction LISFonctions;

public:

	/**
	 * Constructeur par défaut
	 * @brief Crée un objet vide
	*/
	FonctionOperation();

	/**
	 * Constructeur de recopie
	 * @brief Crée l'objet dont les éléments de sa liste ont récupéré par délégation les éléments contenus dans la liste fournie
	 * @param fonctions : Liste de fonctions à récupérer
	*/
	FonctionOperation(ListFonction& fonctions);

	/**
	 * Constructeur de recopie
	 * @brief Crée l'objet dont les éléments de sa liste pointent les éléments contenus dans la liste de l'objet à copier
	 * @param FONOperationCopie : Objet à copier
	*/
	FonctionOperation(FonctionOperation& FONOperationCopie);

	/**
	 * Destructeur
	 * @brief Détruis la liste de fonction puis l'objet FonctionInterface
	*/
	~FonctionOperation();


	/**
	 * Surcharge de l'opérateur =
	 * @brief Affecte les éléments de sa liste pour pointer ceux dans la liste de l'objet à copier
	 * @param FONOperationCopie : Objet à copier
	*/
	FonctionOperation& operator=(FonctionOperation& FONOperationCopie);

	/**
	 * Surcharge de Fonction::Constant()
	 * @brief Retourne vrai si tous les éléments de sa liste sont constants
	*/
	bool Constant();

protected:
	/**
	 * Création d'une copie des sous fonctions
	 * @brief Retourne une copie de la liste de sous fonctions
	*/
	ListFonction Copies();

	/**
	 * Méthode virtuelle pure
	 * @brief Retourne une fonction constante égale à l'application d'une opération entre deux fonctions constantes
	 * @param constante1 : Objet FonctionInterface représentant une formule constante
	 * @param constante2 : Objet FonctionInterface représentant une formule constante
	*/
	virtual FonctionConstante OperationConstante(FonctionInterface& constante1, FonctionInterface& constante2) = 0;

	/**
	 * Méthode virtuelle pure
	 * @brief Retourne l'element neutre de l'operation
	*/
	virtual double ElementNeutre() = 0;
};
#endif

