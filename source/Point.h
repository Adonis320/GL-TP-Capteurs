/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if ! defined ( POINT_H )
#define POINT_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    long double getLatitude();

    long double getLongitude();

//------------------------------------------------- Surcharge d'opérateurs
    Point & operator = (const Point & unPoint );
    // Mode d'emploi :
    //
    // Contrat :
    //

    string toString();
//-------------------------------------------- Constructeurs - destructeur
    //Xxx ( const Xxx & unXxx );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //


    Point (long double lat,long double longi);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Point ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    long double latitude;
    long double longitude;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // XXX_H

