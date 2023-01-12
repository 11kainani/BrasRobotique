#include "MatriceFonction.h"



MatriceFonction::MatriceFonction()
{
	uiNbLignes = 0;
	uiNbColonnes = 0;
}

MatriceFonction::MatriceFonction(unsigned int nbLignes, unsigned int nbColonnes)
{
	LISFonctions = (ListFonction&)ListFonction(nbLignes*nbColonnes);
	FonctionInterface FONElement;
	uiNbLignes = nbLignes;
	uiNbColonnes = nbColonnes;

	for (unsigned int i = 0; i < nbLignes; i++)
	{
		for (unsigned int j = 0; j < nbColonnes; j++)
		{
			FONElement = new FonctionConstante((i == j ? 1 : 0));
			LISFonctions.AddFonction(FONElement);
		}
	}
}

MatriceFonction::MatriceFonction(ListFonction fonctions, unsigned int nbLignes, unsigned int nbColonnes)
{
	LISFonctions = fonctions;
	uiNbLignes = nbLignes;
	uiNbColonnes = nbColonnes;
}

MatriceFonction::MatriceFonction(DenavitParameter& param, unsigned int num)
{
	LISFonctions = (ListFonction&)ListFonction(16);
	uiNbLignes = 4;
	uiNbColonnes = 4;

	FonctionInterface FONElement, Theta, D, Alpha, A, Zero, Un;
	FonctionInterface FONCos;
	FonctionInterface FONSin;
	ListFonction LISElements;

	char* th = (char*)malloc(sizeof(char) * 7);
	char* dd = (char*)malloc(sizeof(char) * 3);
	char* al = (char*)malloc(sizeof(char) * 7);
	char* aa = (char*)malloc(sizeof(char) * 3);

	th[0] = 't';
	th[1] = 'h';
	th[2] = 'e';
	th[3] = 't';
	th[4] = 'a';
	th[5] = '0'+num;
	th[6] = '\0';

	dd[0] = 'd';
	dd[1] = '0' + num;
	dd[2] = '\0';

	al[0] = 'a';
	al[1] = 'l';
	al[2] = 'p';
	al[3] = 'h';
	al[4] = 'a';
	al[5] = '0' + num;
	al[6] = '\0';

	aa[0] = 'a';
	aa[1] = '0' + num;
	aa[2] = '\0';


	Theta = (FonctionInterface&)Param(param, 0, th);	// theta
	D = (FonctionInterface&)Param(param, 1, dd);		// d
	Alpha = (FonctionInterface&)Param(param, 2, al);	// alpha
	A = (FonctionInterface&)Param(param, 3, aa);		// a
	Zero = new FonctionConstante(0);	// 0
	Un = new FonctionConstante(1);		// 1

	// cos(theta)
	FONCos = new FonctionCos((FonctionInterface&)Theta.Copy());
	LISFonctions.AddFonction(FONCos);
	//////

	// -1 * sin(theta) * cos(alpha)
	LISElements = (ListFonction&)ListFonction(3);

	FONElement = new FonctionConstante(-1);
	LISElements.AddFonction(FONElement); // -1

	FONSin = new FonctionSin((FonctionInterface&)Theta.Copy());
	LISElements.AddFonction(FONSin); // sin(theta)

	FONCos = new FonctionCos((FonctionInterface&)Alpha.Copy());
	LISElements.AddFonction(FONCos); // cos(alpha)

	FONElement = new FonctionProduit(LISElements); // -1*sin(theta)*cos(alpha)
	LISFonctions.AddFonction(FONElement);
	//////


	// sin(theta) * sin(alpha)
	LISElements = (ListFonction&)ListFonction(2);

	FONSin = new FonctionSin((FonctionInterface&)Theta.Copy());
	LISElements.AddFonction(FONSin); // sin(theta)

	FONSin = new FonctionSin((FonctionInterface&)Alpha.Copy());
	LISElements.AddFonction(FONSin); // sin(alpha)

	FONElement = new FonctionProduit(LISElements); // sin(theta)*sin(alpha)
	LISFonctions.AddFonction(FONElement);
	//////

	// a * cos(theta)
	LISElements = (ListFonction&)ListFonction(2);

	LISElements.AddFonction(A, false);

	FONCos = new FonctionCos((FonctionInterface&)Theta.Copy());
	LISElements.AddFonction(FONCos); // cos(theta)

	FONElement = new FonctionProduit(LISElements); // a * cos(theta)
	LISFonctions.AddFonction(FONElement);
	//////

	// sin(theta)
	FONSin = new FonctionSin((FonctionInterface&)Theta.Copy());
	LISFonctions.AddFonction(FONSin); // sin(theta)
	//////

	// cos(theta) * cos(alpha)
	LISElements = (ListFonction&)ListFonction(2);

	FONCos = new FonctionCos((FonctionInterface&)Theta.Copy());
	LISElements.AddFonction(FONCos); // cos(theta)

	FONCos = new FonctionCos((FonctionInterface&)Alpha.Copy());
	LISElements.AddFonction(FONCos); // cos(alpha)

	FONElement = new FonctionProduit(LISElements); // cos(theta) * cos(alpha)
	LISFonctions.AddFonction(FONElement);
	//////

	// -1 * cos(theta) * sin(alpha)
	LISElements = (ListFonction&)ListFonction(3);

	FONElement = new FonctionConstante(-1);
	LISElements.AddFonction(FONElement); // -1

	FONCos = new FonctionCos((FonctionInterface&)Theta.Copy());
	LISElements.AddFonction(FONCos); // cos(theta)

	FONSin = new FonctionSin((FonctionInterface&)Alpha.Copy());
	LISElements.AddFonction(FONSin); // sin(alpha)

	FONElement = new FonctionProduit(LISElements); // -1*cos(theta)*sin(alpha)
	LISFonctions.AddFonction(FONElement);
	//////

	// a * sin(theta)
	LISElements = (ListFonction&)ListFonction(2);

	LISElements.AddFonction(A, false);

	FONSin = new FonctionSin((FonctionInterface&)Theta.Copy());
	LISElements.AddFonction(FONSin); // sin(theta)

	FONElement = new FonctionProduit(LISElements); // a * sin(theta)
	LISFonctions.AddFonction(FONElement);
	//////

	// 0
	LISFonctions.AddFonction(Zero);
	//////

	// sin(alpha)
	FONSin = new FonctionSin((FonctionInterface&)Alpha.Copy());
	LISFonctions.AddFonction(FONSin); // sin(alpha)
	//////

	// cos(alpha)
	FONCos = new FonctionCos((FonctionInterface&)Alpha.Copy());
	LISFonctions.AddFonction(FONCos); // cos(alpha)
	//////

	// d
	LISFonctions.AddFonction(D); // d
	//////

	// 0
	LISFonctions.AddFonction(Zero);
	//////

	// 0
	LISFonctions.AddFonction(Zero);
	//////

	// 0
	LISFonctions.AddFonction(Zero);
	//////

	// 1
	LISFonctions.AddFonction(Un);
	//////

}

