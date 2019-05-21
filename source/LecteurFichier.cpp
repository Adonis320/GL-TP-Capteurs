/*************************************************************************
Xxx  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <LecteurFichier> (fichier LecteurFichier.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "LecteurFichier.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
Capteur* LecteurFichier::getCapteurParRegion(Point point1, Point point2)
//Algorithme :
//
{
} //----- Fin de getCapteurParRegion

Mesure* LecteurFichier::getAllMesure(string capteurId, string dateDebut, string dateFin)
//Algorithme :
//
{
} //----- Fin de getAllMesure

Mesure* LecteurFichier::getMesure(string capteurId, string attributId, string dateDebut, string dateFin)
//Algorithme :
//
{
} //----- Fin de getMesure

TypeMesure* LecteurFichier::getTypeMesure()
//Algorithme :
//
{
} //----- Fin de getTypeMesure

bool LecteurFichier::eof()
//Algorithme :
//
{
	return flux.eof();
} //----- Fin de eof

bool LecteurFichier::fail()
//Algorithme :
//
{
	return flux.fail();
} //----- Fin de fail

void LecteurFichier::setFlux(string nomFichier)
//Algorithme :
//
{
	flux.open(nomFichier);
} //----- Fin de setFlux

//-------------------------------------------- Constructeurs - destructeur
LecteurFichier::LecteurFichier()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au constructeur de <LecteurFichier>" << endl;
#endif
} //----- Fin de LecteurFichier


LecteurFichier::~LecteurFichier()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <LecteurFichier>" << endl;
#endif
} //----- Fin de ~LecteurFichier


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées

