/*************************************************************************
Mesure  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Mesure> (fichier Mesure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Mesure::toString() const
// Algorithme :
//
{
	return("Type: " + type.toString() + " valeur: " + to_string(valeur) + " effectuée le " + date + " par " + capteur.toString());
} //----- Fin de Méthode



string Mesure::getDate() const
// Algorithme :
//
{
	return date;
} //----- Fin de Méthode

const TypeMesure* Mesure::getType() const
// Algorithme :
//
{
	return (&type);
} //----- Fin de Méthode


const Capteur* Mesure::getSensor() const
// Algorithme :
//
{
	return (&capteur);
} //----- Fin de Méthode

double Mesure::getValue() 
// Algorithme :
//
{
	return (valeur);
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Mesure & Mesure::operator = (const Mesure & uneMesure)
// Algorithme :
//
{
	valeur = uneMesure.valeur;
	date = uneMesure.date;
	capteur = uneMesure.capteur;
	type = uneMesure.type;
	return (*this);

} //----- Fin de operator =


  //-------------------------------------------- Constructeurs - destructeur
Mesure::Mesure(const Mesure & uneMesure)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Mesure>" << endl;
#endif
	valeur = uneMesure.valeur;
	date = uneMesure.date;
	capteur = uneMesure.capteur;
	type = uneMesure.type;

} //----- Fin de Mesure (constructeur de copie)


Mesure::Mesure(double uneValeur, string unedate, Capteur* unCapteur, TypeMesure* untype)
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <Mesure>" << endl;
#endif
	valeur = uneValeur;
	date = unedate;
	capteur = *(unCapteur);
	type = *(untype);
} //----- Fin de Mesure


Mesure::~Mesure()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Mesure>" << endl;
#endif
} //----- Fin de ~Mesure


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

