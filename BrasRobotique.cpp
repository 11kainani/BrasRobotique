// BrasRobotique.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include "CMatriceBase.h"
#include "CMatrice.h"
#include "VariableArticulaire.h"
#include "DenavitParameter.h"
#include "CEcriture.h"

using namespace std;

int main()
{
   float black[4] = {4, 2, 4, 2};
   float noir[6] = {1, 4, 2,3,1,7};
   
   CMatrice wei(2,2,black);
 
   

   float test[9] = { 1,2,3,4,5,6,7,8,4 };
   CMatrice Mare(3, 3, test);
   CMatrice essai(2,3, noir);

   VariableArticulaire *theta = new VariableArticulaire(5, 8, 2, true);
   VariableArticulaire *d = new VariableArticulaire(12, 12, 12, false);
   VariableArticulaire *alpha = new VariableArticulaire(1, 5, 1, true);
   VariableArticulaire *a = new VariableArticulaire(10, 20, 0, true);
   
   VariableArticulaire** parameter = (VariableArticulaire**)malloc(sizeof(VariableArticulaire*) * 4);
   
   DenavitParameter Denavit(parameter);
    
   Denavit.SetVariable(0, theta);
   Denavit.SetVariable(1, d);
   Denavit.SetVariable(2,alpha);
   Denavit.SetVariable(3,a);
   

   Denavit.Affiche();

   cout << "\n";

   
   CMatrice deny = CMatrice::MATDenavit(Denavit);

   deny.MATAffiche();


  DenavitParameter** listes = new DenavitParameter*[3]();
  listes[0] = &Denavit;
  listes[1] = &Denavit;
  listes[2] = &Denavit;


  CEcriture test10((char*)"text.txt", listes, 3);
  test10.ECREcrireNouveauFichier();



   /*Desallocation*/

   delete theta;
   delete d;
   delete alpha; 
   delete a;
   free(parameter);

 //  delete[] listes;

}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
