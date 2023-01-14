#ifndef LIST_FONCTION_H
#define LIST_FONCTION_H

#include "FonctionInterface.h"

class ListFonction
{
	FonctionInterface* pLISFonctions; // Liste de fonctions
	unsigned int uiTaille;		// Taille de la liste de fonctions
	unsigned int uiNbFonctions; // Nombre de fonctions initialisées

public:
	ListFonction();
	ListFonction(unsigned int taille);
	ListFonction(ListFonction& LISCopie);
	~ListFonction();

	void init(unsigned int taille);
	void init(ListFonction LISCopie);

	ListFonction& operator=(ListFonction& LISCopie);
	FonctionInterface& operator[](int indice);
	void AddFonction(FonctionInterface& pFonction, bool delegation = true);
	unsigned int GetTaille();
	unsigned int GetNbFonctions();

private:
	void Alloc(unsigned int taille);
	void Desalloc();

};
#endif

