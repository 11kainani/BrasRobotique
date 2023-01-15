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

	// Ajout par d�l�gation des objets FonctionInterface
	for (unsigned int i = 0; i < LISCopie.uiNbFonctions; i++)
	{
		AddFonction(LISCopie.pLISFonctions[i]);
	}
}

ListFonction::~ListFonction()
{
	Desalloc();
}

void ListFonction::init(unsigned int taille)
{
	Desalloc();
	Alloc(taille);
}

void ListFonction::init(ListFonction LISCopie)
{
	FonctionInterface FONElement;
	Desalloc();
	Alloc(LISCopie.uiNbFonctions);

	for (unsigned int i = 0; i < LISCopie.uiNbFonctions; i++)
	{
		AddFonction(LISCopie.pLISFonctions[i]);
	}
}


ListFonction& ListFonction::operator=(ListFonction& LISCopie)
{
	FonctionInterface FONElement;
	Desalloc();
	Alloc(LISCopie.uiTaille);

	// Recopie des �l�ments de LISCopie
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
		cout << "Erreur : indice d�pass� " << indice << ">" << (uiNbFonctions - 1) << endl;
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

	// S'il y a d�l�gation
	if (delegation)
	{
		// L'�l�ment de la liste r�cup�re l'objet Fonction contenu dans pFonction
		pLISFonctions[uiNbFonctions].init(pFonction);
	}
	else
	{
		// L'�l�ment de la liste alloue et conserve une copie de l'objet Fonction contenu dans pFonction
		pLISFonctions[uiNbFonctions] = pFonction.Copy();
	}

	uiNbFonctions++;
}

void ListFonction::AddFonction(FonctionInterface&& pFonction)
{
	if (uiNbFonctions == uiTaille)
	{
		cout << "Erreur : Liste complete" << endl;
		return;
	}

	// L'objet pFonction �tant temporaire, l'�l�ment r�cup�re l'objet Fonction qu'il contient
	pLISFonctions[uiNbFonctions].init(pFonction);

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

	// allocation d'un tableau d'objets initialis�s par le constructeur par d�faut
	pLISFonctions = new FonctionInterface[uiTaille];
}

void ListFonction::Desalloc()
{
	// D�ssalocation des �l�ments de la liste
	if (pLISFonctions != nullptr)
	{
		delete[] pLISFonctions;
	}
}
