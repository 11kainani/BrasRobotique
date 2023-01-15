#ifndef FONCTION_OPERATION_H
#define FONCTION_OPERATION_H

#include "ListFonction.h"
#include "FonctionVariable.h"
#include "FonctionConstante.h"

/**
 * Classe h�ritant de Fonction
 * Repr�sente l'application d'une operation entre plusieurs formules f quelconques
 */
class FonctionOperation : public Fonction
{

protected:
	// Liste de sous fonctions f
	ListFonction LISFonctions;

public:

	/**
	 * Constructeur par d�faut
	 * @brief Cr�e un objet vide
	*/
	FonctionOperation();

	/**
	 * Constructeur de recopie
	 * @brief Cr�e l'objet dont les �l�ments de sa liste ont r�cup�r� par d�l�gation les �l�ments contenus dans la liste fournie
	 * @param fonctions : Liste de fonctions � r�cup�rer
	*/
	FonctionOperation(ListFonction& fonctions);

	/**
	 * Constructeur de recopie
	 * @brief Cr�e l'objet dont les �l�ments de sa liste pointent les �l�ments contenus dans la liste de l'objet � copier
	 * @param FONOperationCopie : Objet � copier
	*/
	FonctionOperation(FonctionOperation& FONOperationCopie);

	/**
	 * Destructeur
	 * @brief D�truis la liste de fonction puis l'objet FonctionInterface
	*/
	~FonctionOperation();


	/**
	 * Surcharge de l'op�rateur =
	 * @brief Affecte les �l�ments de sa liste pour pointer ceux dans la liste de l'objet � copier
	 * @param FONOperationCopie : Objet � copier
	*/
	FonctionOperation& operator=(FonctionOperation& FONOperationCopie);

	/**
	 * Surcharge de Fonction::Constant()
	 * @brief Retourne vrai si tous les �l�ments de sa liste sont constants
	*/
	bool Constant();

protected:
	/**
	 * Cr�ation d'une copie des sous fonctions
	 * @brief Retourne une copie de la liste de sous fonctions
	*/
	ListFonction Copies();

	/**
	 * M�thode virtuelle pure
	 * @brief Retourne une fonction constante �gale � l'application d'une op�ration entre deux fonctions constantes
	 * @param constante1 : Objet FonctionInterface repr�sentant une formule constante
	 * @param constante2 : Objet FonctionInterface repr�sentant une formule constante
	*/
	virtual FonctionConstante OperationConstante(FonctionInterface& constante1, FonctionInterface& constante2) = 0;

	/**
	 * M�thode virtuelle pure
	 * @brief Retourne l'element neutre de l'operation
	*/
	virtual double ElementNeutre() = 0;
};
#endif

