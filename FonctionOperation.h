#ifndef FONCTION_OPERATION_H
#define FONCTION_OPERATION_H

#include "ListFonction.h"
#include "FonctionVariable.h"
#include "FonctionConstante.h"

class FonctionOperation : public Fonction
{

protected:
	// Liste de sous fonctions
	ListFonction LISFonctions;

public:
	FonctionOperation();
	FonctionOperation(ListFonction& fonctions);
	FonctionOperation(FonctionOperation& FONOperationCopie);
	~FonctionOperation();

	FonctionOperation& operator=(FonctionOperation& FONOperationCopie);
	bool Constant();

protected:
	// Retourne une copie de la liste de sous fonctions
	ListFonction Copies();

	// Retourne une fonction constante égale à l'application d'une opération entre deux fonctions constantes
	virtual FonctionConstante OperationConstante(FonctionInterface& constante1, FonctionInterface& constante2) = 0;

	// Retourne l'element neutre de l'operation
	virtual double ElementNeutre() = 0;
};
#endif

