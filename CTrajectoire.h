#ifndef C_TRAJECTOIRE_H
#define C_TRAJECTOIRE_H

#include <iostream>
#include <fstream>

#include "CLecteurBase.h"
#include "VariableArticulaire.h"
#include "CMatrice.h"
#include "DenavitParameter.h"

class CTrajectoire : public CLecteurBase
{

private:
	/**
	 * @brief Objet CMatrice n�cessaire pour d�finir la liste de points de trajectoire
	*/
	CMatrice* TRAMatrice;
	/**
	 * @brief Nombre de matrice correctement lue
	*/
	unsigned int uiMatriceLues;
	/**
	 * @brief Nombre de point de trajectoire dans le fichier
	*/
	unsigned int uiNbPoints;


public:
	/**
	 * @brief Constructeur par default
	 * Cr�e et initialiser un objet CTrajectoire
	*/
	CTrajectoire();
	/**
	 * @brief Constructeur de confort
	 * @param pcCheminFicher 
	 * Cree et initialiser un objet CTrajectoire avec un chemin du fichier � lire
	*/
	CTrajectoire(const char* pcCheminFicher);
	/**
	* @brief Destructeur par defaut
	* D�salloue et d�truit un objet CTrajectoire
	*/
	~CTrajectoire();

	/**
	 * @brief Lire matrice 
	 * @param uiIndice 
	 * Lire matrice � l'indice (uiIndice)
	*/
	CMatrice TRALireMatrice(unsigned int uiIndice);

	/**
	 * @brief Lire le nombre de points du trajectoire
	 * @return Le nombre de points de trajectoire dans le fichier
	*/
	unsigned int LireNbPoints();

	/**
	 * @brief Lire le nombre de points lus dans le fichier
	*/
	unsigned int LireNbLu();

	/**
	 * @brief Moiidifer le nom du fichier 
	*/
	void ModifierFichier(const char* pcFichier);

	/**
	 * @brief Lire le fichier 
	 * Necessite : Le chemin du fichier soit correctement initialis�
	 * 
	*/
	void LireFichier();


	void AffichierMatrices();

};







#endif