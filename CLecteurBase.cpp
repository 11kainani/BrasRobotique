#include "CLecteurBase.h"



CLecteurBase::CLecteurBase()
{
	pcFichier = nullptr;
	pcLigne = nullptr;
}

CLecteurBase::CLecteurBase(char* fichier)
{
	pcFichier = fichier;
	pcLigne = nullptr;
	Load();
}


/***********************************************************************************************************************************
* Name : LECModifierFichier ********************************************************************************************************
* Entrée : pcFichier  **************************************************************************************************************
* Nécessite : pcLECFichier correspond à un fichier avec le bon format **************************************************************
* Sortie : néant *******************************************************************************************************************
* Entraîne :Modifier pcLECFichier  *************************************************************************************************
************************************************************************************************************************************/
char* CLecteurBase::LECLireNomFichier()
{
	return pcFichier;

}


/***********************************************************************************************************************************
* Name : LECModifierFichier ********************************************************************************************************
* Entrée : pcFichier  **************************************************************************************************************
* Nécessite : pcLECFichier correspond à un fichier avec le bon format **************************************************************
* Sortie : néant *******************************************************************************************************************
* Entraîne :Modifier pcLECFichier  *************************************************************************************************
************************************************************************************************************************************/
void CLecteurBase::LECModifierFichier(const char* fichier)
{
	if (fichier != nullptr)
	{
		pcFichier = (char*)fichier;
	}

}

void CLecteurBase::Load()
{
	if (ifStream.is_open())
	{
		ifStream.close();
	}

	if (pcFichier != nullptr)
	{
		ifStream.open(pcFichier, ifstream::in);
		if (ifStream.is_open() == false)
		{
			// Exception : Chargement échoué
			return;
		}

		pcLigne = (char*)malloc(sizeof(char) * 255);
	}

	ifStream.getline(pcLigne, 255);

}

bool CLecteurBase::NextLine()
{
	(pcLigne)[0] = '\0';
	// Ignore les sauts de lignes
	while ((pcLigne)[0] == '\0' && ifStream.eof() == false)
	{
		ifStream.getline(pcLigne, 255);
	}

	// Retourne Vrai si le contenu de la ligne a changé
	return ((pcLigne)[0] != '\0');
}

bool CLecteurBase::EmptyLine()
{
	return (pcLigne[0] == '\0');
}



void CLecteurBase::NextChar(unsigned int longueur)
{
	char* nouveau = (char*)malloc(sizeof(char) * 255);
	unsigned int uiBoucle = 0;
	unsigned int uiBoucle2 = 0;

	// Vérification que taille(pcLigne) > longueur
	while (uiBoucle < longueur)
	{
		if (pcLigne[uiBoucle] == '\0')
		{
			// Exception : Il n'y a pas d'autres caractères
			return;
		}

		uiBoucle++;
	}

	do
	{
		nouveau[uiBoucle2] = pcLigne[uiBoucle2 + uiBoucle];
		uiBoucle2++;

	} while (pcLigne[uiBoucle2-1 + uiBoucle] != '\0');

	nouveau[uiBoucle2] = '\0';

	free(pcLigne);
	pcLigne = nouveau;

}

bool CLecteurBase::IsInt(char* pcInput)
{
	unsigned int uiBoucle = 1;

	// Retourne false si le premier caractére n'est pas un chiffre ou le signe négatif
	if (pcInput[0] != '-' && (pcInput[0] < '0' || pcInput[0] > '9'))
	{
		return false;
	}

	// Pour chaque caractére suivant
	while (pcInput[uiBoucle] != '\0')
	{
		// Retourne false si le caractére n'est pas un chiffre
		if (pcInput[uiBoucle] < '0' || pcInput[uiBoucle] > '9')
		{
			return false;
		}

		uiBoucle++;
	}

	return true; // pcInput correspond au format d'une variable type int

}

