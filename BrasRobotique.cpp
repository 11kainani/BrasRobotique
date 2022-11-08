// BrasRobotique.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "CMatriceBase.h"
#include "CMatrice.h"
using namespace std;

int main()
{
   float black[4] = {4, 2, 4, 2};
   
    std::cout << "Hello World!\n";
    CMatrice wei(2,2,black);
  //  wei.MATAffiche();

    CMatrice ouu;
    ouu = wei ;



    wei* ouu - wei * wei * (double)2 ;
   // ouu.MATAffiche();
      
    CMatrice full = wei;
   // full.MATTranspose();

    //full.MATAffiche();

    (full * wei * ouu).MATAffiche();

    CMatrice  mult =  wei + full;

    //mult.MATAffiche();

   CMatrice testt = wei * wei - full * mult;


    


    full.MATAffiche(); 
    
    
    float tab[3] = { 1,2,3 };

    CMatrice mat(1, 3, tab);

    //mat.MATAffiche();

    CMatrice tess(3,1,tab);

    //tess.MATAffiche();

    float test[9] = { 1,0,0,0,2,0,0,0,4 };

    CMatrice Mare(3, 3, test);


   //Mare.Greville(); 

    //CMatrice jupiteur = CMatrice::MATIdentity(5, 2);

    //jupiteur.MATAffiche();

    //Mare = jupiteur.MATTranspose(); 

    //jupiteur.MATAffiche();
    //
    
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
