/*************************************************************************
Xxx  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <LecteurFichier> (fichier LecteurFichier.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "LecteurFichier.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
Capteur *LecteurFichier::getCapteurParRegion(Point point1, Point point2)
//Algorithme :
//
{
	string lat, longi, id, desc;
	long double lati, longit;
	Capteur *capteur;
	getline(flux, id);
	getline(flux, id, ';');
	getline(flux, lat, ';');
	getline(flux, longi, ';');
	getline(flux, desc, ';');
	if (longi != "" && lat != "")
	{
		lati = stold(lat);
		longit = stold(longi);
	}
	else
	{
		return NULL;
	}
	if (((lati < point1.getLatitude()) && (lati > point2.getLatitude())) || ((lati < (point2.getLatitude())) && (lati > (point1.getLatitude()))))
	{
		if (((longit < point1.getLongitude()) && (longit > point2.getLongitude())) || ((longit < (point2.getLongitude())) && (longit > (point1.getLongitude()))))
		{

			capteur = new Capteur(id, desc, longit, lati);
		}
		else
		{
			capteur = NULL;
		}
	}
	else
	{
		capteur = NULL;
	}
	return capteur;
} //----- Fin de getCapteurParRegion
/*
Mesure* LecteurFichier::getMesure(string capteurId, TypeMesure* type, string dateDebut, string dateFin)
//Algorithme :
//
{
        Mesure* mesure;
        string timestamp,sensorId,attributeId,value,trash,comp,date,value8;
        string sensId = "";
        string typeId = "";
        double valeur;
        size_t pos; 
		int cpt = 0;       
        while(cpt<12)
		{
			cpt++;
			getline(flux,timestamp);
		}
		getline(flux,timestamp,';');
		if(good()){	
			pos=timestamp.find('T');
			timestamp.replace(pos,1,1,' ');
			for(char& c : timestamp) {
				if(c!='\n' && (int)c!=0 && (int)c!=13){	
						date.append(1,c);
				}
		}
        if(date<dateFin && date>dateDebut)
        {
				getline(flux,sensorId,';');
				for(char& c : sensorId) {
					if(c!='\n' && (int)c!=0 && (int)c!=13){        
								sensId.append(1,c);
					}
				}
                getline(flux,attributeId,';');
                for(char& c : attributeId) {
                        if(c!='\n' && (int)c!=0 && (int)c!=13){        
                            typeId.append(1,c);
                        }
                }
                if(type->getId()==typeId)
                {
                        getline(flux,value,';');
						for(char& c : value) {
							//cout<<(int)c<<endl;
							if(int(c)!=0)
							{
								value8.append(1,c);
							}
						}
                        if(value8!="" && (sensId == capteurId))
                        {
                                valeur = stod(value8);
                                mesure = new Mesure(valeur,date,type,sensId);
                                return mesure;
                        }else
                        {
                                return NULL;
                        }                
                }else
                {
                        return NULL;
                }
        }else
        {
                return NULL;
        }
	}else
	{
		return NULL;
	}
}*/

/*Mesure *LecteurFichier::getMesure(string capteurId, TypeMesure *type, string dateDebut, string dateFin)
//Algorithme :
//
{
	Mesure *mesure;
	string timestamp, sensorId, attributeId, value, trash, comp, date, value8, sensId, typeId;
	double valeur;
	int cpt = 0;
	size_t pos;
	while (cpt < 12)
	{
		cpt++;
		getline(flux, timestamp);
	}
	getline(flux, timestamp, ';');
//	cout << "loool" << endl;
	if (!eof())
	{
		pos = timestamp.find('T');
		timestamp.replace(pos, 1, 1, ' ');
		sensId = "";
		typeId = "";
		date = "";
		for (char &c : timestamp)
		{
			if (c != '\n' && (int)c != 0 && (int)c != 13)
			{
				date.append(1, c);
			}
		}
		if (date < dateFin && date >= dateDebut)
		{
		//	cout<<"hi ado"<<endl;
			getline(flux, sensorId, ';');
			cout << sensorId << endl;
			getline(flux, attributeId, ';');
			for (char &c : sensorId)
			{
				if (c != '\n' && (int)c != 0 && (int)c != 13)
				{
					sensId.append(1, c);
					//cout<<(int) c<<endl;
				}
			}
			for (char &c : attributeId)
			{
				if (c != '\n' && (int)c != 0 && (int)c != 13)
				{
					typeId.append(1, c);
					//cout<<"du fichier"<<endl<<(int) c<<endl;
				}
			}
			/*for(char& c:type->getUnite()){
			cout<<"rentre en parametre"<<endl;
			cout<<type->getId()<<endl;
			cout<<(int) c<<endl;
		}
		//cout << type->getId()<<endl;
	//	cout << typeId << endl;
	//	cout << type->getId().compare(typeId)<<endl;
			if (type->getId().compare(typeId)==0 && capteurId.compare(sensId)==0)
			{
			//	cout<<"ok"<<endl;
				getline(flux, value, ';');
				for (char &c : value)
				{
					//cout<<(int)c<<endl;
					if (int(c) != 0)
					{
						value8.append(1, c);
					}
				}
				//cout << "valeur "+value<<endl;
				if (value != "")
				{
					valeur = stod(value8);
					//cout << value.substr(1,value.length()-1)<< endl;
					//cout << valeur << endl;
					mesure = new Mesure(valeur, date, type, sensorId);
					//mesure = new Mesure(valeur,timestamp,type,sensorId);
					return mesure;
				}
				else
				{
					return NULL;
				}
			}
			else
			{
				return NULL;
			}
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
} //----- Fin de getMesure
*/

