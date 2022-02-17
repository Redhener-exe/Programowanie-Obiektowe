#include "cuk.hh"
#include "baza_pracownikow.hh"
#include "zalogowany.hh"

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void Obliczanie_premii::wykonaj()
{
    int premia=100;
    int id_pracownika=ZalogowanyPracownik::Logged_in[0].id;
    Baza_Danych_Pracownikow::Pracownik[id_pracownika].srednia_zadowolenia=Baza_Danych_Pracownikow::Pracownik[id_pracownika].zadowolenie / Baza_Danych_Pracownikow::Pracownik[id_pracownika].liczba_klientow;
    Baza_Danych_Pracownikow::Pracownik[id_pracownika].premia=premia*Baza_Danych_Pracownikow::Pracownik[id_pracownika].srednia_zadowolenia;
    cout<<"Premia dla pracownika "<<id_pracownika<<" wynosi: "<<Baza_Danych_Pracownikow::Pracownik[id_pracownika].premia<<" zl"<<endl;
}