#include "FonctionSin.h"



FonctionSin::FonctionSin()
{
}

FonctionSin::FonctionSin(FonctionInterface& FONInterface) : FonctionMath(FONInterface)
{
}


FonctionSin::~FonctionSin()
{
	// Appel de ~FonctionMath()
}

double FonctionSin::Result()
{
	return sin(FONInterface.Result());
}

Fonction* FonctionSin::Derive(double* pdComposant)
{
	Fonction* pFONDerive;
	unsigned int uiTaille = 2;
	ListFonction LISDerives(uiTaille);
	FonctionInterface FONElement;

	// cos(u)
	FONElement = new FonctionCos(FONInterface);
	LISDerives.AddFonction(FONElement);

	// u'
	FONElement = (FonctionInterface&)FONInterface.Derive(pdComposant);
	LISDerives.AddFonction(FONElement);

	// ( sin(u) )' = cos(u)*u'
	pFONDerive = new FonctionProduit(LISDerives);

	return pFONDerive;

}

Fonction* FonctionSin::Copy()
{
	return new FonctionSin(FONInterface);
}

void FonctionSin::Show()
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

	cout << "sin(";
	FONInterface.Show();
	cout << ")";
}

bool FonctionSin::Zero()
{
	return FONInterface.Zero();
}

bool FonctionSin::Un()
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