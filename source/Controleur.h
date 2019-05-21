/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if ! defined ( CONTROLEUR_H )
#define CONTROLEUR_H

//--------------------------------------------------- Interfaces utilisées
#include "Point.h"
#include "Capteur.h"
#include "TypeMesure.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class Controleur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void initTypeMesure();

    string lireTypeMesures();

    string lireListeCapteurs();

    string lireListeCapteursMalfonctionnant();

    void getCapteurRegion(Point p1, Point p2);

    string calculMoyenneSurPeriode(string date1, string date2);

    string calculMoyenneMoment(string date);

    string calculMoyenneSurPeriode(TypeMesure type, string date1, string date2);

    string calculMoyenneMoment(TypeMesure, string date1);

    string getAllMesure(string dateDebut, string dateFin);

    string getMesure(string attributID, string dateDebut, string dateFin);

    double getMoyenne(Capteur capteur);

    double getAtmo(string date);

    void verifierCapteur();

    void changerZoneCapteurs();
//------------------------------------------------- Surcharge d'opérateurs
    //Xxx & operator = ( const Xxx & unXxx );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Xxx ( const Xxx & unXxx );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Controleur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Controleur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    map <string, Capteur> listeCapteurs;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H

