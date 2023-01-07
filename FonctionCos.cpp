#include "FonctionCos.h"



FonctionCos::FonctionCos()
{
}

FonctionCos::FonctionCos(FonctionInterface& FONInterface) : FonctionMath(FONInterface)
{
}

FonctionCos::~FonctionCos()
{
	// Appel de ~FonctionMath()
}

double FonctionCos::Result()
{
	return cos(FONInterface.Result());
}

Fonction* FonctionCos::Derive(double* pdComposant)
{
	Fonction* pFONDerive;
	unsigned int uiTaille = 3;
	ListFonction LISDerives(uiTaille);
	FonctionInterface FONElement;

	// -1
	FonctionConstante fc(-1);
	FONElement = &fc;
	LISDerives.AddFonction(FONElement);

	// sin(u)
	FonctionSin fs(FONInterface);
	FONElement = &fs;
	LISDerives.AddFonction(FONElement);

	// u'
	FONElement = (FonctionInterface&)FONInterface.Derive(pdComposant);
	LISDerives.AddFonction(FONElement);

	// ( cos(u) )' = -1*sin(u)*u'
	pFONDerive = new FonctionProduit(LISDerives);
	return pFONDerive;

}

Fonction* FonctionCos::Copy()
{
	return new FonctionCos(FONInterface);
}

void FonctionCos::Show()
{
	if (Zero())
	{
		cout << "0";
		return;
	}

	if (Un())
	{
		cout << "1";
		return;
	}


	cout << "cos(";
	FONInterface.Show();
	cout << ")";
}

bool FonctionCos::Zero()
{
	double angle = FONInterface.Result();

	while (angle < 0)
	{
		angle += PI;
	}

	while (angle >= PI)
	{
		angle -= PI;
	}

	return (angle == PI / 2 && FONInterface.Constant());
}

bool FonctionCos::Un()
{
	return FONInterface.Zero();
}
