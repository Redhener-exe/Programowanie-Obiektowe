#pragma once

#include <string>
using namespace std;

struct Klient {
    int id;
    string imie;
    string nazwisko;
    string pesel;
    int ubezpiecza_samochod=false;
    int ubezpiecza_dom=false;
};