bool CLecteurBase::IsDouble(char* pcInput)
{
	unsigned int uiBoucle = 1;
	bool bPoint = false; // Un caractére point a été lu

	// Retourne false si le premier caractére n'est pas un chiffre, signe négatif ou point
	if (pcInput[0] != '-' && pcInput[0] != '.' && (pcInput[0] < '0' || pcInput[0] > '9'))
	{
		return false;
	}

	// S'il s'agit d'un format ".i", le caractére point est le premier caractére
	if (pcInput[0] == '.')
	{
		bPoint = true;
	}

	// Pour chaque caractére suivant
	while (pcInput[uiBoucle] != '\0')
	{
		// S'il s'agit d'un point
		if (pcInput[uiBoucle] == '.')
		{
			if (bPoint) // Retourner false si ce n'est pas la premiére fois qu'il a été lu
			{
				return false;
			}
			bPoint = true; // Le caractére point a été lu pour la premiére fois
		}
		// Retourne false si le caractére n'est pas un chiffre
		else if (pcInput[uiBoucle] < '0' || pcInput[uiBoucle] > '9')
		{
			return false;
		}

		uiBoucle++;
	}

	return true; // pcInput correspond au format d'une variable de type double
}

bool CLecteurBase::ToInt(char* pcInput, int& iVar)
{
	unsigned int uiBoucle = 1;
	if (IsInt(pcInput) == false)
		return false;

	iVar = 0; // Affectation de la valeur par défaut
	if (pcInput[0] != '-')
	{
		iVar = (int)(pcInput[0] - '0'); // Affectation du premier chiffre si nombre positif
	}

	// Pour les chiffres suivants
	while (pcInput[uiBoucle] != '\0')
	{
		// Si nombre négatif 
		if (pcInput[0] == '-')
		{
			iVar = iVar * 10 - (int)(pcInput[uiBoucle] - '0');
		}
		// Sinon nombre positif
		else
		{
			iVar = iVar * 10 + (int)(pcInput[uiBoucle] - '0');
		}

		uiBoucle++;
	}

	return true;
}

bool CLecteurBase::ToDouble(char* pcInput, double& dVar)
{
	unsigned int uiBoucle = 1;
	bool bPoint = false; // Le caractére point a été lu
	double dDiviseur = 10; // divisera le chiffre avant de l'ajouter é dVar
	if (IsDouble(pcInput) == false)
		return false;

	dVar = 0; // Affectation de la valeur par défaut
	if ('0' <= pcInput[0] && pcInput[0] <= '9')
	{
		dVar = (double)(pcInput[0] - '0');
	}

	if (pcInput[0] == '.')
	{
		bPoint = true;
	}

	while (pcInput[uiBoucle] != '\0')
	{
		if (pcInput[uiBoucle] == '.')
		{
			bPoint = true;
		}
		else if (bPoint == false)
		{
			if (pcInput[0] == '-')
			{
				dVar = dVar * 10 - (double)(pcInput[uiBoucle] - '0');
			}
			else
			{
				dVar = dVar * 10 + (double)(pcInput[uiBoucle] - '0');
			}
		}
		else
		{
			if (pcInput[0] == '-')
			{
				dVar = dVar - (double)(pcInput[uiBoucle] - '0') / dDiviseur;
			}
			else
			{
				dVar = dVar + (double)(pcInput[uiBoucle] - '0') / dDiviseur;
			}
			dDiviseur *= 10;
		}

		uiBoucle++;
	}

	return true;
}

