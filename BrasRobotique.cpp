// BrasRobotique.cpp : Ce fichier contient la fonction 'main'. L'exÃ©cution du programme commence et se termine Ã  cet endroit.
//

#include "MatriceFonction.h"
#include "CLecteur.h"
#include "CEcriture.h"
#include "CTrajectoire.h"
#include <iostream>
using namespace std;


//// matrice 4 x 4
//void SetPosition(CMatrice& matrice, double x, double y, double z)
//{
//	matrice.MATModiferElement(0, 3, x);
//	matrice.MATModiferElement(1, 3, y);
//	matrice.MATModiferElement(2, 3, z);
//}

// matrice 4 x 4 >>> matrice 12 x 1
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

//CMatrice RotateWithAandN(double theta, double alpha)
//{
//	double * pfMATElementaire = (double*)malloc(sizeof(double) * 16);
//
//	theta *= PI / 180;
//	alpha *= PI / 180;
//
//	pfMATElementaire[0] = cos(theta);
//	pfMATElementaire[1] = -sin(theta) * cos(alpha);
//	pfMATElementaire[2] = sin(theta) * sin(alpha);
//	pfMATElementaire[3] = 0;
//	pfMATElementaire[4] = sin(theta);
//	pfMATElementaire[5] = cos(theta) * cos(alpha);
//	pfMATElementaire[6] = -cos(theta) * sin(alpha);
//	pfMATElementaire[7] = 0;
//	pfMATElementaire[8] = 0;
//	pfMATElementaire[9] = sin(alpha);
//	pfMATElementaire[10] = cos(alpha);
//	pfMATElementaire[11] = 0;
//	pfMATElementaire[12] = 0;
//	pfMATElementaire[13] = 0;
//	pfMATElementaire[14] = 0;
//	pfMATElementaire[15] = 1;
//
//	CMatrice result(4, 4, pfMATElementaire);
//	std::free(pfMATElementaire);
//
//	return result;
//}

//// Crée une trajectoire test
//CMatrice* Trajectoire()
//{
//	int nb = 3;
//	CMatrice* points = new CMatrice[nb];
//
//	// init
//	for (int i = 0; i < nb; i++)
//	{
//		points[i] = RotateWithAandN(0, 0);
//	}
//
//	points[0] = points[0] * (RotateWithAandN(5, 0));
//	SetPosition(points[1], 5, 0, 0);
//	points[2] = points[2] * (RotateWithAandN(0, 5));
//
//	// Mise en vecteur 12*1
//	for (int i = 0; i < nb; i++)
//	{
//		std::cout << "Point " << i + 1 << endl;
//		points[i].MATAffiche();
//		ConvertToTask(points[i]);
//	}
//
//	return points;
//}

int main()
{
	std::cout << "Hello World!\n\n";

	CEcriture log("result.txt");
	CLecteur lec("test.txt");
	CTrajectoire trajectoire("trajectoire.txt");

	CMatrice J, DeltaX, DTheta, Ecart, Resultat, Point;
	MatriceFonction X, JTheta;
	ListFonction LISElements;
	FonctionInterface FONElement;
	unsigned int nbParameter, nbElements, nbVariables, nbPoints;
	unsigned int i, j, k;
	double* Tab;

	
	try
	{
		lec.LireFichier();
	}
	catch (CException exc)
	{
		std::cout << "Echec de lecture fichier Erreur : " << exc.EXCLireValeur() << endl;
		return 1;
	}

	try
	{
		trajectoire.LireFichier();
	}
	catch (CException exc)
	{
		exc.EXCLireValeur();
		return 1;
	}

	nbParameter = lec.LireNbParametres();
	nbElements = lec.LireNbElements();
	nbVariables = lec.LireNbVariables();
	nbPoints = trajectoire.LireNbLu();

	if (nbParameter * 4 != nbElements) 
	{
		std::cout << "Erreur NbParameter et nbElements" << endl;
		//* exit(1);
		return 1;
	}


	// Matrice 4x4 Identité
	X = (MatriceFonction&)MatriceFonction(4, 4);

	// Calcul de X par multiplication de chaque matrice elementaire de Denavit
	for (i = 0; i < nbParameter; i++)
	{
		X = (MatriceFonction&)(MatriceFonction(lec.LireParametre(nbParameter-1-i), nbParameter - i) * X);
	}

	X.Show();
	X.Result().MATAffiche();

	// Initialisation de la matrice J(theta)
	LISElements = (ListFonction&)ListFonction(12 * nbVariables);
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < 3; i++)
		{
			for (k = 0; k < nbVariables; k++)
			{
				FONElement = (FonctionInterface&)X[i][j].Derive(lec.LireVariable(k).LireVariable());
				LISElements.AddFonction(FONElement);
			}
		}
	}
	JTheta = (MatriceFonction&)MatriceFonction(LISElements, 12, nbVariables);
	JTheta.Show();

	// Initialisation du vecteur Tache DeltaX
	DeltaX = CMatrice::MATIdentity(4, 4);

	// Nouvelles valeurs articulaires
	Tab = (double*)malloc(sizeof(double)*nbVariables);

	for (k = 0; k < nbPoints; k++)
	{
		// Point k de la trajectoire
		Point = trajectoire.TRALireMatrice(k);
		cout << "Point " << k + 1 << endl;
		Point.MATAffiche();

		// Calcul de J
		J = JTheta.Result();

		// Calcul du vecteur DeltaX entre le point précédent et le point k
		DeltaX = Point - DeltaX;
		ConvertToTask(DeltaX);
		DeltaX.MATTranspose().MATAffiche();
		//J.MATAffiche();
		//J.Greville().MATAffiche();
		DeltaX.MATAffiche();

		// Calcul de DTheta
		DTheta = J.Greville() * DeltaX;
		DTheta.MATTranspose().MATAffiche();

		// Modification des variables articulaires
		for (i = 0; i < nbVariables; i++)
		{
			Tab[i] = DTheta.MATLireElement(i, 0);

			if (lec.LireVariable(i).LireBAngulaire())
			{
				if (Tab[i] < -1) { Tab[i] = -1; }
				if (Tab[i] > 1) { Tab[i] = 1; }
				Tab[i] = asin(Tab[i]);
			}
			lec.LireVariable(i).ModifierValeur(lec.LireVariable(i).LireValeur() + Tab[i]);
		}

		// On enregistre le nouveau point précédent
		Resultat = X.Result();
		DeltaX = Resultat;

		// Affichage de la nouvelle position-orientation
		std::cout << "Position " << k + 1 << endl;
		Resultat.MATAffiche();

		// Calcul de l'écart par rapport au point k
		Ecart = Resultat;
		for (i = 0; i < 12; i++)
		{
			unsigned int ligne = i % 3;
			unsigned int colonne = i/3;
			Ecart.MATModiferElement(ligne, colonne, Ecart.MATLireElement(ligne, colonne) - Point.MATLireElement(ligne, colonne));
		}

		// Affichage de l'écart par rapport à la trajectoire
		Ecart.MATAffiche();
		std::cout << endl;

		// Enregistrement des parametres denavit
		log.Ecrire("Parametre(s) Denavit :\n");
		for (i = 0; i < nbParameter; i++)
		{
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
