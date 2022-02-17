#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
#include "exit_command.hh"
#include "zapisywanie_pracownikow.hh"
#include "zapisywanie_klientow.hh"

void ExitCommand::wykonaj() {
    cout<<"Czy chcesz zapisac bazy danych?(Tak/Nie): ";
    string odp;
    cin>>odp;
    if(odp=="Tak"){
        make_shared<ZapisywanieKlientow>()->wykonaj();
        make_shared<ZapisywaniePracownikow>()->wykonaj();
    }
    cout << "Wychodzenie z aplikacji..." << endl;
    exit(0);
}