bool CLecteurBase::FindWordInFileLine(const char* pcMot, char separateur)
{
	unsigned int uiBoucle;
	char pcTexte[255] = "\0"; // Un tableau contenant les caractéres autres que ' ' du fichier
	unsigned int uiIndice = 0; // indice du dernier caractére de pcTexte
	char* pcCaractere = nullptr;  // Caractère en cours d'analyse

	pcCaractere = &(pcLigne)[0];

	// Recherche du mot pcMot suivit d'un separateur dans la ligne
	do
	{
		while (*pcCaractere != '\0' && *pcCaractere != separateur)
		{
			// Récupére tous les caractéres autre que separateur et ' '
			if (*pcCaractere != ' ')
			{
				pcTexte[uiIndice] = ToLower(*pcCaractere);
				uiIndice++;
			}

			pcCaractere++; // passe au caractére suivant
		}

		//if (*pcCaractere != '=') // Si le caractére '=' n'a pas été rencontré
			//fichier.getline(pcLigne, 255); // Lis la ligne suivante
	} while (pcTexte[0] == '\0' && (*pcCaractere != '\0' || *pcCaractere != separateur));

	pcTexte[uiIndice] = '\0'; // Ajout du caractére de fin de chaine

	NextChar(uiIndice); // On passe au texte après le mot récupéré

	// Retourne la comparaison des deux mots
	uiBoucle = 0;
	while (pcMot[uiBoucle] != '\0')
	{
		// Si le mot recherché est plus grand que celui récupéré
		if (uiBoucle >= uiIndice)
			return false;

		// Si un caractère est différent entre les deux mots
		if (pcTexte[uiBoucle] != ToLower(pcMot[uiBoucle]))
			return false;

		uiBoucle++;
	}

	return true;
}

/*
bool CLecteurBase::FindWordInSameFileLineWithSeparator(const char* pcMot, char* pcLigne, const char separator)
{
	unsigned int uiBoucle;
	char pcTexte[255] = "\0"; // Un tableau contenant les caractéres autres que ' ' du fichier
	unsigned int uiIndice = 0; // indice du dernier caractére de pcTexte
	char* pcCaractere = nullptr;

	pcCaractere = &pcLigne[0];
	while (*pcCaractere != separator && *pcCaractere != '\0')
	{
		pcCaractere++;
	}


	// Recherche du mot pcMot précédé d'un caractére '=' sur la méme ligne
	while (*pcCaractere != '\0' && *pcCaractere != '=')
	{
		// Récupére tous les caractéres autre que '=' et ' '
		if (*pcCaractere != ' ' && *pcCaractere != separator)
		{
			pcTexte[uiIndice] = ToLower(*pcCaractere);
			uiIndice++;
		}

		pcCaractere++; // passe au caractére suivant
	}

	pcTexte[uiIndice] = '\0'; // Ajout du caractére de fin de chaine

	// Retourne la comparaison des deux mots
	uiBoucle = 0;
	while (pcMot[uiBoucle] != '\0')
	{
		// Si le mot recherché est plus grand que celui récupéré
		if (uiBoucle >= uiIndice)
			return false;

		// Si un caractère est différent entre les deux mots
		if (pcTexte[uiBoucle] != ToLower(pcMot[uiBoucle]))
			return false;

		uiBoucle++;
	}
	return true;
}
*/


char CLecteurBase::ToLower(char cLettre)
{
	if ('A' <= cLettre && cLettre <= 'Z')
	{
		cLettre = cLettre - 'A' + 'a';
	}

	return cLettre;
}

char* CLecteurBase::FindIntInLine(char separateur)
{
	unsigned int uiBoucle;
	char pcTexte[255] = "\0"; // Un tableau contenant les caractéres autres que ' ' du fichier
	unsigned int uiIndice = 0; // indice du dernier caractére de pcTexte
	char* pcCaractere = nullptr;

	pcCaractere = &(pcLigne)[0];
	while (*pcCaractere != separateur && *pcCaractere != '\0')
	{
		pcCaractere++;
	}

	// Recherche d'un entier précédé d'un caractére separateur sur la méme ligne
	while (*pcCaractere != '\0' && *pcCaractere != '\n')
	{
		// Récupére tous les caractéres autre que '\n', separateur et ' '
		if (*pcCaractere != ' ' && *pcCaractere != separateur)
		{
			pcTexte[uiIndice] = *pcCaractere;
			uiIndice++;
		}

		pcCaractere++; // passe au caractére suivant
	}

	pcTexte[uiIndice] = '\0'; // Ajout du caractére de fin de chaine

	NextChar(uiIndice); // On passe au texte après le nombre récupéré

	// S'il s'agit d'un entier, on retourne sa chaine de caractére allouée sur le tas
	if (IsInt(pcTexte))
	{
		pcCaractere = (char*)malloc(sizeof(char) * (uiIndice + 1));
		for (uiBoucle = 0; uiBoucle < uiIndice; uiBoucle++)
		{
			pcCaractere[uiBoucle] = pcTexte[uiBoucle];
		}
		pcCaractere[uiIndice] = '\0';

		return pcCaractere;
	}

	return nullptr;
}

