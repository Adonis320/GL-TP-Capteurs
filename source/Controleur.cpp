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
#include "Controleur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Controleur::initTypeMesure(string nomFichier)
{
    lecteur.setFlux(nomFichier);
    int compteur = 0;

    while (!lecteur.eof())
    {
        TypeMesure *type2 = lecteur.getTypeMesure();
        if (type2 != NULL && lecteur.good())
        {
            listeTypeMesures->insert(pair<string, TypeMesure *>(type2->getId(), type2));
            compteur++;   
        }
       // delete type;
    }
    //cout << "nb de types de mesures ajoutes = " + to_string(compteur) << endl;
    lecteur.closeFlux();
}

string Controleur::lireTypeMesures()
{
    map<string, TypeMesure *>::iterator ite;
    string texte = "";
    int compteur = 1;
    for (ite = listeTypeMesures->begin(); ite != listeTypeMesures->end(); ite++)
    {
        texte += to_string(compteur) + "- " + ite->second->toString();
        compteur++;
    }

    return texte;
}

string Controleur::lireListeCapteurs()
{
    map<string, Capteur *>::iterator ite;
    string texte = "";
    int compteur = 1;
    for (ite = listeCapteurs->begin(); ite != listeCapteurs->end(); ite++)
    {
        texte += to_string(compteur) + "- " + ite->second->toString();
        compteur++;
    }
    return texte;
}

string Controleur::lireListeCapteursMalfonctionnant()
{
    map<string, Capteur *>::iterator ite;
    string texte = "";
    for (ite = listeCapteurs->begin(); ite != listeCapteurs->end(); ite++)
    {
        if (!ite->second->getEtat())
        {
            texte += ite->second->toString();
        }
    }
    return texte;
}

void Controleur::getCapteurRegion(Point p1, Point p2, string nomFichier)
{
    lecteur.setFlux(nomFichier);
    int compteur1 = 0;
    int compteur2 = 0;
    while (!lecteur.eof() && lecteur.good())
    {

        Capteur *capteur = lecteur.getCapteurParRegion(p1, p2);
        compteur1++;
        if (capteur != NULL && lecteur.good())
        {
            listeCapteurs->insert(make_pair(capteur->getId(), capteur));
            compteur2++;
        }
    }
    // cout << "nb total Capteurs = " + to_string(compteur1) << endl;
    // cout << "nb capteurs ajoutes = " + to_string(compteur2) << endl;
    lecteur.closeFlux();
}

void Controleur::methode2(string date1,string date2)
{
    lecteur.setFlux("data_10sensors_1year.csv");
    lecteur.getMesureMethode2(listeCapteurs,listeTypeMesures,date1,date2);
}

string Controleur::calculMoyenneSurPeriode(string date1, string date2)
{
    map<string, Capteur *>::iterator ite;
    map<string, TypeMesure *>::iterator ite2;
    // ite2 = listeTypeMesures.find(type);

    double compteurCapteur = 0;
    double moyenne = 0;
    double valeur = 0;
    string texte = "";
    for (ite2 = listeTypeMesures->begin(); ite2 != listeTypeMesures->end(); ite2++)
    {
        moyenne = 0;
        compteurCapteur = 0;
        for (ite = listeCapteurs->begin(); ite != listeCapteurs->end(); ite++)
        {
            valeur = ite->second->calculMoyennePeriode(date1, date2, ite2->second);
            if (valeur != 0)
            {
                compteurCapteur++;
                moyenne += valeur;
            }
        }
        if (compteurCapteur == 0)
        {
            moyenne = 0;
        }
        else
        {
            moyenne /= compteurCapteur;
        }
        texte += "Moyenne de " + ite2->second->getId() + " sur la periode: " + date1 + " a " + date2 + " = " + to_string(moyenne) + " " + ite2->second->getUnite() + "\n";
    }

    return texte;
}

string Controleur::calculMoyenneSurPeriode(string type, string date1, string date2)
{
    map<string, Capteur *>::iterator ite;
    map<string, TypeMesure *>::iterator ite2;
    ite2 = listeTypeMesures->find(type);

    double compteurCapteur = 0;
    double moyenne = 0;
    double valeur = 0;

    for (ite = listeCapteurs->begin(); ite != listeCapteurs->end(); ite++)
    {
        valeur = ite->second->calculMoyennePeriode(date1, date2, ite2->second);
        if (valeur != 0)
        {
            compteurCapteur++;
        }
        moyenne += valeur;
    }

    if (compteurCapteur == 0)
    {
        moyenne = 0;
    }
    else
    {
        moyenne /= compteurCapteur;
    }

    return ("Moyenne de " + type + " sur la periode: " + date1 + " a " + date2 + " = " + to_string(moyenne) + " " + ite2->second->getUnite());
}

