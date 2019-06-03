/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

long double Point::getLatitude(){
    return latitude;
}

long double Point::getLongitude(){
    return longitude;
}

string Point::toString(){
    return ("Latitude = "+to_string(latitude)+", Longitude = "+to_string(longitude));
}
//------------------------------------------------- Surcharge d'opérateurs

Point & Point::operator = (const Point & unPoint)
{
    latitude = unPoint.latitude;
    longitude = unPoint.longitude;
    return *this;
}

//-------------------------------------------- Constructeurs - destructeur

Point::Point (long double lat, long double longi)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
    latitude = lat;
    longitude = longi;
} //----- Fin de Point


Point::~Point ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- Fin de ~Point


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

