#include <iostream>
#include <fstream>

#include "DenavitParameter.h"


DenavitParameter::DenavitParameter()
{
	pVARVariable = (VariableArticulaire**)malloc(sizeof(VariableArticulaire*) * NB_VARIABLES);
	for (int i = 0; i < NB_VARIABLES; i++)
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

	/*
	if (VARvariable == nullptr)
	{
		// Exception : Aucune variable fournie
		return;
	}*/

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

/*
void DenavitParameter::Swap(int iFrom, int iDestination)
{

}
*/


DenavitParameter& DenavitParameter::operator=(DenavitParameter& parameter)
{
	for (int i = 0; i < NB_VARIABLES; i++)
	{
		SetVariable(i, parameter.pVARVariable[i]);
	}

	return *this;
}

double* DenavitParameter::LireVariable(int iIndice)
{
	if (iIndice >= NB_VARIABLES || iIndice < 0)
	{
		// Exception : Indice incorrect
		return nullptr;
	}

	return pVARVariable[iIndice]->LireVariable();
}

double DenavitParameter::LireValeur(int iIndice)
{
	if (iIndice >= NB_VARIABLES || iIndice < 0)
	{
		// Exception : Indice incorrect
		return 0;
	}

	return pVARVariable[iIndice]->LireValeur();
}

bool DenavitParameter::LireBVariable(int iIndice)
{
	if (iIndice >= NB_VARIABLES || iIndice < 0)
	{
		// Exception : Indice incorrect
		return false;
	}

	return pVARVariable[iIndice]->LireBVariable();
}

void DenavitParameter::Affiche()
{
	for (int i = 0; i < NB_VARIABLES; i++)
	{

		if (i == 0) { cout << "("; }
		if (pVARVariable[i] != nullptr)
		{
			cout << pVARVariable[i]->LireValeur();
		}
		else
		{
			cout << "NaN";
		}
		if (i < 3) { cout << ", "; }
		else { cout << ")" << endl; }
	}

}

void DenavitParameter::UpdateDENVariables()
{
	unsigned int uiBoucle; 
	DENnbVariables = 0;
	for (uiBoucle = 0; uiBoucle < NB_VARIABLES; uiBoucle++)
	{
		if (pVARVariable[uiBoucle]->LireBVariable() == true)
		{
			DENnbVariables++;
		}
	}
}

double DenavitParameter::LireNbVariables()
{
	return DENnbVariables;
}
