#ifndef FONCTION_MATH_H
#define FONCTION_MATH_H

#include "FonctionProduit.h"
//* #include <math.h>
#include <cmath>

#define PI 3.14159265

class FonctionMath : public Fonction
{
protected:
	FonctionInterface FONInterface;

public:
	FonctionMath();
	FonctionMath(FonctionInterface& FONInterface);
	FonctionMath(FonctionMath& FONCopie);
	~FonctionMath();

	FonctionMath& operator=(FonctionMath& FONMath);
	bool Constant();

};
#endif

