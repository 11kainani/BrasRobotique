#include <iostream>
#include <fstream>

#include "CException.h"


CException::CException()
{
}

unsigned int CException::EXCLireValeur()
{
	return uiEXCValeur;
}

void CException::EXCModifierValeur(unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
}
