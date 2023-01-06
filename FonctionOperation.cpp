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
	bool resultat = true;

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
	
	uiTaille = LISFonctions.GetNbFonctions();
	copies = (ListFonction&)ListFonction(uiTaille);

	for (i = 0; i < uiTaille; i++)
	{
		copies.AddFonction(LISFonctions[i], false);
	}

	return copies;
}
