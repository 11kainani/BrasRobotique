#ifndef C_LECTEUR_BASE_H
#define C_LECTEUR_BASE_H

#include <iostream>
#include <fstream>
using namespace std;

class CLecteurBase
{

	char* pcFichier;
	char* pcLigne; // Ligne en cours de lecture
	ifstream ifStream;

public:
	CLecteurBase();   // 

	CLecteurBase(char* pcFichier); //

	void Load(); //

	bool NextLine(); //

	bool EmptyLine(); //

	void NextChar(unsigned int longueur); //

	char* LECLireNomFichier(); //

	void LECModifierFichier(const char* fichier); //

	bool IsInt(char* pcInput); //

	bool IsDouble(char* pcInput); //

	bool ToInt(char* pcInput, int& iVar); //

	bool ToDouble(char* pcInput, double& dVar); //

	bool FindWordInFileLine(const char* pcMot, char separateur); //

	// bool FindWordInSameFileWithSeparator(const char* pcMot, char* pcLigne, const char separator);

	char ToLower(char cValeur); //

	char* FindIntInLine(char separateur); //

	char* FindDoubleInLine(char separateur); //

	// char* FindIntInLineWithSeparator(char* pcLigne, const char separator); 

	// char* FindIntInLineAfterSeparator(char* pcLigne, const char separator);

	// char** FindValuesInLine(char* pcLigne, const char separator);

	// void InputIntPositif(const char* pcMessage, int& iVariable);

};
#endif
