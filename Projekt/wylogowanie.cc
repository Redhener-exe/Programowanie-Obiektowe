#include <iostream>

using namespace std;


#include "wylogowanie.hh"
#include "zalogowany.hh"
#include "logowanie.hh"
#include "exit_command.hh"

void Wylogowanie::wykonaj() {
    string odp;
    cout<<"Czy napewno chcesz sie wylogowac?(Tak/Nie): ";
    cin>>odp;
    if(odp=="Tak"){
        ZalogowanyPracownik::Logged_in.clear();
        cout<<"Zalogowac ponownie?(Tak/Nie): ";
        cin>>odp;
        if(odp=="Tak"){
            make_shared<Logowanie>()->wykonaj();
        }
        else{
            make_shared<ExitCommand>()->wykonaj();
        }
    }
    else{
        cout<<"No to sie zdecyduj"<<endl;
    }
}
    
