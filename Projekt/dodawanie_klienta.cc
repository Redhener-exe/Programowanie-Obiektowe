#include <iostream>
#include <string>
#include <sstream>

#include "dodawanie_klienta.hh"
#include "baza_klientow.hh"
#include "baza_pracownikow.hh"
#include "baza_samochody.hh"
#include "baza_dom.hh"
#include "zalogowany.hh"

using namespace std;


void Dodawanie_Klienta::wykonaj() {

    int id=Baza_Danych_Klientow::Klient.size();
    string imie;
    string nazwisko;
    string pesel;
    string rodzaj_domu;
    bool ubezpiecza_samochod;
    bool ubezpiecza_dom;
    int rok_samochod;
    int rok_prawojazdy;
    int znizka;
    int znizka_dom;
    int rok = 2022;
    int podstawa = 1000;
    int podstawa_dom = 2000;
    int podstawa_mieszkanie = 1500;
    int kwota_samochod = 0;
    int kwota_dom = 0;
    int rok_budowy;
    int powierzchnia;

    cout<<"Podaj imie klienta: ";
    cin>>imie;

    cout<<"Podaj nazwisko klienta: ";
    cin>>nazwisko;

    cout<<"Podaj pesel klienta: ";
    cin>>pesel;

    //czy ubezpiecza samochód
    while (true)
    {
    string odp;
    cout<<"Czy klient chce ubezpieczyc samochod?(Tak/Nie) ";
    cin>>odp;
    if(odp=="Tak"){
        ubezpiecza_samochod=true;

        cout<<"Podaj rok rejestracji samochodu: ";
        cin>>rok_samochod;

        cout<<"Podaj rok otrzymania prawa jazdy: ";
        cin>>rok_prawojazdy;
        
        znizka = ((rok - rok_prawojazdy) * 10) - ((rok - rok_samochod) * 5);

        kwota_samochod = podstawa + znizka;




        Baza_Danych_Samochody::Samochod.push_back({id,rok_samochod,rok_prawojazdy,znizka,kwota_samochod});

        break;
    }
    else if(odp=="Nie"){
        break;
    }
    else{
        cout<<"Podano nieprawidlowa odpowiedz..."<<endl;
    }
    }
    //czy ubezpiecza dom
    while (true)
    {
        string odp;
        cout<<"Czy klient chce ubezpieczyc dom?(Tak/Nie) ";
        cin>>odp;
        if(odp=="Tak"){
            ubezpiecza_dom=true;
            bool czy_ma_alarm;
            cout<<"Podaj rok budowy domu: ";
            cin>>rok_budowy;

            cout<<"Podaj powierzchnie domu/mieszkania w metrach kwadratowych (zaokraglajac do pelnych metrow) ";
            cin>>powierzchnia;
            while (true){
                cout<<"Czy dom ma alarm? (Tak/Nie):";
                cin>>odp;
                if(odp=="Tak"){
                    czy_ma_alarm=true;
                    znizka_dom=200;
                    break;
                }
                else if(odp=="Nie"){
                    czy_ma_alarm=false;
                    znizka_dom=0;
                    break;
                }
                else{
                    cout<<"Zla odp"<<endl;
                }
            }
            
            while (true){
                cout<<"Czy to jest dom czy mieszkanie? (Dom/Mieszkanie)";
                cin>>rodzaj_domu;
                if(rodzaj_domu=="Dom"){
                    kwota_dom = (powierzchnia*10) + ((rok - rok_budowy)*5) + podstawa_dom - znizka_dom;
                    break;
                }
                else if(rodzaj_domu=="Mieszkanie"){
                    kwota_dom = (powierzchnia*10) + ((rok - rok_budowy)*5) + podstawa_mieszkanie - znizka_dom;
                    break;
                }
                else{
                    cout<<"Zla odp"<<endl;
                }
            }

            Baza_Danych_Domy::Dom.push_back({id,rok_budowy,powierzchnia,kwota_dom,rodzaj_domu,czy_ma_alarm});

            break;
        }
        else if(odp=="Nie"){
            break;
        }
        else{
            cout<<"Podano nieprawidlowa odpowiedz..."<<endl;
        }
    }

    //zadowolenie
    if(ubezpiecza_samochod){
        cout<<"Kwota ubezpieczenia samochodu wyniosla "<<kwota_samochod<<" zl"<<endl;
    }
    if(ubezpiecza_dom){
        cout<<"Kwota ubezpieczenia domu wyniosla "<<kwota_dom<<" zl"<<endl;
    }
    int zadowolenie;
    cout<<"W skali od 1 do 5 podaj zadowolenie klienta(liczby calkowite):";
    cin>>zadowolenie;
    Baza_Danych_Pracownikow::Pracownik[ZalogowanyPracownik::Logged_in[0].id].zadowolenie+=zadowolenie;
    Baza_Danych_Pracownikow::Pracownik[ZalogowanyPracownik::Logged_in[0].id].liczba_klientow++;

    Baza_Danych_Klientow::Klient.push_back({id,imie,nazwisko,pesel,ubezpiecza_samochod,ubezpiecza_dom});
    cout << "Klient "<<imie<<" "<<nazwisko<<" dodany do bazy danych"<<endl;
}