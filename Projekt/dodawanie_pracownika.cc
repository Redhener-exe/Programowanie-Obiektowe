#include <iostream>
#include <string>
#include <sstream>

#include "dodawanie_pracownika.hh"
#include "baza_pracownikow.hh"


using namespace std;


void Dodawanie_Pracownika::wykonaj() {

    int id=Baza_Danych_Pracownikow::Pracownik.size();
    string haslo;
    cout<<"Podaj haslo dla nowego pracownika: ";
    cin>>haslo;
    float zadowolenie=0;
    int liczba_klientow=0;
    float srednia_zadowolenia=0;
    float premia=0;
    Baza_Danych_Pracownikow::Pracownik.push_back({id,zadowolenie,liczba_klientow,srednia_zadowolenia,premia,haslo});
    cout << "Pracownik "<<id<<" dodany do bazy danych"<<endl;
}