#include <iostream>
#include "wypisanie_listy_pracownikow.hh"
#include "baza_pracownikow.hh"

void Wypisanie_Listy_Pracownikow::wykonaj() {
    for (int i = 0; i != Baza_Danych_Pracownikow::Pracownik.size(); i++) {
        cout<<"ID: "<<Baza_Danych_Pracownikow::Pracownik[i].id<<"\tHaslo: "<<Baza_Danych_Pracownikow::Pracownik[i].haslo<<"\tWskaznik zadowolenia: "<<Baza_Danych_Pracownikow::Pracownik[i].zadowolenie/Baza_Danych_Pracownikow::Pracownik[i].liczba_klientow<<"\tLiczba obsluzonych klientow: "<<Baza_Danych_Pracownikow::Pracownik[i].liczba_klientow<<endl;
    }
    cout << "Koniec bazy danych poracownikow"<<endl;
}
