/*************************************************************************
Mesure  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <Mesure> (fichier Mesure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

string Mesure::toString() const
// Algorithme :
//
{
	return("Type: " + type.toString() + " valeur: " + to_string(valeur) + " effectu�e le " + date + " par " + capteur.toString());
} //----- Fin de M�thode



string Mesure::getDate() const
// Algorithme :
//
{
	return date;
} //----- Fin de M�thode

const TypeMesure* Mesure::getType() const
// Algorithme :
//
{
	return (&type);
} //----- Fin de M�thode


const Capteur* Mesure::getSensor() const
// Algorithme :
//
{
	return (&capteur);
} //----- Fin de M�thode

double Mesure::getValue() 
// Algorithme :
//
{
	return (valeur);
} //----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
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

  //----------------------------------------------------- M�thodes prot�g�es

