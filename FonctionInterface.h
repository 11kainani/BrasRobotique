#ifndef FONCTION_INTERFACE_H
#define FONCTION_INTERFACE_H

#include "FonctionConstante.h"

class FonctionInterface
{
	Fonction* pnFONFonction; // pointeur polymorphique d'une fonction
	bool bDynamique;  // Le pointeur est-il alloué par new ?
	bool bTemporaire; // L'objet est-il temporaire ?

public:
	FonctionInterface();
	FonctionInterface(Fonction* fonction, bool bTemp=true);
	FonctionInterface(FonctionInterface& FONInterface);
	~FonctionInterface();

	FonctionInterface& operator=(FonctionInterface& FONInterface);
	FonctionInterface& operator=(Fonction* fonction);

	double Result();
	FonctionInterface Derive(double* pdComposant);
	FonctionInterface Copy();
	void Show();
	bool Zero();
	bool Un();
	bool Constant();

private:
	void Alloc(Fonction* pFonction, bool dynamique);
	void Desalloc();
};
#endif;

