#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "wczytywanie_klientow.hh"
#include "baza_klientow.hh"

void WczytywanieKlientow::wykonaj() {
    int id;
    string imie;
    string nazwisko;
    string pesel;
    bool ubezpiecza_samochod=false;
    bool ubezpiecza_dom=false;
    int temp;

    string wejscie;
    ifstream in("Baza danych klientow.txt");
    Baza_Danych_Klientow::Klient.clear();
    while (std::getline(in, wejscie)) {
        stringstream ss(wejscie);
        getline(ss,imie,' ');
        getline(ss,nazwisko,' ');
        getline(ss,pesel,' ');
        ss>>id;
        ss>>temp;
        if(temp==1){
            ubezpiecza_samochod=true;
        }
        ss>>temp;
        if(temp==1){
            ubezpiecza_dom=true;
        }
        Baza_Danych_Klientow::Klient.push_back({id,imie,nazwisko,pesel,ubezpiecza_samochod,ubezpiecza_dom});
    }
    in.close();
    cout << "Baza danych zaladowana"<<endl;
    
}