#include "FonctionMath.h"



FonctionMath::FonctionMath()
{
}

FonctionMath::FonctionMath(FonctionInterface& fonction)
{
	FONInterface = (FonctionInterface&)FonctionInterface(fonction);
}

FonctionMath::FonctionMath(FonctionMath& FONMath)
{
	FONInterface = FONMath.FONInterface;
}

FonctionMath::~FonctionMath()
{
	// Appel de ~Fonction()
}

FonctionMath& FonctionMath::operator=(FonctionMath& FONMath)
{
	FONInterface = FONMath.FONInterface;

	return *this;
}

bool FonctionMath::Constant()
{
	return FONInterface.Constant();
}
