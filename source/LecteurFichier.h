/*************************************************************************
LecteurFichier  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <LecteurFichier> (fichier LecteurFichier.h) ----------------
#if ! defined ( LecteurFichier_H )
#define LecteurFichier_H

//--------------------------------------------------- Interfaces utilis�es
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
// R�le de la classe <LecteurFichier>
//
//
//------------------------------------------------------------------------

class LecteurFichier
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- M�thodes publiques
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

	void getMesureMethode2(map<string,Capteur*>* mapCapteur, map<string,TypeMesure*>* mapType, string dateDebut, string dateFin);

	Mesure* getMesure(string capteurId, TypeMesure* type, string dateDebut, string dateFin);
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


	void closeFlux();

	bool good();

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
	ifstream flux;
	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

};

//-------------------------------- Autres d�finitions d�pendantes de <Xxx>

#endif // XXX_H

