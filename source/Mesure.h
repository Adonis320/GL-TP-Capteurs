/*************************************************************************
Mesure  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Mesure> (fichier Mesure.h) ----------------
#if ! defined ( MESURE_H )
#define MESURE_H

//--------------------------------------------------- Interfaces utilis�es
#include "TypeMesure.h"
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Mesure>
//
//
//------------------------------------------------------------------------

class Mesure
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques

	string getDate() const;
	// Mode d'emploi :
	//
	// Contrat :
	//

	double getValue();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//const Capteur* getSensor() const;
	// Mode d'emploi :
	//
	// Contrat :
	//

	TypeMesure* getType();
	// Mode d'emploi :
	//
	// Contrat :
	//

	string toString() const;
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------- Surcharge d'op�rateurs
	Mesure & operator = (const Mesure & uneMesure);
	// Mode d'emploi :
	//
	// Contrat :
	//


	//-------------------------------------------- Constructeurs - destructeur
	Mesure(const Mesure & uneMesure);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Mesure(double uneValeur, string unedate, TypeMesure *untype, string capteur);
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Mesure();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	double valeur;
	string date;
	string capteurID;
	TypeMesure *type;
};

//-------------------------------- Autres d�finitions d�pendantes de <Mesure>

#endif // MESURE_H

