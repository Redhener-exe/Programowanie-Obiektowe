#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>
using namespace std;
#include "menedzer_komend.hh"
#include "baza_pracownikow.hh"
#include "baza_klientow.hh"

#include "cuk.hh"
#include "dodawanie_pracownika.hh"
#include "wypisanie_listy_pracownikow.hh"
#include "dodawanie_klienta.hh"
#include "wypisanie_listy_klientow.hh"
#include "help.hh"
#include "exit_command.hh"
#include "zapisywanie_pracownikow.hh"
#include "wczytywanie_pracownikow.hh"
#include "zapisywanie_klientow.hh"
#include "wczytywanie_klientow.hh"
#include "zalogowany.hh"
#include "wylogowanie.hh"
#include "logowanie.hh"


Menedzer_Komend::Menedzer_Komend() {
    komendy["Obliczanie premii"] = make_shared<Obliczanie_premii>();
    komendy["Dodaj pracownika"] = make_shared<Dodawanie_Pracownika>();
    komendy["Wypisz pracownikow"] = make_shared<Wypisanie_Listy_Pracownikow>();
    komendy["Dodaj klienta"] = make_shared<Dodawanie_Klienta>();
    komendy["Wypisz klientow"] = make_shared<Wypisanie_Listy_Klientow>();
    komendy["Zapisz pracownikow"] = make_shared<ZapisywaniePracownikow>();
    komendy["Wczytaj pracownikow"] = make_shared<WczytywaniePracownikow>();
    komendy["Zapisz klientow"] = make_shared<ZapisywanieKlientow>();
    komendy["Wczytaj klientow"] = make_shared<WczytywanieKlientow>();
    komendy["Wyloguj"] = make_shared<Wylogowanie>();
    komendy["Help"]=make_shared<Help>();
    komendy["Exit"] = make_shared<ExitCommand>();
    
}
bool poprawne_logowanie(int id,string haslo){
    if(Baza_Danych_Pracownikow::Pracownik[id].haslo==haslo){
        return true;
    }
    else{
        return false;
    }
}

void Menedzer_Komend::petla_rejestracji(){
    string odp;
    cout<<"Czy chcesz wczytac baze danych?(Tak/Nie): ";
    cin>>odp;
    if(odp=="Tak"){
        komendy["Wczytaj pracownikow"]->wykonaj();
        komendy["Wczytaj klientow"]->wykonaj();
        make_shared<Logowanie>()->wykonaj();
    }
    else{
    komendy["Dodaj pracownika"]->wykonaj();
    ZalogowanyPracownik::Logged_in.push_back({0});
    }
}

void Menedzer_Komend::petla() {
    string obecna_komenda;
    cout << ">";
    while (getline(cin, obecna_komenda)) {
        if (komendy.find(obecna_komenda) != komendy.end() ) {
            string odp;
            komendy[obecna_komenda]->wykonaj();
        }
        else if(obecna_komenda==""){
            cout<<">";
            continue;
        }
        else {
            cout << "Podano zla komende `" << obecna_komenda << "'"<<endl<<"Jezeli masz problem z komendami uzyj komendy Help"<<endl;
        }
        cout << "\n>";
    }
}