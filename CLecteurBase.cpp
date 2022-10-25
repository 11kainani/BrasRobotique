#include <iostream>
#include <assert.h>
#include <fstream>

#include "CLecteurBase.h"


CLecteurBase::CLecteurBase()
{
}

bool CLecteurBase::IsInt(char* pcInput)
{
	return false;
}

bool CLecteurBase::IsDouble(char* pcInput)
{
	return false;
}

bool CLecteurBase::ToInt(char* pcInput, int& iVar)
{
	return false;
}

bool CLecteurBase::ToDouble(char* pcInput, double& dVar)
{
	return 0;
}

bool CLecteurBase::FindWordInFileLine(ifstream& fichier, const char* pcMot, char** ppcLigne)
{
	return false;
}

bool CLecteurBase::FindWordInSameFileLine(const char* pcMot, char* pcLigne)
{
	return false;
}

bool CLecteurBase::FindWordInSameFileWithSeparator(const char* pcMot, char* pcLigne, const char separator)
{
	return false;
}

char CLecteurBase::ToLower()
{
	return 0;
}

char* CLecteurBase::FindIntInLine(char* pcLigne)
{
	return 0;
}

char* CLecteurBase::FindIntInLineWithSeparator(char* pcLigne, const char separator)
{
	return 0;
}

char* CLecteurBase::FindIntInLineAfterSeparator(char* pcLigne, const char separator)
{
	return 0;
}

char** CLecteurBase::FindValuesInLine(char* pcLigne, const char separator)
{
	return 0;
}

void CLecteurBase::InputIntPositif(const char* pcMessage, int& iVariable)
{
}
