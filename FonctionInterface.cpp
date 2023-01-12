#include "FonctionInterface.h"



FonctionInterface::FonctionInterface()
{
	Alloc(nullptr, false);
	bTemporaire = false;
}

FonctionInterface::FonctionInterface(Fonction* pFonction, bool bTemp)
{
	Alloc(pFonction, true);
	bTemporaire = bTemp;
}

FonctionInterface::FonctionInterface(FonctionInterface& FONInterface)
{
	Alloc(FONInterface.pnFONFonction, false);
	bTemporaire = true;

	// delegation
	if (FONInterface.bDynamique)
	{
		bDynamique = true;
		FONInterface.bDynamique = false;
	}
}


FonctionInterface::~FonctionInterface()
{
	Desalloc();
}

FonctionInterface& FonctionInterface::operator=(FonctionInterface& FONInterface)
{
	Desalloc();
	Alloc(FONInterface.pnFONFonction, false);

	// delegation si l'objet est temporaire
	if (FONInterface.bTemporaire && FONInterface.bDynamique)
	{
		bDynamique = true;
		FONInterface.bDynamique = false;
	}

	return *this;
}

FonctionInterface& FonctionInterface::operator=(Fonction* fonction)
{
	Desalloc();
	Alloc(fonction, false);
	bDynamique = true;
	bTemporaire = true;

	return *this;
}

double FonctionInterface::Result()
{
	if (pnFONFonction == nullptr)
	{
		cout << "Erreur : Fonction null" << endl;
		return 0;
	}

	return pnFONFonction->Result();
}

FonctionInterface FonctionInterface::Derive(double* pdComposant)
{
	FonctionInterface DeriveInterface;

	if (pnFONFonction == nullptr) 
	{
		cout << "Erreur : Fonction null -> Derive null" << endl;
		return DeriveInterface; 
	}

	// DeriveInterface pointe la fonction resultante de Derive()
	DeriveInterface.pnFONFonction = pnFONFonction->Derive(pdComposant);
	DeriveInterface.bDynamique = true;  // DeriveInterface se chargera d'appeler l'instruction delete sur la fonction derive

	return DeriveInterface;
}

FonctionInterface FonctionInterface::Copy()
{
	FonctionInterface CopieInterface;
	CopieInterface.Alloc(pnFONFonction, true);

	return CopieInterface;
}

void FonctionInterface::Show()
{
	pnFONFonction->Show();
}

bool FonctionInterface::Zero()
{
	return pnFONFonction->Zero();
}

bool FonctionInterface::Un()
{
	return pnFONFonction->Un();
}

bool FonctionInterface::Constant()
{
	return pnFONFonction->Constant();
}

//// Fonctions privées ////
void FonctionInterface::Alloc(Fonction* pFonction, bool dynamique)
{
	pnFONFonction = nullptr;
	bDynamique = dynamique;
	if (pFonction == nullptr) { return; }

	if (bDynamique)
	{
		if (pFonction->Constant())
		{
			// Allocation d'une constante contenant le résultat
			pnFONFonction = new FonctionConstante(pFonction->Result());
		}
		else
		{
			// Allocation d'une copie de la fonction avec new
			pnFONFonction = pFonction->Copy();
		}
	}
	else
	{
		// L'interface pointe la même fonction
		pnFONFonction = pFonction;
	}
}

void FonctionInterface::Desalloc()
{
	if (pnFONFonction != nullptr)
	{
		if (bDynamique)
		{
			delete pnFONFonction;
		}
	}
	pnFONFonction = nullptr;

}
