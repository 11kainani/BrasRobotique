#ifndef FONCTION_SINCOS_H
#define FONCTION_SINCOS_H

#include "FonctionMath.h"
#include "FonctionCos.h"

class FonctionSin : public FonctionMath
{
public:
	FonctionSin();
	FonctionSin(FonctionInterface& FONInterface);
	~FonctionSin();

	double Result();
	Fonction* Derive(double* pdComposant);
	Fonction* Copy();
	void Show();
	bool Zero();
	bool Un();
};
#endif


