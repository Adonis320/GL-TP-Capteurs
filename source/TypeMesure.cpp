/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TypeMesure> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TypeMesure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

    string TypeMesure::getUnite() const{
        return unite;
    }

    string TypeMesure::getDescription() const{
        return description;
    }

    string TypeMesure::getId() {
        return id;
    }

    string TypeMesure::toString() const{
        string texte = id +", "+ description+", "+unite+"\n";
        return texte;
    }
//------------------------------------------------- Surcharge d'opérateurs
/*Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
/*TypeMesure::TypeMesure ( const Xxx & unXxx )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif
} //----- Fin de Xxx (constructeur de copie)
*/

TypeMesure &TypeMesure::operator=(TypeMesure &unType)
// Algorithme :
//
{
    unite = unType.unite;
    description = unType.description;
    id = unType.id;
    return *this;
} 

TypeMesure::TypeMesure(const TypeMesure & unType)
{
    unite = unType.unite;
    description = unType.description;
    id = unType.id;
}

TypeMesure::TypeMesure (string uni, string desc, string ide)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TypeMesure>" << endl;
#endif
    unite = uni;
    description = desc;
    id = ide;
} //----- Fin de TypeMesure

/*TypeMesure::TypeMesure()
{

}*/

TypeMesure::~TypeMesure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TypeMesure>" << endl;
#endif
} //----- Fin de ~TypeMesure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

