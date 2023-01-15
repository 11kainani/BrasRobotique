#include "MatriceFonction.h"



MatriceFonction::MatriceFonction()
{
	uiNbLignes = 0;
	uiNbColonnes = 0;
}

MatriceFonction::MatriceFonction(unsigned int nbLignes, unsigned int nbColonnes)
{
	init(nbLignes, nbColonnes);
}

MatriceFonction::MatriceFonction(ListFonction fonctions, unsigned int nbLignes, unsigned int nbColonnes)
{
	init(fonctions, nbLignes, nbColonnes);
}

MatriceFonction::MatriceFonction(DenavitParameter& param, unsigned int num)
{
	init(param, num);

}

MatriceFonction::MatriceFonction(MatriceFonction& MATCopie)
{
	LISFonctions = MATCopie.LISFonctions;
	uiNbLignes = MATCopie.uiNbLignes;
	uiNbColonnes = MATCopie.uiNbColonnes;
}

MatriceFonction::MatriceFonction(MatriceFonction&& MATCopie)
{
	LISFonctions = MATCopie.LISFonctions;
	uiNbLignes = MATCopie.uiNbLignes;
	uiNbColonnes = MATCopie.uiNbColonnes;
}

MatriceFonction::~MatriceFonction()
{
	// Destruction de LISFonctions
}

void MatriceFonction::init(unsigned int nbLignes, unsigned int nbColonnes)
{
	LISFonctions.init(nbLignes*nbColonnes);
	FonctionInterface FONElement;
	uiNbLignes = nbLignes;
	uiNbColonnes = nbColonnes;

	// Pour chaque ligne
	for (unsigned int i = 0; i < nbLignes; i++)
	{
		// Pour chaque colonne
		for (unsigned int j = 0; j < nbColonnes; j++)
		{
			// Cr�ation d'une valeur constante �gale � 1 dans la diagonal et � 0 pour le reste
			FONElement = new FonctionConstante((i == j ? 1 : 0));
			LISFonctions.AddFonction(FONElement);
		}
	}
}

void MatriceFonction::init(ListFonction fonctions, unsigned int nbLignes, unsigned int nbColonnes)
{
	LISFonctions = fonctions;
	uiNbLignes = nbLignes;
	uiNbColonnes = nbColonnes;
}