char* CLecteurBase::FindDoubleInLine(char separateur)
{
	unsigned int uiBoucle;
	char pcTexte[255] = "\0"; // Un tableau contenant les caractéres autres que ' ' du fichier
	unsigned int uiIndice = 0; // indice du dernier caractére de pcTexte
	unsigned int uiLength = 0; // nombre de caractères analysés
	char* pcCaractere = nullptr;

	pcCaractere = &(pcLigne)[0];

	// Recherche d'un réel suivit d'un caractére separateur sur la méme ligne
	while (*pcCaractere != '\0' && *pcCaractere != '\n' && *pcCaractere != separateur)
	{
		// Récupére tous les caractéres autre que '\n' et ' '
		if (*pcCaractere != ' ')
		{
			pcTexte[uiIndice] = *pcCaractere;
			uiIndice++;
		}

		pcCaractere++; // passe au caractére suivant
		uiLength++;
	}

	pcTexte[uiIndice] = '\0'; // Ajout du caractére de fin de chaine

	NextChar(uiLength); // On passe au texte après le nombre récupéré

	if (uiIndice > 0)
	{
		NextChar(1);
	}

	// S'il s'agit d'un réel, on retourne sa chaine de caractére allouée sur le tas
	if (IsDouble(pcTexte))
	{
		pcCaractere = (char*)malloc(sizeof(char) * (uiIndice + 1));
		for (uiBoucle = 0; uiBoucle < uiIndice; uiBoucle++)
		{
			pcCaractere[uiBoucle] = pcTexte[uiBoucle];
		}
		pcCaractere[uiIndice] = '\0';

		return pcCaractere;
	}

	return nullptr;
}

/*
char* CLecteurBase::FindIntInLineWithSeparator(char* pcLigne, const char separator)
{
	unsigned int uiBoucle;
	char pcTexte[255] = "\0"; // Un tableau contenant les caractéres autres que ' ' du fichier
	unsigned int uiIndice = 0; // indice du dernier caractére de pcTexte
	char* pcCaractere = nullptr;

	pcCaractere = &pcLigne[0];
	while (*pcCaractere != '=' && *pcCaractere != '\0')
	{
		pcCaractere++;
	}

	// Recherche d'un entier précédé d'un caractére '=' sur la méme ligne
	while (*pcCaractere != '\0' && *pcCaractere != '\n' && *pcCaractere != separator)
	{
		// Récupére tous les caractéres autre que '\n', '=' et ' '
		if (*pcCaractere != ' ' && *pcCaractere != '=')
		{
			pcTexte[uiIndice] = *pcCaractere;
			uiIndice++;
		}

		pcCaractere++; // passe au caractére suivant
	}

	pcTexte[uiIndice] = '\0'; // Ajout du caractére de fin de chaine

	// S'il s'agit d'un entier, on retourne sa chaine de caractére allouée sur le tas
	if (IsInt(pcTexte))
	{
		pcCaractere = (char*)malloc(sizeof(char) * (uiIndice + 1));
		for (uiBoucle = 0; uiBoucle < uiIndice; uiBoucle++)
		{
			pcCaractere[uiBoucle] = pcTexte[uiBoucle];
		}
		pcCaractere[uiIndice] = '\0';

		return pcCaractere;
	}

	return nullptr;
}
*/