void LecteurFichier::getMesureMethode2(map<string, Capteur *> *mapCapteur, map<string, TypeMesure *> *mapType, string dateDebut, string dateFin)
{
	string timestamp, sensorId, attributeId, value, trash, comp, date, value8, sensId, typeId;
	getline(flux, trash);
	double valeur;
	size_t pos;

	map<string, Capteur *>::iterator itCap;
	map<string, TypeMesure *>::iterator itType;

	while (!eof())
	{
		getline(flux, timestamp, ';');
		if (good())
		{
			pos = timestamp.find('T');
			timestamp.replace(pos, 1, 1, ' ');
			sensId = "";
			typeId = "";
			date = "";
			value8 = "";
			for (char &c : timestamp)
			{
				if (c != '\n' && (int)c != 0 && (int)c != 13)
				{
					date.append(1, c);
				}
			}
			if (date < dateFin && date >= dateDebut)
			{
				getline(flux, sensorId, ';');
				getline(flux, attributeId, ';');
				for (char &c : sensorId)
				{
					if (c != '\n' && (int)c != 0 && (int)c != 13)
					{
						sensId.append(1, c);
					}
				}
				for (char &c : attributeId)
				{
					if (c != '\n' && (int)c != 0 && (int)c != 13)
					{
						typeId.append(1, c);
					}
				}
				itCap = mapCapteur->find(sensId);
				itType = mapType->find(typeId);

				if (itCap != mapCapteur->end() && itType != mapType->end())
				{
					
					getline(flux, value, ';');
					for (char &c : value)
					{
						if (int(c) != 0)
						{
							value8.append(1, c);
						}
					}
					if (value8 != "")
					{
						valeur = stod(value8);
						
						Mesure *mesure = new Mesure(valeur, date, itType->second, sensorId);
						
						itCap->second->ajouterMesure(mesure);
						
					}else{
						getline(flux,trash);
					}
				}else{
					cout << "hello" << endl;
					getline(flux,trash);
				}
			}
			else
			{
				getline(flux, trash);
			}
		}
		else
		{
			getline(flux,trash);
			break;
		}
	}
	flux.close();
}

Mesure *LecteurFichier::getMesure(string capteurId, TypeMesure *type, string dateDebut, string dateFin)
{
	Mesure *mesure;
	string timestamp, sensorId, attributeId, value, trash, comp, date, value8, sensId, typeId;
	double valeur;
	int cpt = 0;
	size_t pos;
	getline(flux, timestamp, ';');
	//cout<<timestamp<<endl;
	if (good())
	{
		pos = timestamp.find('T');
		timestamp.replace(pos, 1, 1, ' ');
		sensId = "";
		typeId = "";
		date = "";
		for (char &c : timestamp)
		{
			if (c != '\n' && (int)c != 0 && (int)c != 13)
			{
				date.append(1, c);
			}
		}
		//cout<<date<<endl;
		if (date < dateFin && date >= dateDebut)
		{
			//cout << "tout est bien" << endl;
			getline(flux, sensorId, ';');
			//cout << sensorId << endl;
			getline(flux, attributeId, ';');
			//cout << attributeId << endl;
			for (char &c : sensorId)
			{
				if (c != '\n' && (int)c != 0 && (int)c != 13)
				{
					sensId.append(1, c);
					//cout<<(int) c<<endl;
				}
			}
			for (char &c : attributeId)
			{
				if (c != '\n' && (int)c != 0 && (int)c != 13)
				{
					typeId.append(1, c);
					//cout<<"du fichier"<<endl<<(int) c<<endl;
				}
			}
			/*cout << capteurId.compare(sensId) << endl;
			cout << type->getId() << endl;
			cout << type->getId().compare(typeId) << endl;*/
			if (type->getId().compare(typeId) == 0 && capteurId.compare(sensId) == 0)
			{
				//	cout<<"hi"<<endl;
				getline(flux, value, ';');
				for (char &c : value)
				{
					//cout<<(int)c<<endl;
					if (int(c) != 0)
					{
						value8.append(1, c);
					}
				}
				//cout << value8 << endl;
				if (value != "")
				{
					valeur = stod(value8);
					//cout << value.substr(1,value.length()-1)<< endl;
					//cout << valeur << endl;
					mesure = new Mesure(valeur, date, type, sensorId);
					//mesure = new Mesure(valeur,timestamp,type,sensorId);
					return mesure;
				}
				else
				{
					return NULL;
				}
			}
			else
			{
				getline(flux, trash);
				return NULL;
			}
		}
		else
		{
			getline(flux, trash);
			cout << "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd" << endl;
			return NULL;
		}
	}
	getline(flux, trash);
	//getline(flux,timestamp);
	//cout <<timestamp <<endl;
	//return NULL;
}

TypeMesure *LecteurFichier::getTypeMesure()
//Algorithme :
//
{
	string unite;
	string description;
	string id;
	TypeMesure *type;
	getline(flux, id);
	getline(flux, id, ';');
	getline(flux, unite, ';');
	getline(flux, description, ';');
	type = new TypeMesure(unite, description, id);
	//cout << "id = " + id<< endl;
	//delete type;
	return type;
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

bool LecteurFichier::good()
//Algorithme :
//
{
	return flux.good();
} //----- Fin de fail

void LecteurFichier::setFlux(string nomFichier)
//Algorithme :
//
{
	flux.open(nomFichier);
} //----- Fin de setFlux

void LecteurFichier::closeFlux()
{
	flux.close();
}

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

//----------------------------------------------------- M�thodes prot�g�es
