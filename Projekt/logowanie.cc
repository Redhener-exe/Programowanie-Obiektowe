#include <iostream>

using namespace std;


#include "logowanie.hh"
#include "zalogowany.hh"
#include "baza_pracownikow.hh"

bool Logowanie::poprawne_logowanie(int id,string haslo){
    if(Baza_Danych_Pracownikow::Pracownik[id].haslo==haslo){
        return true;
    }
    else{
        return false;
    }
}

void Logowanie::wykonaj() {
    int id_uzytkownika;
    string haslo;
    do{
        cout<<"Logowanie"<<endl;
        cout<<"_____________________"<<endl;
        cout<<"Podaj id uzytkownika: ";
        cin>>id_uzytkownika;
        cout<<"Podaj haslo: ";
        cin>>haslo;
        if(!Logowanie::poprawne_logowanie(id_uzytkownika,haslo)){
            cout<<"Nieprawidlowe dane"<<endl;
        }
    }while(!Logowanie::poprawne_logowanie(id_uzytkownika,haslo));
    ZalogowanyPracownik::Logged_in.push_back({id_uzytkownika});
}
    
