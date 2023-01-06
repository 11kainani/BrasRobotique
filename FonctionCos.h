#pragma once

#include "FonctionMath.h"
#include "FonctionSin.h"

class FonctionCos : public FonctionMath
{

public:
	FonctionCos();
	FonctionCos(FonctionInterface& FONInterface);
	~FonctionCos();

	double Result();
	Fonction* Derive(double* pdComposant);
	Fonction* Copy();
	void Show();
	bool Zero();
	bool Un();
};


