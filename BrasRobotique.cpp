// BrasRobotique.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "..\..\..\BrasRobotique-Jesimiel\DenavitParameter.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!\n"; 
	
	/*
	CLecteurBase lec;
	int taille = 20;
	bool res;
	double var;
	char* texte = (char*)malloc(sizeof(char) * taille);
	
	do
	{
		cin >> texte;
		res = lec.FindWordInSameFileLine("h", texte);
		cout << "Resultat : " << res << endl;
		if (res)
		{
			
		}

	}while (res == 1);

	free(texte);
	*/

	VariableArticulaire v1(10, 0, 12, 1);
	VariableArticulaire v2(9, 0, 12, 1);
	VariableArticulaire v3(8, 0, 12, 1);
	VariableArticulaire v4(10, 0, 12, 1);

	VariableArticulaire** pv = (VariableArticulaire**)malloc(sizeof(VariableArticulaire*) * 4);
	pv[0] = &v1;
	pv[1] = &v2;
	pv[2] = &v3;
	pv[3] = &v4;

	DenavitParameter dp(pv);

		
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
