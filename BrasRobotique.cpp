// BrasRobotique.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "DenavitParameter.h"
#include "CLecteurBase.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Hello World!\n\n";

	
	CLecteurBase lec((char*)"test.txt");
	DenavitParameter dp;
	bool res = false;
	double var;
	char* texte = nullptr;

	cout << "read" << endl;
	do
	{
		texte = lec.FindDoubleInLine(',');
		if (texte != nullptr)
		{
			lec.ToDouble(texte, var);
			cout << var << " ";
			res = true;
			free(texte);
		}
		else
		{
			
			if (lec.EmptyLine())
			{
				lec.RewindTo(',', 1, true);
				if (lec.FindWordInFileLine("h", ','))
				{
					cout << "h ";
				}

				cout << endl;
				res = lec.NextLine();
			}
			else
			{
				lec.RewindTo(',', 2, true);
				if (lec.FindWordInFileLine("h", ','))
				{
					cout << "h ";
				}
				else { cout << "Nan "; }
				res = true;
			}
		}
	}while (res == 1);


	/*
	VariableArticulaire v1(10, 5, 10, 1);
	VariableArticulaire v2(9, 0, 12, 1);
	VariableArticulaire v3(8, 0, 12, 1);
	VariableArticulaire v4(10, 0, 12, 1);

	DenavitParameter dp;
	dp.SetVariable(0, &v1);
	dp.SetVariable(1, &v2);
	dp.SetVariable(2, &v3);
	dp.Affiche();
	dp.DeleteVariable(2);
	for (int i = 0; i < 10; i++)
	{
		v1.ModifierValeur(10-i);
		dp.Affiche();

	}
	*/

	return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
