#ifndef DENAVIT_PARAMETER_H
#define DENAVIT_PARAMETER_H

#include <iostream>
#include "VariableArticulaire.h"
using namespace std;
#define NB_VARIABLES 4

class DenavitParameter
{
private:
	VariableArticulaire** pVARVariable;

public:
	/**
	 * @brief Constructeur par default qui crée un objet DenavitParameter
	*/
	DenavitParameter();
	/**
	 * @brief Constructeur de confort qui initialise l'objet DenavitParameter avec la liste de pointeurs de variableArticulaire VARListe
	 * @param VARListe liste de VariableArticulaire
	*/
	DenavitParameter(VariableArticulaire** VARListe);
	/**
	 * @brief Constructeur de recopie qui crée et initialise l'objet DenavitParameter 
	 * @param DENObject 
	*/
	DenavitParameter(DenavitParameter& DENObject);
	/**
	 * @brief Destructeur par default qui détruit l'objet DenavitParameter
	*/
	~DenavitParameter();
	/**
	 * @brief Modifie le variable articulaire à la position iIndice dans la liste de pointeurs de variableArticuaire
	 * @param iIndice l'indice de l'élément à modifier
	 * @param VARvariable le nouveau pointeur sur variableArticulaire
	*/
	void SetVariable(int iIndice, VariableArticulaire* VARvariable);
	/**
	 * @brief Supprimer le variableArticulaire à la position iIndice dans la liste de pointeurs de variableArticulaire
	 * @param iIndice 
	*/
	void DeleteVariable(int iIndice);

	/**
	 * @brief Surcharge de l'égalité 
	 * @param parameter 
	 * @return 
	*/
	DenavitParameter& operator=(DenavitParameter& parameter);

	/**
	 * @brief Lis la valeur dVariable de la variableArticulaire à l'indice Iindice 
	 * @param Iindice L'indice de la variableArticulaire dans la liste de pointeurs dans cette DevanitParameter
	 * @return la valeur lue
	*/
	double* LireVariable(int Iindice);
	/**
	 * @brief Lis la valeur dValeur de la variableArticulaire à l'indice Iindice
	 * @param Iindice L'indice de la variableArticulaire dans la liste de pointeurs dans cette DevanitParameter
	 * @return la valeur lue
	*/
	double LireValeur(int Iindice);
	/**
	 * @brief Lire la valeur BVariable
	 * @param Iindice l'indice de la variableArticulaire dans la liste de pointeurs 
	 * @return true si la variableArticulaire varie sinon false
	*/
	bool LireBVariable(int Iindice);
	/**
	 * @brief Afficher la DenavitParameter
	*/
	void Affiche();

};
#endif