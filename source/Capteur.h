/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if !defined(CAPTEUR_H)
#define CAPTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Point.h"
#include <map>
#include "Mesure.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class Capteur
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    string getId();
    // Mode d'emploi :
    //
    // Contrat :
    //

    string getDescription();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Point &getPosition();
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool getEtat();
    // Mode d'emploi :
    //
    // Contrat :
    //

    double getMesure(string date, TypeMesure type);
    // Mode d'emploi :
    //
    // Contrat :
    //

    double calculMoyennePeriode(string dateDebut, string dateFin, TypeMesure type);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void ajouterMesure(Mesure mesure);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    Capteur &operator=(Capteur &unCapteur);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    //  Xxx ( const Xxx & unXxx );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Capteur(string ide, string desc, double lon, double lat);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Capteur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string id;
    string description;
    bool etat;
    Point position;

    map<string, map<string, Mesure>> listeMesures;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H
