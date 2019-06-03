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

void Capteur::ajouterMesure(Mesure *mesure)
{
    map<string, map<string, Mesure*>>::iterator ite1;

    map<string, Mesure*>::iterator ite2;

    ite1 = listeMesures.find(mesure->getType()->getId());

    if (ite1 == listeMesures.end())
    {
        map<string, Mesure*> mapMes;
        mapMes.insert(make_pair(mesure->getDate(), mesure));
        listeMesures.insert(make_pair(mesure->getType()->getId(), mapMes));
     //   cout << "je trouve pas" +mesure->getType()->getId()<<endl;
    }
    else
    {
        ite1->second.insert(make_pair(mesure->getDate(), mesure));
       // cout <<"je trouve "+mesure->getType()->getId()<<endl;
    }
    //cout << mesure->toString() << endl;
}

double Capteur::getMesure(string date, TypeMesure* type)
{
    double valeur = 0;
    //ATTENTION IL N Y A PAS DE DATE EXACTE FAUT QU'ON SE DEMERDE AUSSI POUR CONVERTIR DATE EN STRING OU UN TRUC DU GENRE
    map<string, map<string, Mesure*>>::iterator ite1;

    map<string, Mesure*>::iterator ite2;

    ite1 = listeMesures.find(type->getId());
    if (ite1 != listeMesures.end())
    {
        for (ite2 = ite1->second.begin(); ite2 != ite1->second.end(); ite2++)
        {
            if (ite2->first.substr(11,2) >= date.substr(11,2) && stoi(ite2->first.substr(11,2)) < (stoi(date.substr(11,2))+1))// a changer aussi
            {
                valeur = ite2->second->getValue();
            }
        }
    }

    return valeur;
}

double Capteur::calculMoyennePeriode(string dateDebut, string dateFin, TypeMesure *type)
{
    double moyenne = 0;
    double compteur = 0;
    //ATTENTION !!! ON NE PEUT PAS COMPARER DES DATES EN ETANT DES STRING.... FAUT SE DEMERDER AUSSI
    map<string, map<string, Mesure*>>::iterator ite1;

    map<string, Mesure*>::iterator ite2;

    ite1 = listeMesures.find(type->getId());

    if (ite1 != listeMesures.end())
    {
        for (ite2 = ite1->second.begin(); ite2 != ite1->second.end(); ite2++)
        {
            if (ite2->first >= dateDebut && ite2->first <= dateFin)
            {
                moyenne = moyenne + ite2->second->getValue();
                compteur++;
            }
        }
    }
    if (compteur == 0)
    {
        return 0;
    }
    else
    {
        return moyenne / compteur;
    }
}

double Capteur::calculMoyenneMoment(string date, TypeMesure * type)
{
    double moyenne = 0;
    double compteur = 0;
    //ATTENTION !!! ON NE PEUT PAS COMPARER DES DATES EN ETANT DES STRING.... FAUT SE DEMERDER AUSSI
    map<string, map<string, Mesure*>>::iterator ite1;

    map<string, Mesure*>::iterator ite2;

    ite1 = listeMesures.find(type->getId());

    if (ite1 != listeMesures.end())
    {
        for (ite2 = ite1->second.begin(); ite2 != ite1->second.end(); ite2++)
        {   
            if (ite2->first.substr(11,2) >= date.substr(11,2)&& stoi(ite2->first.substr(11,2)) < (stoi(date.substr(11,2))+1)) //il faut ajouter une marge d'une heure 
            {
                moyenne = moyenne + ite2->second->getValue();
                compteur++;
            }
        }
    }
    if (compteur == 0)
    {
        return 0;
    }
    else
    {
        return moyenne / compteur;
    }
}

string Capteur::getId()
{
    return id;
}

string Capteur::toString(){
	
    int compteur = 1;
    string fonctionnement;
    if(etat != 0){
        fonctionnement = "fonctionne";
    }else{
        fonctionnement = "malfonctionnant";
    }
    string texte = "Capteur: id= "+id+", "+fonctionnement+", "+ description+", "+ position.toString()+"\n"+"     Mesures: \n";
    
    map<string, map<string, Mesure*>>::iterator ite;
    map<string,Mesure*>::iterator ite2;

    for(ite=listeMesures.begin();ite!=listeMesures.end();ite++){
        for(ite2=ite->second.begin();ite2!=ite->second.end();ite2++)
        {
            texte += "     "+to_string(compteur)+"- "+ite2->second->toString();
            compteur++;
        }
    }
    
    return texte;
}

bool Capteur::getEtat()
{
    return etat;
}

void Capteur::setEtat(bool fonctionne)
{
    etat = fonctionne;
}

Point Capteur::getPosition()
{
    return position;
}
string Capteur::getDescription()
{
    return description;
}

double Capteur::getDistance(Capteur* capteur)
{
    return sqrt(pow(position.getLatitude()-capteur->getPosition().getLatitude(),2)+pow(position.getLongitude()-capteur->getPosition().getLongitude(),2));
}
//------------------------------------------------- Surcharge d'opérateurs
Capteur &Capteur::operator=(Capteur &unCapteur)
// Algorithme :
//
{
    id = unCapteur.id;
    etat = true; //on suppose qu'il fonctionne
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

Capteur::Capteur(string ide, string desc, double lon, double lat) : position(lat, lon)
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de <Capteur>" << endl;
#endif

    id = ide;
    etat = true; // on suppose qu'il fonctionne
    description = desc;
} //----- Fin de Capteur

Capteur::~Capteur()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Capteur>" << endl;
#endif
    map<string, map<string, Mesure*>>::iterator ite1;

    map<string, Mesure*>::iterator ite2;

    for(ite1 = listeMesures.begin();ite1!= listeMesures.end();ite1++)
    {
        for(ite2 = ite1->second.begin();ite2!=ite1->second.end();ite2++){
            delete ite2->second;
        }
    }
} //----- Fin de ~Capteur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
