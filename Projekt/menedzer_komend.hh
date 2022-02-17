#pragma once

#include <map>
#include <string>

#include "komenda.hh"

class Menedzer_Komend {
    std::map<std::string, pcommand> komendy;
public:

    Menedzer_Komend();
    void petla_rejestracji();
    void petla();
};