MatriceFonction::MatriceFonction(MatriceFonction& MATCopie)
{
	LISFonctions = MATCopie.LISFonctions;
	uiNbLignes = MATCopie.uiNbLignes;
	uiNbColonnes = MATCopie.uiNbColonnes;
}


MatriceFonction::~MatriceFonction()
{
}


CMatrice MatriceFonction::Result()
{
	double* elements;
	double zero = 0;
	
	if (uiNbColonnes == 0 || uiNbLignes == 0) { return CMatrice(1, 1, &zero); }

	elements = (double*)malloc(sizeof(double)*uiNbLignes*uiNbColonnes);
	for (unsigned int i = 0; i < uiNbColonnes*uiNbLignes; i++)
	{
		elements[i] = LISFonctions[i].Result();
	}


	CMatrice result(uiNbLignes, uiNbColonnes, elements);
	free(elements);

	return result;
	
}


MatriceFonction& MatriceFonction::operator=(MatriceFonction& MATMatrice)
{
	LISFonctions = MATMatrice.LISFonctions;
	uiNbLignes = MATMatrice.uiNbLignes;
	uiNbColonnes = MATMatrice.uiNbColonnes;

	return *this;
}

MatriceFonction MatriceFonction::operator*(MatriceFonction& MATMatrice)
{
	ListFonction LISSommes;			// liste de sommes de produits de fonctions
	ListFonction LISProduits;		// liste de produits de fonctions
	ListFonction LISElements;		// liste de fonctions
	FonctionInterface FONElement;	// Element à ajouter à une liste
	unsigned int nbLignes, nbColonnes, i, j, k;

	if (uiNbColonnes != MATMatrice.uiNbLignes) 
	{
		cout << "Erreur : Nombre de colonnes et lignes différents " << uiNbColonnes << " != " << MATMatrice.uiNbLignes << endl;
		exit(1);
	}

	nbLignes = uiNbLignes;
	nbColonnes = MATMatrice.uiNbColonnes;

	LISSommes = (ListFonction&)ListFonction(nbLignes*nbColonnes);
	for (i = 0; i < nbLignes; i++)
	{
		for (j = 0; j < nbColonnes; j++)
		{
			LISProduits = (ListFonction&)ListFonction(uiNbColonnes);
			for (k = 0; k < uiNbColonnes; k++)
			{
				// a(i, k) * b(k, j)
				LISElements = (ListFonction&)ListFonction(2);
				LISElements.AddFonction(LISFonctions[i*uiNbColonnes + k], false);
				LISElements.AddFonction(MATMatrice.LISFonctions[k*MATMatrice.uiNbColonnes + j], false);

				FONElement = new FonctionProduit(LISElements);
				LISProduits.AddFonction(FONElement);
			}

			
			FONElement = new FonctionSomme(LISProduits);
			LISSommes.AddFonction(FONElement);
		}
	}

	MatriceFonction resultat(LISSommes, nbLignes, nbColonnes);
	return resultat;
}

