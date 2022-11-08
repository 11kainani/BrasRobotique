#include <iostream>
#include <fstream>

#include "DenavitParameter.h"


DenavitParameter::DenavitParameter()
{
	variableArticulaire = nullptr;
}

DenavitParameter::DenavitParameter(VariableArticulaire** VARListe)
{
	variableArticulaire = (VariableArticulaire**)malloc(sizeof(VariableArticulaire*) * 4);
	for (int i = 0; i < 4; i++)
	{
		variableArticulaire[i] = VARListe[i];
	}
}

DenavitParameter::DenavitParameter(DenavitParameter& DENObject)
{
}

DenavitParameter::~DenavitParameter()
{
}

void DenavitParameter::AddParameter(int iIndice, VariableArticulaire VARvariable)
{
}

void DenavitParameter::DeleteParameter(int iIndice)
{
}

void DenavitParameter::Swap(int iFrom, int iDestination)
{
}
