// BrasRobotique.cpp : Ce fichier contient la fonction 'main'. L'exÃ©cution du programme commence et se termine Ã  cet endroit.
//

#include "MatriceFonction.h"
#include "CLecteur.h"
#include "CEcriture.h"
#include "CTrajectoire.h"
#include <iostream>
using namespace std;


// Conversion d'une matrice 4 x 4 en matrice 12 x 1
void ConvertToTask(CMatrice& matrice)
{
	double* tab = (double*)malloc(sizeof(double) * 12);

	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			tab[j*3 + i] = matrice.MATLireElement(i, j);
		}
	}

	CMatrice resultat(12, 1, tab);
	std::free(tab);
	matrice = resultat;
}


int main()
{
	std::cout << "Hello World!\n\n";

	// Entrées et Sorties
	CEcriture log("result.txt");
	CLecteur lec("test.txt");
	CTrajectoire trajectoire("trajectoire.txt");

	// Matrices et formules mathématiques
	CMatrice J, G, Z, I, DeltaX, DTheta, Ecart, Resultat, Point;
	MatriceFonction X, M, JTheta, ZTheta;
	ListFonction LISElements, LISProduits;
	FonctionInterface FONElement;

	// Données, intervalles, itérateurs et tableau de résultats
	unsigned int nbParameter, nbElements, nbVariables, nbPoints;
	double min, max;
	unsigned int i, j, k, d;
	double* Tab;

	// Lecture du fichier d'architecture
	try
	{
		lec.LireFichier();
	}
	catch (CException exc)
	{
		std::cout << "Echec de lecture fichier Erreur : " << exc.EXCLireValeur() << endl;
		return 1;
	}

	// Lecture du fichier de trajectoire
	try
	{
		trajectoire.LireFichier();
	}
	catch (CException exc)
	{
		exc.EXCLireValeur();
		return 1;
	}

	// Enregistrement des parametres des fichiers
	nbParameter = lec.LireNbParametres();
	nbElements = lec.LireNbElements();
	nbVariables = lec.LireNbVariables();
	nbPoints = trajectoire.LireNbLu();

	if (nbParameter * 4 != nbElements) 
	{
		std::cout << "Erreur NbParameter et nbElements" << endl;
		return 1;
	}




	cout << "Generation de la matrice X" << endl;
	// Matrice 4x4 Identité
	X .init(4, 4);

	// Calcul de X par multiplication de chaque matrice elementaire de Denavit
	for (i = 0; i < nbParameter; i++)
	{
		// Multiplication des matrices elementaires selon le modele geometrique direct (M1(M2(M3(...(Mn-1(Mn*I))))))
		M.init(lec.LireParametre(nbParameter - 1 - i), nbParameter - i);
		X.init((MatriceFonction&)(M * X));
	}

	// Affichage de la matrice de l'organe terminal
	cout << "X" << endl;
	X.Show();
	X.Result().MATAffiche();
	cout << endl;




	cout << "Generation de la matrice J(theta)" << endl;
	// Initialisation de la matrice J(theta) 12 x NbVariables
	LISElements.init(12 * nbVariables);

	// Pour chaque vecteur de X (n, o, a, p)
	for (j = 0; j < 4; j++)
	{
		// Pour chaque composante de ce vecteur
		for (i = 0; i < 3; i++)
		{
			for (k = 0; k < nbVariables; k++)
			{
				// Calcul de la dérivée partielle à partir des variables articulaires
				FONElement = (FonctionInterface&)X[i][j].Derive(lec.LireVariable(k).LireVariable());
				LISElements.AddFonction(FONElement);
				cout << "|";
			}
		}
	}

	// Creation et Affichage de la matrice J(theta)
	cout << endl;
	JTheta.init(LISElements, 12, nbVariables);
	cout << "J(theta)" << endl;
	JTheta.Show();
	cout << endl;


	
	cout << "Generation de la matrice Z" << endl;
	// Initialisation de la matrice Z(theta)  NbVariables x 1
	LISElements.init(nbVariables);

	// Pour chaque variable articulaire
	for (i = 0; i < nbVariables; i++)
	{
		VariableArticulaire* var = &lec.LireVariable(i);

		// Valeur minimale et maximale possible pour la variable
		min = var->LireMin();
		max = var->LireMax();
		
		// variable - ((max - min) / 2)
		LISProduits.init(2);

		FONElement = new FonctionVariable(var->LireVariable());
		LISProduits.AddFonction(FONElement);

		FONElement = new FonctionConstante(-0.5 * (max-min));
		LISProduits.AddFonction(FONElement);

		FONElement = new FonctionSomme(LISProduits);  // variable + (-0.5 * (max - min))

		// ( 2/3 ) * [ ( variable - ((max - min) / 2) ) / (max - min) ]
		LISProduits.init(2);
		LISProduits.AddFonction(FONElement);

		/// FONElement = &FonctionConstante((nbVariables-1) / (nbVariables * (max - min)));
		FONElement = new FonctionConstante(2 / (3 * (max - min)));
		LISProduits.AddFonction(FONElement);

		FONElement = new FonctionProduit(LISProduits);  // (variable + (-0.5 * (max - min))) * (2 / (3 * (max - min)))

		LISElements.AddFonction(FONElement);
	}

	// Creation et Affichage de la matrice Z(theta)
	ZTheta.init(LISElements, nbVariables, 1);
	cout << "Z" << endl;
	ZTheta.Show();
	cout << endl;
	

	// Initialisation du vecteur Tache DeltaX, la matrice d'Ecart et la matrice Identité I;
	DeltaX = CMatrice::MATIdentity(4, 4);
	Ecart = CMatrice::MATIdentity(3, 4);
	I = CMatrice::MATIdentity(nbVariables, nbVariables);

	// Allocation du tableau de résultats
	Tab = (double*)malloc(sizeof(double)*nbVariables);


	// Calcul Trajectoire
	cout << endl << "-- Calcul de Trajectoire --" << endl;

	for (k = 0; k < nbPoints; k++)
	{
		// Affichage du Point k de la trajectoire
		Point = trajectoire.TRALireMatrice(k);
		cout << "Point " << k + 1 << endl;
		Point.MATAffiche();

		// Calcul de J, G et Z
		J = JTheta.Result();
		G = J.Greville();
		Z = ZTheta.Result();

		/// Affichage optionnel
		cout << "Z" << endl;
		Z.MATTranspose().MATAffiche();
		///

		// Calcul du vecteur DeltaX entre le point précédent et le point k
		DeltaX = Point - DeltaX;
		ConvertToTask(DeltaX); // Conversion en vecteur 12 x 1

		// Calcul de DTheta
		DTheta = G * DeltaX + (G * J - I) * Z;

		/// Affichage optionnel
		cout << "G * J" << endl;
		(G*J).MATAffiche();
		///

		// Affichage du resultat du calcul
		cout << "DTheta" << endl;
		DTheta.MATTranspose().MATAffiche();

		// Modification des variables articulaires par DTheta
		for (i = 0; i < nbVariables; i++)
		{
			Tab[i] = DTheta.MATLireElement(i, 0);

			// Si la variable articulaire affecte la rotation du bras robotique
			if (lec.LireVariable(i).LireBAngulaire())
			{
				// La valeur est limitée à l'intervalle du sinus
				if (Tab[i] < -1) { Tab[i] = -1; }
				if (Tab[i] > 1) { Tab[i] = 1; }

				// Calcul de l'angle en radian 
				Tab[i] = asin(Tab[i]);
			}

			// Modification de la variable articulaire
			lec.LireVariable(i).ModifierValeur(lec.LireVariable(i).LireValeur() + Tab[i]);
		}

		// On enregistre le nouveau point précédent
		Resultat = X.Result();
		DeltaX = Resultat;

		// Affichage de la nouvelle position-orientation
		std::cout << "Position " << k + 1 << endl;
		Resultat.MATAffiche();
		cout << endl;

		// Calcul de l'écart par rapport au point k
		for (i = 0; i < 12; i++)
		{
			unsigned int ligne = i % 3;
			unsigned int colonne = i/3;
			Ecart.MATModiferElement(ligne, colonne, Resultat.MATLireElement(ligne, colonne) - Point.MATLireElement(ligne, colonne));
		}

		// Affichage de l'écart par rapport à la trajectoire
		cout << "Ecart" << endl;
		Ecart.MATAffiche();
		std::cout << endl << endl;


		// Enregistrement des parametres denavit
		log.Ecrire("Parametre(s) Denavit :\n");

		d = 0;  // decalage
		// Pour chaque paramètre
		for (i = 0; i < nbParameter; i++)
		{
			// Pour chaque variable articulaire non-constante
			/*for (j = 0; j < lec.LireParametre(i).nbVari(); j++)
			{

				log.EcrireParametre(lec.LireParametre(i), Tab[i + j + d], j);

				// incremente le decalage en cas de plusieurs variables articulaires dans le paramètre
				if (j > 0)
				{
					d++;
				}
			}*/

			log.EcrireParametre(lec.LireParametre(i));
		}
		log.Ecrire("-------------\n");
	}


	std::free(Tab);
	return 0;
}



// ExÃ©cuter le programmeÂ : Ctrl+F5 ou menu DÃ©boguerÂ > ExÃ©cuter sans dÃ©bogage
// DÃ©boguer le programmeÂ : F5 ou menu DÃ©boguerÂ > DÃ©marrer le dÃ©bogage

// Conseils pour bien dÃ©marrerÂ : 
//   1. Utilisez la fenÃªtre Explorateur de solutions pour ajouter des fichiers et les gÃ©rer.
//   2. Utilisez la fenÃªtre Team Explorer pour vous connecter au contrÃ´le de code source.
//   3. Utilisez la fenÃªtre Sortie pour voir la sortie de la gÃ©nÃ©ration et d'autres messages.
//   4. Utilisez la fenÃªtre Liste d'erreurs pour voir les erreurs.
//   5. AccÃ©dez Ã  ProjetÂ > Ajouter un nouvel Ã©lÃ©ment pour crÃ©er des fichiers de code, ou Ã  ProjetÂ > Ajouter un Ã©lÃ©ment existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accÃ©dez Ã  FichierÂ > OuvrirÂ > Projet et sÃ©lectionnez le fichier .sln.