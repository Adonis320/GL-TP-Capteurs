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
    id = unCapteur.getId();
    description = unCapteur.getDescription();
    position = unCapteur.getPosition();
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
    cout << "Appel au constructeur de <Xxx>" << endl;
#endif

    id = ide;
    description = desc;
} //----- Fin de Xxx


Capteur::~Capteur ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

