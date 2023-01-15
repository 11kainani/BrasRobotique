#include "FonctionOperation.h"



FonctionOperation::FonctionOperation()
{
}

FonctionOperation::FonctionOperation(ListFonction& fonctions)
{
	LISFonctions = fonctions;
}

FonctionOperation::FonctionOperation(FonctionOperation& FONOperationCopie)
{
	LISFonctions = FONOperationCopie.LISFonctions;
}

FonctionOperation::~FonctionOperation()
{
	// Appel de ~Fonction()
}

FonctionOperation& FonctionOperation::operator=(FonctionOperation& FONOperationCopie)
{
	LISFonctions = FONOperationCopie.LISFonctions;

	return *this;
}

bool FonctionOperation::Constant()
{
	unsigned int uiTaille = LISFonctions.GetNbFonctions();
	bool resultat = true;  // On consid�re tous les �l�ments constants

	// Parcours des �l�ments jusqu'� trouver un �l�ment non constant
	for (unsigned int i = 0; i < uiTaille && resultat; i++)
	{
		resultat = LISFonctions[i].Constant();
	}

	return resultat;
}

ListFonction FonctionOperation::Copies()
{
	ListFonction copies;
	unsigned int i, uiTaille;
	
	// Allocation d'une liste pour contenir seulement les �l�ments initialis�es de la liste
	uiTaille = LISFonctions.GetNbFonctions();
	copies.init(uiTaille);

	// Allocation de copie de chaque �l�ment de la liste
	for (i = 0; i < uiTaille; i++)
	{
		copies.AddFonction(LISFonctions[i], false);
	}

	return copies;
}
