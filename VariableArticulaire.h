#ifndef VARIABLE_ARTICULAIRE_H
#define VARIABLE_ARTICULAIRE_H

#include <iostream>

class VariableArticulaire
{
private:
	double dvaleur;

	double dvariable;  // copie de fvaleur accessible uniquement en lecture

	double fmin;

	double fmax;

	bool bvariable;

	bool bAngulaire;


public:
	/**
	 * @brief Constructeur par default qui cr�e un objet VariableArticulaire
	*/
	VariableArticulaire();

	/**
	 * @brief Construteur de confort qui cr�e et initialise les champs de VariableArticulaire
	 * @param fValue valeur de lla variableArticulaire 
	 * @param fMinValue valeur mini si la variableArticulaire varie
	 * @param fMaxValue valeur max si la variableArticulaire varie
	 * @param bIsVariable Est ce que la variableArticualire varie ?
	*/
	VariableArticulaire(double fValue, int fMinValue, int fMaxValue, int bIsVariable);

	/**
	 * @brief Destructeur par default qui d�saloue et d�trruit l'objet VariableArticulaire
	*/
	~VariableArticulaire();
	/**
	 * @brief Lis la valeur de la variablearticculaire
	 * @return la valuer lue
	*/
	double LireValeur();
	/**
	 * @brief Modifie la valeur de cette variable articulaire
	 * @param fValue la nouvelle valeur de la variablearticulaire
	 * @return true si la modification a eu lieu sion false
	*/
	bool ModifierValeur(double fValue);
	/**
	 * @brief Lis la valeur dvariable
	 * @return le pointeur sur dvariable
	*/
	double* LireVariable();
	/**
	 * @brief Lire la valeur max
	 * @return la valeur lue
	*/
	double LireMax();
	/**
	 * @brief Modifier la valeur max
	 * @param max la nouvelle valeur max
	 * @return true si la modification a eu lieu sinon false
	*/
	bool ModifierMax(double max);
	/**
	 * @brief Lire la valeur min
	 * @return la valeur lue 
	*/
	double LireMin();
	/**
	 * @brief Modifier la valeur minimale
	 * @param min la nouvelle valeur minimale
	 * @return true si la valeur a �t� modifi� sinon false
	*/
	bool ModifierMin(double min);
	/**
	 * @brief Lire le bool�an BVariable
	 * @return true si ette variablearticulaire varie sinon false
	*/
	bool LireBVariable();
	/**
	 * @brief Modifier le bool�an BVariable
	 * @param bValue la nouvelle valeur de bVariable
	*/
	void ModifierBVariable(bool bValue);

	/**
	 * @brief Lire le bool�an BAngulaire
	 * @return la valeur lue
	*/
	bool LireBAngulaire();
	/**
	 * @brief Modifier le bool�an BAngulaire
	 * @param bValue la nouvelle valeur de BAngulaire
	*/
	void ModifierBAngulaire(bool bValue);

};
#endif