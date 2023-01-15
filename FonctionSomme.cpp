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
	Fonction* pFONDerive; // Résultat de la dérivée
	ListFonction LISDerives(LISFonctions.GetNbFonctions());  // Dérivées de chaque sous fonction


	// Résultat nul si aucune fonction
	uiTaille = LISFonctions.GetNbFonctions();
	if (uiTaille == 0) { return new FonctionConstante(0); }

	for (i = 0; i < uiTaille; i++)
	{
		// On ajoute la dérivée de chaque sous fonction dans la liste
		LISDerives.AddFonction((LISFonctions[i].Derive(pdComposant)));
	}

	// Allocation par new et création de copies des dérivés
	pFONDerive = new FonctionSomme(LISDerives);

	// Retour de la dérivée contenant les éléments
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

	// Affiche 0 si aucune sous fonctions ou la somme égale constamment 0
	if (uiTaille == 0 || Zero()) 
	{ 
		cout << "0";
		return;
	}

	// On compte les sous fonctions qui ne sont pas constamment égal à 0 
	for (unsigned int i = 0; i < uiTaille; i++)
	{
		if (LISFonctions[i].Zero() == false) { uiNbNonNeutre++; }
	}

	// S'il y a plusieurs éléments non neutre, on les met entre crochets
	if (uiNbNonNeutre > 1) { cout << "["; }

	// Pour chaque sous fonction
	for (unsigned int i = 0; i < uiTaille - 1; i++)
	{
		// Si elle ne vaut pas constamment 0, elle est affichée
		if (LISFonctions[i].Zero() == false)
		{
			LISFonctions[i].Show();

			// Si la sous fonction suivante ne vaut pas constamment 0, on affiche le symbole d'addition
			if (LISFonctions[i + 1].Zero() == false)
			{
				cout << " + ";
			}
		}
	}

	// Si la dernière sous fonction ne vaut pas constamment 0, on l'affiche
	if (LISFonctions[uiTaille - 1].Zero() == false)
	{
		LISFonctions[uiTaille - 1].Show();
	}

	// S'il y avait plusieurs éléments non neutre, on les mets entre crochets
	if (uiNbNonNeutre > 1) { cout << "]"; }
}

bool FonctionSomme::Zero()
{
	unsigned int uiTaille = LISFonctions.GetNbFonctions();
	bool resultat = true;  // On considère toutes les sous fonctions constamment égal à 0

	// Parcours des sous fonctions jusqu'à trouver une fonction qui n'est pas constamment égale à 0
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

