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
#include "Capteur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Capteur::ajouterMesure(Mesure mesure){
    map<string,map<string,Mesure>>::iterator position;

    position = listeMesures.find(mesure.getType());
    if(position == listeMesures.end()){
        listeMesures.insert(make_pair(mesure.getType(),))
    }
}

//------------------------------------------------- Surcharge d'opérateurs
Capteur & Capteur::operator = (Capteur & unCapteur )
// Algorithme :
//
{
	id = unCapteur.id;
    description = unCapteur.description;
    position = unCapteur.position;
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/*Xxx::Xxx ( const Xxx & unXxx )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif
} //----- Fin de Xxx (constructeur de copie)
*/

Capteur::Capteur (string ide, string desc, double lon, double lat) : position(lat,lon)
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de <Capteur>" << endl;
#endif

    id = ide;
    description = desc;
} //----- Fin de Capteur


Capteur::~Capteur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Capteur>" << endl;
#endif
} //----- Fin de ~Capteur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

