#include <fstream>
#include <iostream>
using namespace std;
#include "zapisywanie_klientow.hh"
#include "baza_klientow.hh"

void ZapisywanieKlientow::wykonaj() {
    ofstream out("Baza danych klientow.txt");
    for (auto &&klient: Baza_Danych_Klientow::Klient) {
        out << klient.imie << " " << klient.nazwisko<<" "<<klient.pesel<<" "<<klient.id << " "<<klient.ubezpiecza_samochod<<" "<<klient.ubezpiecza_dom << "\n";
    }
    out.close();
    std::cout << "Baza klientow zapisana do: Baza danych klientow.txt";
}
