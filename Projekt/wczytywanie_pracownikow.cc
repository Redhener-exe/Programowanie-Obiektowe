#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "wczytywanie_pracownikow.hh"
#include "baza_pracownikow.hh"

void WczytywaniePracownikow::wykonaj() {
    int id;
    float zadowolenie=0;
    int liczba_klientow=0;
    float srednia_zadowolenia=0;
    float premia;
    string haslo;

    string wejscie;
    ifstream in("Baza danych pracownikow.txt");
    Baza_Danych_Pracownikow::Pracownik.clear();
    while (std::getline(in, wejscie)) {
        stringstream ss(wejscie);
        getline(ss,haslo,' ');
        ss>>id;
        ss>>zadowolenie;
        ss>>liczba_klientow;
        ss>>srednia_zadowolenia;
        ss>>premia;
        
        Baza_Danych_Pracownikow::Pracownik.push_back({id,zadowolenie,liczba_klientow,srednia_zadowolenia,premia,haslo});
    }
    in.close();
    cout << "Baza danych zaladowana"<<endl;
    
}