#ifndef C_EXCEPTION_H
#define C_EXCEPTION_H

#include <iostream>
#include <fstream>

class CException
{
private:
	unsigned int uiEXCValeur;


public:
	CException();

	unsigned int EXCLireValeur();

	void EXCModifierValeur(unsigned int uiValeur);

};
#endif
