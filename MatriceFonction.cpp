#include "MatriceFonction.h"



MatriceFonction::MatriceFonction()
{
	uiNbLignes = 0;
	uiNbColonnes = 0;
}

MatriceFonction::MatriceFonction(unsigned int nbLignes, unsigned int nbColonnes)
{
	LISFonctions = (ListFonction&)ListFonction(nbLignes * nbColonnes);
	FonctionInterface FONElement;
	uiNbLignes = nbLignes;
	uiNbColonnes = nbColonnes;

	for (unsigned int i = 0; i < nbLignes; i++)
	{
		for (unsigned int j = 0; j < nbColonnes; j++)
		{
			FonctionConstante fConst((i == j ? 1 : 0));
			FONElement = &fConst;
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
	th[5] = '0' + num;
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
	
	FonctionConstante fZero(0);
	Zero = &fZero;	// 0
	FonctionConstante fUn(1);
	Un = &fUn;		// 1

	// cos(theta)
	FonctionCos fCos1((FonctionInterface&)Theta.Copy());
	FONCos = &fCos1;
	LISFonctions.AddFonction(FONCos);
	//////

	// -1 * sin(theta) * cos(alpha)
	LISElements = (ListFonction&)ListFonction(3);
	
	FonctionConstante fConst2(-1);
	FONElement = &fConst2;
	LISElements.AddFonction(FONElement); // -1


	FonctionSin fSin2((FonctionInterface&)Theta.Copy());
	FONSin = &(fSin2);
	LISElements.AddFonction(FONSin); // sin(theta)

	FonctionCos fCos2((FonctionInterface&)Alpha.Copy());
	FONCos = &(fCos2);
	LISElements.AddFonction(FONCos); // cos(alpha)

	FonctionProduit fProd2(LISElements);
	FONElement = &fProd2; // -1*sin(theta)*cos(alpha)
	LISFonctions.AddFonction(FONElement);
	//////


	// sin(theta) * sin(alpha)
	LISElements = (ListFonction&)ListFonction(2);

	FonctionSin fSin3((FonctionInterface&)Theta.Copy());
	FONSin = &(fSin3);
	LISElements.AddFonction(FONSin); // sin(theta)
	
	FonctionSin fSin3_2((FonctionInterface&)Alpha.Copy());
	FONSin = &(fSin3_2);
	LISElements.AddFonction(FONSin); // sin(alpha)
	
	FonctionProduit fProd3(LISElements);
	FONElement = &fProd3; // sin(theta)*sin(alpha)
	LISFonctions.AddFonction(FONElement);
	//////

	// a * cos(theta)
	LISElements = (ListFonction&)ListFonction(2);

	LISElements.AddFonction(A, false);

	FonctionCos fCos4((FonctionInterface&)Theta.Copy());
	FONCos = &(fCos4);
	LISElements.AddFonction(FONCos); // cos(theta)

	FonctionProduit fProd4(LISElements);
	FONElement = &fProd4; // a * cos(theta)
	LISFonctions.AddFonction(FONElement);
	//////

	// sin(theta)
	FonctionSin fSin5((FonctionInterface&)Theta.Copy());
	FONSin = &(fSin5);
	LISFonctions.AddFonction(FONSin); // sin(theta)
	//////

	// cos(theta) * cos(alpha)
	LISElements = (ListFonction&)ListFonction(2);

	FonctionCos fCos6((FonctionInterface&)Theta.Copy());
	FONCos = &(fCos6);
	LISElements.AddFonction(FONCos); // cos(theta)

	FonctionCos fCos6_2((FonctionInterface&)Alpha.Copy());
	FONCos = &(fCos6_2);
	LISElements.AddFonction(FONCos); // cos(alpha)

	FonctionProduit fProd6(LISElements);
	FONElement = &fProd6; // cos(theta) * cos(alpha)
	LISFonctions.AddFonction(FONElement);
	//////

	// -1 * cos(theta) * sin(alpha)
	LISElements = (ListFonction&)ListFonction(3);

	FonctionConstante moinsUn(-1);
	FONElement = &moinsUn;
	LISElements.AddFonction(FONElement); // -1

	FonctionCos fCos7((FonctionInterface&)Theta.Copy());
	FONCos = &(fCos7);
	LISElements.AddFonction(FONCos); // cos(theta)

	FonctionSin fSin7((FonctionInterface&)Alpha.Copy());
	FONSin = &(fSin7);
	LISElements.AddFonction(FONSin); // sin(alpha)

	FonctionProduit fProduit6(LISElements);
	FONElement = &fProduit6; // -1*cos(theta)*sin(alpha)
	LISFonctions.AddFonction(FONElement);
	//////

	// a * sin(theta)
	LISElements = (ListFonction&)ListFonction(2);

	LISElements.AddFonction(A, false);

	FonctionSin fs((FonctionInterface&)Theta.Copy());
	FONSin = &(fs);
	LISElements.AddFonction(FONSin); // sin(theta)

	FonctionProduit fp(LISElements);
	FONElement = &fp; // a * sin(theta)
	LISFonctions.AddFonction(FONElement);
	//////

	// 0
	LISFonctions.AddFonction(Zero);
	//////

	// sin(alpha)
	FonctionSin fsinAlpha((FonctionInterface&)Alpha.Copy());
	FONSin = &(fsinAlpha);
	LISFonctions.AddFonction(FONSin); // sin(alpha)
	//////

	// cos(alpha)
	FonctionCos fc((FonctionInterface&)Alpha.Copy());
	FONCos = &(fc);
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

	elements = (double*)malloc(sizeof(double) * uiNbLignes * uiNbColonnes);
	for (unsigned int i = 0; i < uiNbColonnes * uiNbLignes; i++)
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
	FonctionInterface FONElement;	// Element � ajouter � une liste
	unsigned int nbLignes, nbColonnes, i, j, k;

	if (uiNbColonnes != MATMatrice.uiNbLignes)
	{
		cout << "Erreur : Nombre de colonnes et lignes diff�rents " << uiNbColonnes << " != " << MATMatrice.uiNbLignes << endl;
		exit(1);
	}

	nbLignes = uiNbLignes;
	nbColonnes = MATMatrice.uiNbColonnes;

	LISSommes = (ListFonction&)ListFonction(nbLignes * nbColonnes);
	for (i = 0; i < nbLignes; i++)
	{
		for (j = 0; j < nbColonnes; j++)
		{
			LISProduits = (ListFonction&)ListFonction(uiNbColonnes);
			for (k = 0; k < uiNbColonnes; k++)
			{
				// a(i, k) * b(k, j)
				LISElements = (ListFonction&)ListFonction(2);
				LISElements.AddFonction(LISFonctions[i * uiNbColonnes + k], false);
				LISElements.AddFonction(MATMatrice.LISFonctions[k * MATMatrice.uiNbColonnes + j], false);

				FonctionProduit fp(LISElements);
				FONElement = &fp;
				LISProduits.AddFonction(FONElement);
			}

			FonctionSomme fs(LISProduits);
			FONElement = &fs;
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
		cout << "Erreur indice ligne d�pass� " << uiIndice << "<" << uiNbLignes << endl;
		return LISLigne;
	}

	LISLigne = (ListFonction&)ListFonction(uiNbColonnes);
	for (unsigned int i = 0; i < uiNbColonnes; i++)
	{
		FONElement = LISFonctions[uiIndice * uiNbColonnes + i];
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
		for (unsigned int j = 0; j < uiNbColonnes - 1; j++)
		{
			LISFonctions[i * uiNbColonnes + j].Show(); cout << ", ";
		}
		LISFonctions[i * uiNbColonnes + uiNbColonnes - 1].Show(); cout << " |" << endl;
	}

}


FonctionInterface MatriceFonction::Param(DenavitParameter& param, unsigned int uiIndice, const char* nom)
{
	FonctionInterface FONInterface;

	if (param.LireBVariable(uiIndice) == false)
	{
		FonctionConstante fc(param.LireValeur(uiIndice));
		FONInterface = &fc;
	}
	else
	{
		FonctionVariable fv(param.LireVariable(uiIndice), nom);
		FONInterface = &fv;
	}

	return FONInterface;
}