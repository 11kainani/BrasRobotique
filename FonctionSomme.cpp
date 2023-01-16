#include "FonctionSomme.h"



FonctionSomme::FonctionSomme() : FonctionOperation()
{
}


FonctionSomme::FonctionSomme(ListFonction& fonctions) : FonctionOperation(fonctions)
{
	unsigned int uiTaille = LISFonctions.GetNbFonctions();
	double ElementNeutre = 0;
	ListFonction Temp(uiTaille);
	FonctionInterface FONConstante = new FonctionConstante(ElementNeutre);

	for (unsigned int i = 0; i < uiTaille; i++)
	{
		if (LISFonctions[i].Constant())
		{
			FONConstante = new FonctionConstante(FONConstante.Result() + LISFonctions[i].Result());
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

	LISFonctions.init(Temp);
}

FonctionSomme::~FonctionSomme()
{
	// Appel de ~FonctionOperation()
}


double FonctionSomme::Result()
{
	double resultat = 0;
	unsigned int uiTaille = LISFonctions.GetNbFonctions();

	for (unsigned int i = 0; i < uiTaille; i++)
	{
		resultat += LISFonctions[i].Result();
	}

	return resultat;
}

Fonction* FonctionSomme::Derive(double* pdComposant)
{
	unsigned int i, uiTaille;
	Fonction* pFONDerive; // Resultat de la derivee
	ListFonction LISDerives(LISFonctions.GetNbFonctions());  // Derivees de chaque sous fonction


	// Resultat nul si aucune fonction
	uiTaille = LISFonctions.GetNbFonctions();
	if (uiTaille == 0) { return new FonctionConstante(0); }

	for (i = 0; i < uiTaille; i++)
	{
		// On ajoute la derivee de chaque sous fonction dans la liste
		LISDerives.AddFonction((LISFonctions[i].Derive(pdComposant)));
	}

	// Allocation par new et creation de copies des derives
	pFONDerive = new FonctionSomme(LISDerives);

	// Retour de la derivee contenant les elements
	return pFONDerive;
}

Fonction* FonctionSomme::Copy()
{
	Fonction* pFONCopie;
	unsigned int uiTaille = LISFonctions.GetNbFonctions();
	
	if (uiTaille == 0) { return new FonctionConstante(0); }

	// Allocation par new
	pFONCopie = new FonctionSomme(*this);

	return pFONCopie;
}

void FonctionSomme::Show()
{
	unsigned int uiTaille = LISFonctions.GetNbFonctions();
	unsigned int uiNbNonNeutre = 0;

	if (uiTaille == 0 || Zero()) 
	{ 
		cout << "0";
		return;
	}


	for (unsigned int i = 0; i < uiTaille; i++)
	{
		if (LISFonctions[i].Zero() == false) { uiNbNonNeutre++; }
	}

	if (uiNbNonNeutre > 1) { cout << "["; }
	for (unsigned int i = 0; i < uiTaille - 1; i++)
	{
		if (LISFonctions[i].Zero() == false)
		{
			LISFonctions[i].Show();
			if (LISFonctions[i + 1].Zero() == false)
			{
				cout << " + ";
			}
		}
	}
	if (LISFonctions[uiTaille - 1].Zero() == false)
	{
		LISFonctions[uiTaille - 1].Show();
	}
	if (uiNbNonNeutre > 1) { cout << "]"; }
}

bool FonctionSomme::Zero()
{
	unsigned int uiTaille = LISFonctions.GetNbFonctions();
	bool resultat = true;

	for (unsigned int i = 0; i < uiTaille && resultat; i++)
	{
		resultat = LISFonctions[i].Zero();
	}

	return resultat;
}

bool FonctionSomme::Un()
{
	return (Constant() && Result() == 1);
}

FonctionConstante FonctionSomme::OperationConstante(FonctionInterface& constante1, FonctionInterface& constante2)
{
	return FonctionConstante(constante1.Result() + constante2.Result());
}

double FonctionSomme::ElementNeutre()
{
	return 0;
}

