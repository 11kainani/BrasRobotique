#include "ListFonction.h"



ListFonction::ListFonction()
{
	pLISFonctions = nullptr;
	uiTaille = 0;
	uiNbFonctions = 0;
}

ListFonction::ListFonction(unsigned int taille)
{
	Alloc(taille);
}

ListFonction::ListFonction(ListFonction& LISCopie)
{
	FonctionInterface FONElement;
	Alloc(LISCopie.uiNbFonctions);

	for (unsigned int i = 0; i < LISCopie.uiNbFonctions; i++)
	{
		AddFonction(LISCopie.pLISFonctions[i]);
	}
}

ListFonction::~ListFonction()
{
	Desalloc();
}

ListFonction& ListFonction::operator=(ListFonction& LISCopie)
{
	FonctionInterface FONElement;
	Desalloc();
	Alloc(LISCopie.uiTaille);

	// Recopie des éléments de LISCopie
	for (unsigned int i = 0; i < LISCopie.uiNbFonctions; i++)
	{
		AddFonction(LISCopie.pLISFonctions[i]);
	}

	return *this;
}

FonctionInterface& ListFonction::operator[](int indice)
{
	if (indice >= (int)uiNbFonctions)
	{
		cout << "Erreur : indice dépassé " << indice << ">" << (uiNbFonctions - 1) << endl;
		exit(1);
	}

	if (indice < 0)
	{
		cout << "Erreur : indice negatif " << indice << "<0" << endl;
		exit(1);
	}

	return pLISFonctions[indice];
}

void ListFonction::AddFonction(FonctionInterface& pFonction, bool delegation)
{
	if(uiNbFonctions == uiTaille) 
	{
		cout << "Erreur : Liste complete" << endl;
		return;
	}

	if (delegation)
	{
		pLISFonctions[uiNbFonctions] = (FonctionInterface&)FonctionInterface(pFonction);
	}
	else
	{
		pLISFonctions[uiNbFonctions] = (FonctionInterface&)pFonction.Copy();
	}

	uiNbFonctions++;
}

unsigned int ListFonction::GetTaille()
{
	return uiTaille;
}

unsigned int ListFonction::GetNbFonctions()
{
	return uiNbFonctions;
}

void ListFonction::Alloc(unsigned int taille)
{
	pLISFonctions = nullptr;
	uiTaille = taille;
	uiNbFonctions = 0;

	if (uiTaille == 0) { return; }

	pLISFonctions = new FonctionInterface[uiTaille];
}

void ListFonction::Desalloc()
{
	// Déssalocation des éléments de la liste
	if (pLISFonctions != nullptr)
	{
		delete[] pLISFonctions;
	}
}
