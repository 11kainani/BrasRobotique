#include "FonctionProduit.h"



FonctionProduit::FonctionProduit() : FonctionOperation()
{
}

FonctionProduit::FonctionProduit(ListFonction& fonctions) : FonctionOperation(fonctions)
{
	unsigned int uiTaille = LISFonctions.GetNbFonctions();
	double ElementNeutre = 1;
	ListFonction Temp(uiTaille);
	FonctionInterface FONConstante = new FonctionConstante(ElementNeutre);

	for (unsigned int i = 0; i < uiTaille; i++)
	{
		if (LISFonctions[i].Constant())
		{
			FONConstante = new FonctionConstante(FONConstante.Result() * LISFonctions[i].Result());
		}
		else
		{
			Temp.AddFonction(LISFonctions[i]);
		}
	}

	if (FONConstante.Result() != ElementNeutre || Temp.GetNbFonctions() == 0)
	{
		Temp.AddFonction(FONConstante);
	}

	LISFonctions = (ListFonction&)ListFonction(Temp);
}

FonctionProduit::~FonctionProduit()
{
	// Appel de ~FonctionOperation()
}


double FonctionProduit::Result()
{
	double resultat;
	unsigned int uiTaille = LISFonctions.GetNbFonctions();
	
	if (uiTaille == 0) { return 0; }

	resultat = 1;
	for (unsigned int i = 0; i < uiTaille; i++)
	{
		resultat *= LISFonctions[i].Result();
	}

	return resultat;
}

Fonction* FonctionProduit::Derive(double* pdComposant)
{
	unsigned int i, j, uiTaille;
	Fonction* pFONDerive;
	ListFonction LISDerives;
	ListFonction LISProduits;
	FonctionInterface DeriveInterface;

	uiTaille = LISFonctions.GetNbFonctions();
	if (uiTaille == 0) { return new FonctionConstante(0); }

	LISDerives = (ListFonction&)ListFonction(uiTaille);
	for (i = 0; i < uiTaille; i++)
	{
		LISProduits = (ListFonction&)ListFonction(uiTaille);
		for (j = 0; j < uiTaille; j++)
		{
			if (i == j) 
			{ 
				LISProduits.AddFonction((FonctionInterface&)LISFonctions[j].Derive(pdComposant)); 
			}
			else
			{
				LISProduits.AddFonction(LISFonctions[j], (LISFonctions[j].Constant() == false));
			}
		}
		DeriveInterface = new FonctionProduit(LISProduits);
		LISDerives.AddFonction(DeriveInterface);
	}
	pFONDerive = new FonctionSomme(LISDerives);

	return pFONDerive;

}

Fonction* FonctionProduit::Copy()
{
	unsigned int uiTaille;
	Fonction* pFONCopie;

	uiTaille = LISFonctions.GetNbFonctions();
	if (uiTaille == 0) { return new FonctionConstante(0); }

	pFONCopie = new FonctionProduit(*this);

	return pFONCopie;
}

void FonctionProduit::Show()
{
	unsigned int uiTaille = LISFonctions.GetNbFonctions();
	unsigned int uiNbNonNeutre = 0;

	if (uiTaille == 0 || Zero())
	{
		cout << "0";
		return;
	}

	if (Un())
	{
		cout << "1";
		return;
	}


	for (unsigned int i = 0; i < uiTaille; i++)
	{
		if (LISFonctions[i].Un() == false) { uiNbNonNeutre++; }
	}

	if (uiNbNonNeutre > 1) { cout << "("; }
	for (unsigned int i = 0; i < uiTaille - 1; i++)
	{
		if (LISFonctions[i].Un() == false)
		{
			LISFonctions[i].Show();
			if (LISFonctions[i + 1].Un() == false)
			{
				cout << " * ";
			}
		}
	}

	if (LISFonctions[uiTaille - 1].Un() == false)
	{
		LISFonctions[uiTaille - 1].Show();
	}
	if (uiNbNonNeutre > 1) { cout << ")"; }
}

bool FonctionProduit::Zero()
{
	unsigned int uiTaille = LISFonctions.GetNbFonctions();
	bool resultat = false;

	for (unsigned int i = 0; i < uiTaille && resultat == false; i++)
	{
		resultat = LISFonctions[i].Zero();
	}

	return resultat;
}

bool FonctionProduit::Un()
{
	unsigned int uiTaille = LISFonctions.GetNbFonctions();
	bool resultat = true;

	for (unsigned int i = 0; i < uiTaille && resultat; i++)
	{
		resultat = LISFonctions[i].Un();
	}
	
	return resultat;
}

FonctionConstante FonctionProduit::OperationConstante(FonctionInterface& constante1, FonctionInterface& constante2)
{
	return FonctionConstante(constante1.Result() * constante2.Result());
}

double FonctionProduit::ElementNeutre()
{
	return 1;
}