string Controleur::calculMoyenneMoment(string date)
{
    map<string, Capteur *>::iterator ite;
    map<string, TypeMesure *>::iterator ite2;
    // ite2 = listeTypeMesures.find(type);

    double compteurCapteur = 0;
    double moyenne = 0;
    double valeur = 0;
    string texte = "";
    for (ite2 = listeTypeMesures->begin(); ite2 != listeTypeMesures->end(); ite2++)
    {
        moyenne = 0;
        compteurCapteur = 0;
        for (ite = listeCapteurs->begin(); ite != listeCapteurs->end(); ite++)
        {
            valeur = ite->second->calculMoyenneMoment(date, ite2->second);
            if (valeur != 0)
            {
                compteurCapteur++;
            }
            moyenne += valeur;
        }
        if (compteurCapteur == 0)
        {
            moyenne = 0;
        }
        else
        {
            moyenne /= compteurCapteur;
        }
        texte += "Moyenne de " + ite2->second->getId() + " a " + date + " = " + to_string(moyenne) + " " + ite2->second->getUnite() + "\n";
    }

    return texte;
}

string Controleur::calculMoyenneMoment(string type, string date1)
{
    map<string, Capteur *>::iterator ite;
    map<string, TypeMesure *>::iterator ite2;
    ite2 = listeTypeMesures->find(type);

    double compteurCapteur = 0;
    double moyenne = 0;
    double valeur = 0;

    for (ite = listeCapteurs->begin(); ite != listeCapteurs->end(); ite++)
    {
        valeur = ite->second->getMesure(date1, ite2->second);
        if (valeur != 0)
        {
            compteurCapteur++;
        }
        moyenne += valeur;
    }

    if (compteurCapteur == 0)
    {
        moyenne = 0;
    }
    else
    {
        moyenne /= compteurCapteur;
    }

    return ("Moyenne de " + type + " a " + date1 + " = " + to_string(moyenne) + " " + ite2->second->getUnite());
}

string Controleur::getAllMesure(string dateDebut, string dateFin)
{
    lecteur.setFlux("data_10sensors_1year.csv");
   // int con = 0;
    string trash;
    getline(lecteur.flux, trash);
    /*while (con < 12)
    {
        con++;
        getline(lecteur.flux, trash);
    }*/
    // lecteur.setFlux("data_10test.csv");
    map<string, Capteur *>::iterator ite;
    map<string, TypeMesure *>::iterator ite2;
    string texte = "";
    int cpt = 0;
    for (ite = listeCapteurs->begin(); ite != listeCapteurs->end(); ite++)
    {
        for (ite2 = listeTypeMesures->begin(); ite2 != listeTypeMesures->end(); ite2++)
        {
            // cout << ite2->second->getId() +ite->second->getId()<< endl;

            while (!lecteur.eof())
            {
                cpt++;
                Mesure *mesure = lecteur.getMesure(ite->second->getId(), ite2->second, dateDebut, dateFin);
                if (!lecteur.good())
                {
                    cout << cpt << endl;
                    cout << "gros pb" << endl;
                    break;
                }
                if (mesure != NULL)
                {
                    ite->second->ajouterMesure(mesure);
                    texte += mesure->toString();
                    //cout<<"hello"<<endl;
                }
                /*else if (lecteur.eof())
                {
                    lecteur.flux.clear();
                    lecteur.flux.seekg(0, ios::beg);
                    getline(lecteur.flux,trash);
                    cout<<trash<<endl;*/
                   /* int con = 0;
                    string trash;
                    while (con < 12)
                    {
                        con++;
                        getline(lecteur.flux, trash);
                    }*/
                //}

                //cout<<cpt<<endl;
                
            }
            //cout<<ite->second->getId()+" "+ite2->first<<endl;
           // if (lecteur.eof())
            //{
                lecteur.flux.clear();
                lecteur.flux.seekg(0, ios::beg);
                int con = 0;
                string trash;
                //while (con < 12)
                //{
                   // con++;
                    getline(lecteur.flux, trash);
                //}
           // }
            cpt = 0;
        }
    }
    lecteur.closeFlux();
    return texte;
}

