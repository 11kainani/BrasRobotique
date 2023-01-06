#ifndef FONCTION_H
#define FONCTION_H

#include <iostream>
using namespace std;

class Fonction
{
public:

	// Retourne le résultat du calcul de la fonction
	virtual double Result()=0;

	// Retourne la dérivée de la fonction
	// ATTENTION : Retourne un pointeur Fonction alloué dynamiquement par new
	// Vous devez obligatoirement utiliser l'instruction delete sur l'élément retourné
	// Note : Stockez l'élément dans une variable Fonction* non allouée
	virtual Fonction* Derive(double* pdComposant) = 0;

	// Retourne une copie de la fonction
	// ATTENTION : Retourne un pointeur Fonction alloué dynamiquement par new
	// Vous devez obligatoirement utiliser l'instruction delete sur l'élément retourné
	// Note : Stockez l'élément dans une variable Fonction* non allouée
	virtual Fonction* Copy() = 0;

	// Affiche la formule de la fonction
	virtual void Show() = 0;

	// La formule vaut-elle constamment 0 ?
	virtual bool Zero() = 0;

	// La formule vaut-elle constamment 1 ?
	virtual bool Un() = 0;

	// La formule est-elle une constante ?
	virtual bool Constant() = 0;

	~Fonction();
};
#endif 

