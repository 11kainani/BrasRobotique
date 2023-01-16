#ifndef C_LECTEUR_BASE_H
#define C_LECTEUR_BASE_H

#include <fstream>
#include "CException.h"
using namespace std;

/**
 * @brief Boite a outil pour les lecteurs 
*/
class CLecteurBase
{

	const char* pcFichier;
	char* pcLigne;  //Ligne en cours de lecture (alloue sur le tas)
	char* pcCurseur;   //Texte en cours de lecture
	ifstream ifStream;

public:
	/**
	 * @brief Constructeur par default aui cree l'objet CLecteurBase
	*/
	CLecteurBase();    
	/**
	 * @brief Destructeur par default qui desalloue et detruit l'objet CLecteurBase
	*/
	~CLecteurBase(); 
	/**
	 * @brief Constructeur de confort qui cree et initialise le chemin de ce fichier
	 * @param pcFichier 
	*/
	CLecteurBase(const char* pcFichier); 
	/**
	 * @brief Ouvre le fichier a l'adresse "pcFichier"
	*/
	void Load(); 
	/**
	 * @brief Aller a la prochaine ligne dans le fichier
	 * @return true si le passage a ete effectue sinon false
	*/
	bool NextLine(); 
	/**
	 * @brief Verifie si la liste st vide
	 * @return true si la ligne est vide sinon false
	*/
	bool EmptyLine(); 
	/**
	 * @brief Aller au prochain caractere
	 * @param longueur le nombre de caractere a sauter
	*/
	void NextChar(unsigned int longueur); 
	/**
	 * @brief Retourner en arriere
	 * @param cible le caractere a viser  
	 * @param n marquer de la position actuelle
	 * @param afterCible true si on s'arrete apres avoir atteint la cible sinon false
	*/
	void RewindTo(char cible, unsigned int n = 1, bool afterCible = false); 
	/**
	 * @brief Lire le nom du chemin du fihier
	 * @return la chaine lue
	*/
	const char* LECLireNomFichier(); 
	/**
	 * @brief Modifier le chemin du fichier
	 * @param fichier le nouveau chemin du fichier
	*/
	void LECModifierFichier(const char* fichier); 
	/**
	 * @brief Est ce que la chaîne est un entier
	 * @param pcInput la chaine a verifier
	 * @return true is la chaine est une entier sinon false
	*/
	bool IsInt(char* pcInput); 
	/**
	 * @brief Est ce que la chaine est un double
	 * @param pcInput La chaine a analyser
	 * @return true si la chaine est un double sinon false
	*/
	bool IsDouble(char* pcInput); 
	/**
	 * @brief Convertir la chaine en entier
	 * @param pcInput la chaine a convertir
	 * @param iVar l'entier qui accueillera la convertion
	 * @return true seulement si la conversion a eu lieu
	*/
	bool ToInt(char* pcInput, int& iVar); 
	/**
	* @brief Convertir la chaine en double
	* @param pcInput la chaine a convertir
	* @param iVar le double qui accueillera la convertion
	* @return true seulement si la conversion a eu lieu
	*/
	bool ToDouble(char* pcInput, double& dVar); 
	/**
	 * @brief Trouver le mot dans la ligne
	 * @param pcMot Le mot a trouver
	 * @param separateur le separateur qui suit le mot a trouver
	 * @return true si le mot a ete trouver sinon faux
	*/
	bool FindWordInFileLine(const char* pcMot, char separateur); 
	/**
	 * @brief Convertir le caractere en miniscule
	 * @param cValeur charactere a minimiser 
	 * @return character minimise
	*/
	char ToLower(char cValeur); 
	/**
	 * @brief TRouver l'entier qui precede le separateur
	 * @param separateur qui suit l'entier
	 * @return l'entier trouve
	*/
	char* FindIntInLine(char separateur); 
	/**
	 * @brief TRouver le double qui precede le separateur
	 * @param separateur qui suit le double
	 * @return le double trouve
	*/
	char* FindDoubleInLine(char separateur); 
	/**
	 * @brief Retourner le char pointe par le curser
	 * @return le char retourne
	*/
	char GetChar();  



};
#endif