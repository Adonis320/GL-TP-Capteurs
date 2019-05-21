/*************************************************************************
LecteurFichier  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <LecteurFichier> (fichier LecteurFichier.h) ----------------
#if ! defined ( LecteurFichier_H )
#define LecteurFichier_H

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include <string>
#include "Point.h"
#include "Capteur.h"
#include "Mesure.h"
#include "TypeMesure.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LecteurFichier>
//
//
//------------------------------------------------------------------------

class LecteurFichier
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	Capteur* getCapteurParRegion(Point point1, Point point2);
	// Mode d'emploi :
	//
	// Contrat :
	//

	Mesure* getAllMesure(string capteurId, string dateDebut, string dateFin);
	// Mode d'emploi :
	//
	// Contrat :
	//

	Mesure* getMesure(string capteurId, string attributId, string dateDebut, string dateFin);
	// Mode d'emploi :
	//
	// Contrat :
	//

	TypeMesure* getTypeMesure();
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool eof();
	// Mode d'emploi :
	//
	// Contrat :
	//

	bool fail();
	// Mode d'emploi :
	//
	// Contrat :
	//

	void setFlux(string nomFichier);
	// Mode d'emploi :
	//
	// Contrat :
	//

	//-------------------------------------------- Constructeurs - destructeur
	LecteurFichier();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~LecteurFichier();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	ifstream flux;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H

