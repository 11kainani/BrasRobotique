#include "FonctionMath.h"



FonctionMath::FonctionMath()
{
}

FonctionMath::FonctionMath(FonctionInterface& fonction)
{
	FONInterface.init(fonction);
}

FonctionMath::FonctionMath(FonctionMath& FONMath)
{
	FONInterface = FONMath.FONInterface;
}

FonctionMath::~FonctionMath()
{
	// Destruction de FONInterface
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
