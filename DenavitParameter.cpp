#include <iostream>
#include <assert.h>
#include <fstream>

#include "DenavitParameter.h"


DenavitParameter::DenavitParameter()
{
	int i;
	pVARVariable = (VariableArticulaire**)malloc(sizeof(VariableArticulaire*) * NB_VARIABLES +sizeof(char));
	for ( i = 0; i < NB_VARIABLES; i++)
	{
		pVARVariable[i] = nullptr;
	}

}

DenavitParameter::DenavitParameter(VariableArticulaire** VARListe)
{
	pVARVariable = (VariableArticulaire**)malloc(sizeof(VariableArticulaire*) * NB_VARIABLES);
	for (int i = 0; i < NB_VARIABLES; i++)
	{
		pVARVariable[i] = VARListe[i];
	}
}

DenavitParameter::DenavitParameter(DenavitParameter& DENObject)
{
	pVARVariable = (VariableArticulaire**)malloc(sizeof(VariableArticulaire*) * NB_VARIABLES);
	for (int i = 0; i < NB_VARIABLES; i++)
	{
		pVARVariable[i] = DENObject.pVARVariable[i];
	}

}

DenavitParameter::~DenavitParameter()
{
	if (pVARVariable != nullptr)
	{
		for (int i = 0; i < NB_VARIABLES; i++)
		{
			pVARVariable[i] = nullptr;
		}
		free(pVARVariable);
	}
}

void DenavitParameter::SetVariable(int iIndice, VariableArticulaire* VARvariable)
{
	if (iIndice >= NB_VARIABLES || iIndice < 0)
	{
		// Exception : Indice incorrect
		return;
	}

	if (VARvariable == nullptr)
	{
		// Exception : Aucune variable fournie
		return;
	}

	pVARVariable[iIndice] = VARvariable;

}

void DenavitParameter::DeleteVariable(int iIndice)
{
	if (iIndice >= NB_VARIABLES || iIndice < 0)
	{
		// Exception : Indice incorrect
		return;
	}

	pVARVariable[iIndice] = nullptr;
}



void DenavitParameter::Affiche()
{
	for (int i = 0; i < NB_VARIABLES; i++)
	{

		if (i == 0) { cout << "("; }
		if (pVARVariable[i] != nullptr)
		{
			cout << (*(pVARVariable[i])).LireValeur();
		}
		else
		{
			cout << "NaN";
		}
		if (i < 3) { cout << ", "; }
		else { cout << ")" << endl; }
	}

}

VariableArticulaire* DenavitParameter::DENLireVariable(unsigned int uiIndice)
{
	
	
	return pVARVariable[uiIndice];
}