ListFonction MatriceFonction::getElements()
{
	unsigned int uiTaille = LISFonctions.GetNbFonctions();
	ListFonction LISCopie(uiTaille);

	for (unsigned int i = 0; i < uiTaille; i++)
	{
		LISCopie.AddFonction(LISFonctions[i], false);
	}

	return LISCopie;
}

ListFonction MatriceFonction::operator[](unsigned int uiIndice)
{
	ListFonction LISLigne;
	FonctionInterface FONElement;

	if (uiIndice >= uiNbLignes) 
	{
		cout << "Erreur indice ligne dépassé " << uiIndice << "<" << uiNbLignes << endl;
		return LISLigne;
	}

	LISLigne = (ListFonction&)ListFonction(uiNbColonnes);
	for (unsigned int i = 0; i < uiNbColonnes; i++)
	{
		FONElement = LISFonctions[uiIndice*uiNbColonnes + i];
		LISLigne.AddFonction(FONElement);
	}

	return LISLigne;
}


void MatriceFonction::Show()
{
	if (uiNbColonnes == 0 || uiNbLignes == 0) 
	{
		cout << "(0)" << endl; 
		return;
	}

	for (unsigned int i = 0; i < uiNbLignes; i++)
	{
		cout << "| ";
		for (unsigned int j = 0; j < uiNbColonnes-1; j++)
		{
			LISFonctions[i*uiNbColonnes + j].Show(); cout << ", ";
		}
		LISFonctions[i*uiNbColonnes + uiNbColonnes - 1].Show(); cout << " |" << endl;
	}

}


FonctionInterface MatriceFonction::Param(DenavitParameter& param, unsigned int uiIndice, const char* nom)
{
	FonctionInterface FONInterface;
	
	if (param.LireBVariable(uiIndice) == false)
	{
		FONInterface = new FonctionConstante(param.LireValeur(uiIndice));
	}
	else
	{
		FONInterface = new FonctionVariable(param.LireVariable(uiIndice), nom);
	}

	return FONInterface;
}
