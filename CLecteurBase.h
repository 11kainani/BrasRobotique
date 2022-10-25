#ifndef C_LECTEUR_BASE_H
#define C_LECTEUR_BASE_H

#include <iostream>
#include <assert.h>
#include <fstream>




using std::ifstream;

class CLecteurBase
{
public:
	CLecteurBase();

	bool IsInt(char* pcInput);

	bool IsDouble(char* pcInput);

	bool ToInt(char* pcInput, int& iVar);

	static bool ToDouble(char* pcInput, double& dVar);

	bool FindWordInFileLine(ifstream& fichier, const char* pcMot, char** ppcLigne);

	//bool FindWordInFileLine(ifstream& fichier, const char* pcMot, char** ppcLigne);

	bool FindWordInSameFileLine(const char* pcMot, char* pcLigne);

	bool FindWordInSameFileWithSeparator(const char* pcMot, char* pcLigne, const char separator);

	char ToLower();

	char* FindIntInLine(char* pcLigne);

	char* FindIntInLineWithSeparator(char* pcLigne, const char separator);

	char* FindIntInLineAfterSeparator(char* pcLigne, const char separator);

	char** FindValuesInLine(char* pcLigne, const char separator);

	void InputIntPositif(const char* pcMessage, int& iVariable);

};
#endif
