#ifndef C_LECTEUR_BASE_H
#define C_LECTEUR_BASE_H

#include <fstream>
#include "CException.h"
using namespace std;

class CLecteurBase
{

	const char* pcFichier;
	char* pcLigne; // Ligne en cours de lecture (allou� sur le tas)
	char* pcCurseur;  // Texte en cours de lecture
	ifstream ifStream;

public:
	CLecteurBase();   // 

	~CLecteurBase(); //

	CLecteurBase(const char* pcFichier); //

	void Load(); //

	bool NextLine(); //

	bool EmptyLine(); //

	void NextChar(unsigned int longueur); //

	void RewindTo(char cible, unsigned int n = 1, bool afterCible = false); //

	const char* LECLireNomFichier(); //

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

	char GetChar(); // 

	// char* FindIntInLineWithSeparator(char* pcLigne, const char separator); 

	// char* FindIntInLineAfterSeparator(char* pcLigne, const char separator);

	// char** FindValuesInLine(char* pcLigne, const char separator);

	// void InputIntPositif(const char* pcMessage, int& iVariable);


};
#endif