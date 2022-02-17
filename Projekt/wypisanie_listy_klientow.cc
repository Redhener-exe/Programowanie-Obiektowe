#include <iostream>
#include "wypisanie_listy_klientow.hh"
#include "baza_klientow.hh"

void Wypisanie_Listy_Klientow::wykonaj() {
    for (int i = 0; i != Baza_Danych_Klientow::Klient.size(); i++) {
        cout<<"ID: "<<Baza_Danych_Klientow::Klient[i].id<<endl<<"Imie: "<<Baza_Danych_Klientow::Klient[i].imie<<endl<<"Nazwisko: "<<Baza_Danych_Klientow::Klient[i].nazwisko<<endl<<"Pesel: "<<Baza_Danych_Klientow::Klient[i].pesel<<endl;
        cout<<"Klient ubezpiecza: ";
        if(Baza_Danych_Klientow::Klient[i].ubezpiecza_samochod==true){
            cout<<"Samochod ";
        }
        if(Baza_Danych_Klientow::Klient[i].ubezpiecza_dom==true){
            cout<<"Dom ";
        }
        cout<<endl<<"_______________________________________________"<<endl;
    }
    cout << "Koniec bazy danych klientow"<<endl;
}