/*
char* CLecteurBase::FindIntInLineAfterSeparator(char* pcLigne, const char separator)
{
	unsigned int uiBoucle;
	char pcTexte[255] = "\0"; // Un tableau contenant les caractéres autres que ' ' du fichier
	unsigned int uiIndice = 0; // indice du dernier caractére de pcTexte
	char* pcCaractere = nullptr;

	pcCaractere = &pcLigne[0];
	while (*pcCaractere != separator)
	{
		pcCaractere++;
	}
	while (*pcCaractere != '=' && *pcCaractere != '\0')
	{
		pcCaractere++;
	}

	// Recherche d'un entier précédé d'un caractére '=' sur la méme ligne
	while (*pcCaractere != '\0' && *pcCaractere != '\n' && *pcCaractere != separator)
	{
		// Récupére tous les caractéres autre que '\n', '=' et ' '
		if (*pcCaractere != ' ' && *pcCaractere != '=')
		{
			pcTexte[uiIndice] = *pcCaractere;
			uiIndice++;
		}

		pcCaractere++; // passe au caractére suivant
	}

	pcTexte[uiIndice] = '\0'; // Ajout du caractére de fin de chaine

	// S'il s'agit d'un entier, on retourne sa chaine de caractére allouée sur le tas
	if (IsInt(pcTexte))
	{
		pcCaractere = (char*)malloc(sizeof(char) * (uiIndice + 1));
		for (uiBoucle = 0; uiBoucle < uiIndice; uiBoucle++)
		{
			pcCaractere[uiBoucle] = pcTexte[uiBoucle];
		}
		pcCaractere[uiIndice] = '\0';

		return pcCaractere;
	}

	return nullptr;
}
*/

/*
char** CLecteurBase::FindValuesInLine(char* pcLigne, unsigned int uiNbValeurs)
{
	unsigned int uiBoucle;
	unsigned int uiBoucle2;
	char pcTexte[255]; // Un tableau contenant les caractéres autres que ' ' du fichier
	unsigned int uiIndice; // indice du dernier caractére de pcTexte
	char* pcCaractere = nullptr;
	char** ppcValeurs = (char**)malloc(sizeof(char*) * uiNbValeurs);

	pcCaractere = &pcLigne[0];

	// Récupére les nombres contenus dans la ligne
	for (uiBoucle = 0; uiBoucle < uiNbValeurs; uiBoucle++)
	{
		// ignore les espaces avant le nombre
		while (*pcCaractere == ' ')
		{
			pcCaractere++;
		}

		uiIndice = 0;
		// Récupére tous les caractéres jusqu'é lire ' ', '\0' ou '\n' 
		while (*pcCaractere != ' ' && *pcCaractere != '\0' && *pcCaractere != '\n')
		{
			pcTexte[uiIndice] = *pcCaractere;
			uiIndice++;

			pcCaractere++; // passe au caractére suivant
		}
		pcTexte[uiIndice] = '\0'; // Ajout du caractére de fin de chaine

		// Récupére les caractéres de pcTexte
		ppcValeurs[uiBoucle] = (char*)malloc(sizeof(char) * (uiIndice + 1));
		for (uiBoucle2 = 0; uiBoucle2 < uiIndice; uiBoucle2++)
		{
			ppcValeurs[uiBoucle][uiBoucle2] = pcTexte[uiBoucle2];
		}
		ppcValeurs[uiBoucle][uiIndice] = '\0';

	}

	// Vérification du type de chaque chaine récoltée
	for (uiBoucle = 0; uiBoucle < uiNbValeurs; uiBoucle++)
	{
		// Si l'une d'elles n'a pas le format d'un double, Arrét de la boucle
		if (IsDouble(ppcValeurs[uiBoucle]) == false)
		{
			uiBoucle = uiNbValeurs;
		}
	}

	// S'il y a eu arrét de la boucle, on désalloue ppcValeurs et on retournera nullptr
	if (uiBoucle > uiNbValeurs)
	{
		for (uiBoucle = 0; uiBoucle < uiNbValeurs; uiBoucle++)
		{
			free(ppcValeurs[uiBoucle]);
		}
		free(ppcValeurs);
		ppcValeurs = nullptr;
	}

	// Sinon retourne les valeurs récoltées sous forme de chaines
	return ppcValeurs;
}
*/
