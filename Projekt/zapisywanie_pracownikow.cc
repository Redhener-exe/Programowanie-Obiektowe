#include <fstream>
#include <iostream>
using namespace std;
#include "zapisywanie_pracownikow.hh"
#include "baza_pracownikow.hh"

void ZapisywaniePracownikow::wykonaj() {
    ofstream out("Baza danych pracownikow.txt");
    for (auto &&pracownik: Baza_Danych_Pracownikow::Pracownik) {
        out << pracownik.haslo <<" "<< pracownik.id << " " << pracownik.zadowolenie << " " << pracownik.liczba_klientow<<" "<<pracownik.srednia_zadowolenia<<" "<<pracownik.premia<< "\n";
    }
    out.close();
    std::cout << "Baza pracownikow zaladowana do: Baza danych pracownikow.txt";
}