string Controleur::getMesure(string type, string dateDebut, string dateFin)
{
    //lecteur.setFlux("data_10sensors_1year.csv");
    lecteur.setFlux("data_test.txt");
    map<string, Capteur *>::iterator ite;
    map<string, TypeMesure *>::iterator ite2;
    ite2 = listeTypeMesures->find(type);
    string texte = "";
    for (ite = listeCapteurs->begin(); ite != listeCapteurs->end(); ite++)
    {
        while (!lecteur.eof() && lecteur.good())
        {
            Mesure *mesure = lecteur.getMesure(ite->second->getId(), ite2->second, dateDebut, dateFin);
            if (mesure != NULL)
            {
                ite->second->ajouterMesure(mesure);
                texte += mesure->toString();
            }
        }
    }
    return texte;
}

string Controleur::getMoyenne(string capteurID, string dateDebut, string dateFin)
{
    map<string, Capteur *>::iterator ite;
    map<string, TypeMesure *>::iterator ite2;
    string texte = "";
    double moyenne = 0;

    for (ite2 = listeTypeMesures->begin(); ite2 != listeTypeMesures->end(); ite2++)
    {
        moyenne = 0;
        for (ite = listeCapteurs->begin(); ite != listeCapteurs->end(); ite++)
        {
            if (ite->second->getId().compare(capteurID) == 0)
            {
                if (dateDebut.compare(dateFin) == 0)
                {
                    moyenne = ite->second->calculMoyenneMoment(dateDebut, ite2->second);
                }
                else
                {
                    moyenne = ite->second->calculMoyennePeriode(dateDebut, dateFin, ite2->second);
                }
            }
        }
        texte += "Moyenne de " + ite2->first + "sur le capteur " + capteurID + " a " + dateDebut + " jusqu'a " + dateFin + " = " + to_string(moyenne) + " " + ite2->second->getUnite() + "/n";
    }

    return texte;
}

void Controleur::changerZoneCapteurs()
{
    map<string, Capteur *>::iterator ite;
    for (ite = listeCapteurs->begin(); ite != listeCapteurs->end(); ite++)
    {
        delete ite->second;
    }
    listeCapteurs->clear();
}

void Controleur::verifierCapteur(string date1, string date2)
{
    //TODO REMTETTRE A JOUR
    map<string, Capteur *>::iterator ite;
    map<string, Capteur *>::iterator ite2;
    map<string, TypeMesure *>::iterator ite3;

    double moyenneCapteur = 0;
    double moyenneAutres = 0;
    double moyenneCapteurAutre = 0;
    double compteurCapteurs = 0;
    double erreurMoyenne = 0;
    double compteurMoyennes = 0;

    for (ite = listeCapteurs->begin(); ite != listeCapteurs->end(); ite++)
    {
        compteurMoyennes = 0;
        erreurMoyenne = 0;
        for (ite3 = listeTypeMesures->begin(); ite3 != listeTypeMesures->end(); ite3++)
        {
            compteurCapteurs = 0;
            moyenneAutres = 0;
            moyenneCapteur = ite->second->calculMoyennePeriode(date1, date2, ite3->second);
            //if (moyenneCapteur != 0)
            //{
            for (ite2 = listeCapteurs->begin(); ite2 != listeCapteurs->end(); ite2++)
            {
                if (ite2->first.compare(ite->first) != 0)
                {
                    if (ite->second->getDistance(ite2->second) < 1)
                    {
                        moyenneCapteurAutre = ite2->second->calculMoyennePeriode(date1, date2, ite3->second);
                        if (moyenneCapteurAutre != 0)
                        {
                            compteurCapteurs++;
                            moyenneAutres += moyenneCapteurAutre;
                        }
                    }
                }
            }
            moyenneAutres /= compteurCapteurs;
            erreurMoyenne += abs(abs(moyenneCapteur) - abs(moyenneAutres)) / abs(moyenneAutres);
            compteurMoyennes++;

            // }
        }
        erreurMoyenne /= compteurMoyennes;
        if (erreurMoyenne > 0.15)
        {
            ite->second->setEtat(false);
        }
    }
}
//------------------------------------------------- Surcharge d'opérateurs
/*Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :
//
{
} //----- Fin de operator =
*/

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

Controleur::Controleur()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Xxx>" << endl;
#endif
    listeCapteurs = new map<string,Capteur*>();
    listeTypeMesures = new map<string,TypeMesure*>();
} //----- Fin de Xxx

Controleur::~Controleur()
// Algorithme :
//
{
    map<string, Capteur *>::iterator ite;
    for (ite = listeCapteurs->begin(); ite != listeCapteurs->end(); ite++)
    {
        delete ite->second;
    }
    delete listeCapteurs;
    map<string, TypeMesure *>::iterator ite2;
    for (ite2 = listeTypeMesures->begin(); ite2 != listeTypeMesures->end(); ite2++)
    {
        delete ite2->second;
    }
    delete listeTypeMesures;

#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Xxx

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
