#include "LecteurFichier.h"
#include "Capteur.h"
#include "Controleur.h"
#include "Point.h"
#include <iostream>
#include <cstring>
using namespace std;
int main()
{   
    Controleur* controleur = new Controleur();

    /*Point p1 (-9,-37);
    Point p2 (-7,-30);*/

	Point p1 (-400,-400);
	Point p2 (400,400);

  	controleur->initTypeMesure("AttributeType.csv");
    //controleur->getCapteurRegion(p1,p2,"Sensors.csv");

  

  
  
    cout << controleur->lireTypeMesures() << endl;

//	controleur->getAllMesure("2017-01-01 00:00:00.6090000","2017-01-01 01:01:00.6090000");



	

			//controleur->methode2("2017-01-01 00:00:00.6090000","2017-01-01 01:01:00.6090000");

	cout << controleur->lireListeCapteurs() << endl;
	//cout << controleur->calculMoyenneSurPeriode("2017-01-01 00:00:20.6090000","2017-01-01 00:00:50.6090000") << endl;
	//cout << controleur->lireListeCapteurs() << endl;
    
    delete controleur;

/*	LecteurFichier * l = new LecteurFichier();
  	TypeMesure * type1 = new TypeMesure("g/cm3","concentration d'oxygene","NO2");
	Capteur * capteur1 = new Capteur("Sensor0","un capteur",32.25,-8.65);  
	l->setFlux("data_10sensors_1year.csv");
	int cont = 0;
	while(!l->eof() && cont < 15)
	{
		l->getMesure(capteur1->getId(),type1,"2017-01-01 00:00:00.6090000","2017-01-01 01:01:00.6090000");
		cont++;
	}*/

    /*string date = "2017-01-01T00:01:20.6090000";
    cout<< date.substr(11,2) << endl;*/
    /*Capteur * capteur1 = new Capteur("Sensor0","un capteur",32.25,-8.65);
    TypeMesure * type1 = new TypeMesure("g/cm3","concentration d'oxygene","O2");
    TypeMesure * type2 = new TypeMesure("g/cm3","concentration d'n2o","N2O");

    Mesure * mesure1 = new Mesure(22.3,"2017-01-01T01:01:20.6090000",type1,"Sensor0");
    Mesure * mesure2 = new Mesure(23.3,"2017-01-01T01:01:22.6090000",type1,"Sensor0");
    Mesure * mesure3 = new Mesure(23.3,"2017-01-01T02:01:24.6090000",type1,"Sensor0");
    Mesure * mesure7 = new Mesure(23.3,"2017-01-01T03:01:24.6090000",type1,"Sensor0");

    Mesure * mesure4 = new Mesure(1,"2017-01-01T01:01:20.6090000",type2,"Sensor0");
    Mesure * mesure5 = new Mesure(2,"2017-01-01T01:01:22.6090000",type2,"Sensor0");
    Mesure * mesure6 = new Mesure(3,"2017-01-01T01:01:35.6090000",type2,"Sensor0");
    //cout<<mesure1->toString()<<endl;
    //cout<<type1->toString()<<endl;
    capteur1->ajouterMesure(mesure1);
    capteur1->ajouterMesure(mesure2);
    capteur1->ajouterMesure(mesure3);
    capteur1->ajouterMesure(mesure4);
    capteur1->ajouterMesure(mesure5);
    capteur1->ajouterMesure(mesure6);
    capteur1->ajouterMesure(mesure7);
    cout <<capteur1->toString()<<endl;

    double m = capteur1->calculMoyenneMoment("2017-01-01T01:01:20.6090000",type2);
    cout << to_string(m) << endl;

    double c = capteur1->calculMoyennePeriode("2017-01-01T01:01:20.6090000","2017-01-01T04:01:20.6090000",type1);
    cout << to_string(c) << endl;

    double f = capteur1->getMesure("2017-01-01T01:01:32.6090000",type2);
    cout << to_string(f) << endl;*/

    
	/*Lsubstr(11,2)ecteurFichier f;
	f.setFlux("Sensors.csv");
	string test;
	Capteur* t;
	Point p(100,100);
	Point p2(0,0);
	int cpt=0;		
	while(true)
	{
		t = f.getCapteurParRegion(p,p2);
		if(!f.good() && t==NULL){
			delete t;
			cout<<cpt<<endl;
			break;
		}
		if(t==NULL)
		{
		}else
		{
			cout<<(*t).toString();
			delete t;
		}
	}*/
	/*LecteurFichier f;
	f.setFlux("data_10sensors_1year.csv");
	string test;
	getline(f.flux,test);
	int cpt=0;
	while(true)
	{	
		getline(f.flux,test,'\n');
		cpt++;
		if(!f.good() && test=="")
			break;
		if(!f.good())
			break;
		cout<<test<<endl;
		
	}
	cout<<"nb: "<<cpt<<endl;*/
	return 0;
}