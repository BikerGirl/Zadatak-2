#include <iostream>
using namespace std;
#define SEPARATOR "--------------------------"

//#include "stog_polje.h"
#include "stog_pokazivac.h"

void ispisi_auto(element x){
  cout <<" Serijski broj: "<<x.sbroj<<endl;
  cout <<"    Proizvodac: "<<x.proizvodjac<<endl;
  cout <<"         Model: "<<x.model<<endl;
  cout <<"        Godina: "<<x.godina<<endl;
}

void unesi_auto(stack *S, int sbroj, char* proizvodjac, char* model, int godina){
  element x;
  
  x.sbroj=sbroj;
  x.godina=godina;
  int i;
  strcpy((char*) &(x.proizvodjac), (char*) proizvodjac);
  strcpy((char*) &(x.model), (char*) model);
  
  PushS(x, S);
}

void unesi_sve_aute(stack *S){
  //Unesite pet različitih marki automobila
  //i za svaku marku tri različita modela.
  //Godišta automobila trebaju biti u rasponu
  //od 1995 do 2010. godine.

  //AUDI
  unesi_auto(S, 11111555, "Audi", "A3", 1996);
  unesi_auto(S, 11111566, "Audi", "A4", 2000);
  unesi_auto(S, 11111577, "Audi", "A5", 2010);

  //MERCEDES-BENZ
  unesi_auto(S, 11111655, "Mercedes", "A klasa", 2001);
  unesi_auto(S, 11111666, "Mercedes", "C klasa", 2009);
  unesi_auto(S, 11111677, "Mercedes", "SL", 1998);
  
  //PEUGEOT
  unesi_auto(S, 11111755, "Peugeot", "306", 1997);
  unesi_auto(S, 11111766, "Peugeot", "307", 1999);
  unesi_auto(S, 11111777, "Peugeot", "406", 2005);
  
  //CITROEN
  unesi_auto(S, 11111855, "Citroen", "C3", 2004);
  unesi_auto(S, 11111866, "Citroen", "C4", 2008);
  unesi_auto(S, 11111877, "Citroen", "C5", 2007);
  
  //MAZDA
  unesi_auto(S, 11111755, "Mazda", "323", 1997);
  unesi_auto(S, 11111766, "Mazda", "3", 1999);
  unesi_auto(S, 11111777, "Mazda", "RX-8", 2005);
};

void ispisi_sve(stack *S){
  element x;

  x=TopS(S);
  ispisi_auto(x);
  cout <<SEPARATOR<<endl;
  PopS(S);
  if(!IsEmptyS(S))
    ispisi_sve(S);
  PushS(x,S);
}

void ispisi_prva_kuca(stack *S1, stack *S2){
  element x;
  //Vađenje sa stoga i ispisivanje, spremanje na drugi stog
  while(!IsEmptyS(S1)){
    x=TopS(S1);
    if(x.godina >= 2006 && strcmp((char*) &(x.proizvodjac), "Audi")){
      ispisi_auto(x);
      cout <<SEPARATOR<<endl;
    }
    PopS(S1);
    PushS(x,S2);
  }
  //Vraćanje iz drugog stoga u prvi stog kako bi se očuvao poredak
  while(!IsEmptyS(S2)){
    x=TopS(S2);
    PopS(S2);
    PushS(x,S1);
  }
}

void ispisi_druga_kuca(stack *S){
  element x;

  x=TopS(S);
  if(!strcmp((char*) &(x.proizvodjac), "Audi")){
    ispisi_auto(x);
    cout <<SEPARATOR<<endl;
  }
  PopS(S);
  if(!IsEmptyS(S))
    ispisi_druga_kuca(S);
  PushS(x,S);
}

int main(){
  int i, broj;
  char izbor;
  stack *Auti1=InitS();
  stack *Auti2=InitS();
  
  unesi_sve_aute(Auti1);
    
  cout <<"Program za primjer rada sa stogom.\nAuti su vec upisani u program pa se ne moraju unositi rucno.\n";
  cout <<"U program su uneseni auti 5 proizvodjaca:\nAudi, Mercedes, Peugeot, Citroen i Mazda.\n"; 
  cout <<"Za svakog proizvodjaca auta unesena su po tri razlicita modela.\n";
  cout <<"Za ispis svih auta u stogu odaberite opciju 3 iz izbornika.\n";
  cout <<"(Auti ce biti ispisani orbnutim redoslijedom od onog kojim su uneseni u stog -\nLIFO princip)\n";
  system("pause");
  system("cls");
    
    
  do{  
    cout <<"Izbornik"<<endl;
    cout <<"\t1) Ispis auta iz prve auto-kuce (uz upotrebu pomocnog stoga)"<<endl;
    cout <<"\t2) Ispis auta iz druga auto-kuce (uz pomoc rekurzije)"<<endl;
    cout <<"\t3) Ispis svih auta sa stoga (stanje stoga)"<<endl;
    cout <<"\tq) Izlaz iz programa"<<endl;
    cout <<"Vas izbor: ";
    cin >>izbor;
    system("cls");
    
    switch(izbor){
      case '1':
        cout <<SEPARATOR<<endl;
        ispisi_prva_kuca(Auti1, Auti2);
        break;
      case '2':
        cout <<SEPARATOR<<endl;
        ispisi_druga_kuca(Auti1);
        break;
      case '3':
        cout <<SEPARATOR<<endl;
        ispisi_sve(Auti1);
        break;
      case 'q':
      case 'Q':
        cout <<"Bye bye!"<<endl;
        break;
      default:
        cout <<"Krivi izbor!"<<endl;
    }
    system("pause");
    system("cls");
  }while(izbor!='q' && izbor !='Q');
  return 0;
}