void MatriceFonction::init(DenavitParameter& param, unsigned int num)
{
	LISFonctions.init(16);
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


	Theta = Param(param, 0, th);	// theta
	D = Param(param, 1, dd);		// d
	Alpha = Param(param, 2, al);	// alpha
	A = Param(param, 3, aa);		// a
	Zero = new FonctionConstante(0);	// 0
	Un = new FonctionConstante(1);		// 1

	free(th);
	free(dd);
	free(al);
	free(aa);

	// CREATION DES ELEMENTS DE LA MATRICE ELEMENTAIRE //

	// cos(theta)
	FONCos = new FonctionCos(Theta.Copy());
	LISFonctions.AddFonction(FONCos);
	//////

	// -1 * sin(theta) * cos(alpha)
	LISElements.init(3);

	FONElement = new FonctionConstante(-1);
	LISElements.AddFonction(FONElement); // -1

	FONSin = new FonctionSin(Theta.Copy());
	LISElements.AddFonction(FONSin); // sin(theta)

	FONCos = new FonctionCos(Alpha.Copy());
	LISElements.AddFonction(FONCos); // cos(alpha)

	FONElement = new FonctionProduit(LISElements); // -1*sin(theta)*cos(alpha)
	LISFonctions.AddFonction(FONElement);
	//////


	// sin(theta) * sin(alpha)
	LISElements.init(2);

	FONSin = new FonctionSin(Theta.Copy());
	LISElements.AddFonction(FONSin); // sin(theta)

	FONSin = new FonctionSin(Alpha.Copy());
	LISElements.AddFonction(FONSin); // sin(alpha)

	FONElement = new FonctionProduit(LISElements); // sin(theta)*sin(alpha)
	LISFonctions.AddFonction(FONElement);
	//////

	// a * cos(theta)
	LISElements.init(2);

	LISElements.AddFonction(A, false);

	FONCos = new FonctionCos(Theta.Copy());
	LISElements.AddFonction(FONCos); // cos(theta)

	FONElement = new FonctionProduit(LISElements); // a * cos(theta)
	LISFonctions.AddFonction(FONElement);
	//////

	// sin(theta)
	FONSin = new FonctionSin(Theta.Copy());
	LISFonctions.AddFonction(FONSin); // sin(theta)
	//////

	// cos(theta) * cos(alpha)
	LISElements.init(2);

	FONCos = new FonctionCos(Theta.Copy());
	LISElements.AddFonction(FONCos); // cos(theta)

	FONCos = new FonctionCos(Alpha.Copy());
	LISElements.AddFonction(FONCos); // cos(alpha)

	FONElement = new FonctionProduit(LISElements); // cos(theta) * cos(alpha)
	LISFonctions.AddFonction(FONElement);
	//////

	// -1 * cos(theta) * sin(alpha)
	LISElements.init(3);

	FONElement = new FonctionConstante(-1);
	LISElements.AddFonction(FONElement); // -1

	FONCos = new FonctionCos(Theta.Copy());
	LISElements.AddFonction(FONCos); // cos(theta)

	FONSin = new FonctionSin(Alpha.Copy());
	LISElements.AddFonction(FONSin); // sin(alpha)

	FONElement = new FonctionProduit(LISElements); // -1*cos(theta)*sin(alpha)
	LISFonctions.AddFonction(FONElement);
	//////

	// a * sin(theta)
	LISElements.init(2);

	LISElements.AddFonction(A, false);

	FONSin = new FonctionSin(Theta.Copy());
	LISElements.AddFonction(FONSin); // sin(theta)

	FONElement = new FonctionProduit(LISElements); // a * sin(theta)
	LISFonctions.AddFonction(FONElement);
	//////

	// 0
	LISFonctions.AddFonction(Zero);
	//////

	// sin(alpha)
	FONSin = new FonctionSin(Alpha.Copy());
	LISFonctions.AddFonction(FONSin); // sin(alpha)
	//////

	// cos(alpha)
	FONCos = new FonctionCos(Alpha.Copy());
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

void MatriceFonction::init(MatriceFonction MATCopie)
{
	LISFonctions = MATCopie.LISFonctions;
	uiNbLignes = MATCopie.uiNbLignes;
	uiNbColonnes = MATCopie.uiNbColonnes;
}



CMatrice MatriceFonction::Result()
{
	double* elements;
	double zero = 0;
	
	if (uiNbColonnes == 0 || uiNbLignes == 0) { return CMatrice(1, 1, &zero); }

	// Cr�ation d'un tableau contenant le r�sultat de chaque formule math�matique
	elements = (double*)malloc(sizeof(double)*uiNbLignes*uiNbColonnes);
	for (unsigned int i = 0; i < uiNbColonnes*uiNbLignes; i++)
	{
		elements[i] = LISFonctions[i].Result();
	}

	// Cr�ation d'une matrice de r�els contenant le r�sultat
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

	LISSommes.init(nbLignes*nbColonnes);  // Liste des �l�ments de la matrice r�sultat
	for (i = 0; i < nbLignes; i++)
	{
		for (j = 0; j < nbColonnes; j++)
		{
			LISProduits.init(uiNbColonnes);  // Liste des produits � mettre en somme
			for (k = 0; k < uiNbColonnes; k++)
			{
				// a(i, k) * b(k, j)  o� a(i, k) et b(k, j) sont des copies
				LISElements.init(2);
				LISElements.AddFonction(LISFonctions[i*uiNbColonnes + k], false);  
				LISElements.AddFonction(MATMatrice.LISFonctions[k*MATMatrice.uiNbColonnes + j], false);

				// Ajout du produit dans la liste
				FONElement = new FonctionProduit(LISElements);
				LISProduits.AddFonction(FONElement);
			}

			// Ajout de la somme (k allant de 1 � nbColonnes) des produits ( a(i, k)*b(k, j) ) dans la liste
			FONElement = new FonctionSomme(LISProduits);
			LISSommes.AddFonction(FONElement);
		}
	}

	// Cr�ation d'une matrice de fonctions contenant la liste d'�l�ments
	MatriceFonction resultat(LISSommes, nbLignes, nbColonnes);
	return resultat;
}

ListFonction MatriceFonction::getElements()
{
	unsigned int uiTaille = LISFonctions.GetNbFonctions();
	ListFonction LISCopie(uiTaille);

	// Allocation d'une copie des �l�ments de la matrice
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

	// Cr�ation d'une liste dont les �l�ments pointent ceux de la ligne d'indice donn�
	LISLigne.init(uiNbColonnes);
	for (unsigned int i = 0; i < uiNbColonnes; i++)
	{
		// FONElement pointe l'�l�ment � ajouter car il n'est pas temporaire
		FONElement = LISFonctions[uiIndice*uiNbColonnes + i];

		// La d�l�gation ne r�cup�re pas l'�l�ment car FONElement ne le poss�de pas
		// L'�l�ment de LISLigne pointe donc l'�l�ment point� par FONElement
		LISLigne.AddFonction(FONElement);  
	}

	return LISLigne;
}


void MatriceFonction::Show()
{
	// Si aucune ligne ou colonne, afficher une matrice vide
	if (uiNbColonnes == 0 || uiNbLignes == 0) 
	{
		cout << "(0)" << endl; 
		return;
	}

	// Pour chaque ligne
	for (unsigned int i = 0; i < uiNbLignes; i++)
	{
		cout << "| ";

		// Pour chaque colonne except�e la derni�re, afficher la formule suivi d'une virgule
		for (unsigned int j = 0; j < uiNbColonnes-1; j++)
		{
			LISFonctions[i*uiNbColonnes + j].Show(); cout << ", ";
		}
		// Afficher la formule de la derni�re colonne
		LISFonctions[i*uiNbColonnes + uiNbColonnes - 1].Show(); cout << " |" << endl;
	}

}


FonctionInterface MatriceFonction::Param(DenavitParameter& param, unsigned int uiIndice, const char* nom)
{
	FonctionInterface FONInterface;
	
	// Si la variable articulaire indiqu�e n'est pas variable
	if (param.LireBVariable(uiIndice) == false)
	{
		// Allocation d'une fonction constante contenant la valeur de la variable
		FONInterface = new FonctionConstante(param.LireValeur(uiIndice));
	}
	else
	{
		// Allocation d'une fonction variable reli�e � la variable articulaire et affectation du nom donn�
		FONInterface = new FonctionVariable(param.LireVariable(uiIndice), nom);
	}

	return FONInterface;
}
