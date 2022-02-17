#pragma once

#include "komenda.hh"

class Logowanie: public Komenda {
public:
    void wykonaj();
    bool poprawne_logowanie(int id, string haslo);
};
