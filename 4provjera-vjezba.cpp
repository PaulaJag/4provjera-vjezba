#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<utility>
#include<numeric>
using namespace std;

bool negativni_saldo(double saldo)
{
    if(saldo<0)
        return true;
    else
        return false;

}
bool tekuci(unsigned long long broj)
{
    if(broj/10000000==32)
        return true;
    else
        return false;
}

int main()
{

    int brKlijenata=0;
    unsigned long long int *brRacuna=new unsigned long long int[1000];
    string *prezimeIme=new string[1000];
    double *saldo=new double[1000];
    int izbor;
    while(1)
    {
      cout<<"1. unos novog racuna"<<endl;
      cout<<"2. ispisi sve podatke"<<endl;
      cout<<"3. pretraga prema prezimenu i imenu"<<endl;
      cout<<"4. brisanje racuna"<<endl;
      cout<<"5. ispisi sortirano po prezimenu i imenu"<<endl;
      cout<<"6. izmjena podataka prema broju racuna"<<endl;
      cout<<"7. izlaz"<<endl;
        cout<<"Unesite svoj odabir: ";
        cin >> izbor;
        if(izbor==1)
        {
            unsigned long long unos;
            while(1)
            {
                try
                {
                    cout << "Unesite broj racuna: ";
                    cin >> unos;
                    if(unos<1000000000 || unos>9999999999)
                        throw "Broj racuna mora imati 10 znamenki.";
                    break;
                }
                catch(const char* msg)
                {
                    cout << msg << endl;
                }
            }
            brRacuna[brKlijenata]=unos;
            cout << "Unesite prezime i ime: " << endl;
            cin.ignore();
            getline(cin, prezimeIme[brKlijenata]);
            cout << "Unesite saldo: ";
            cin >> saldo[brKlijenata];
            brKlijenata++;
            }
           else if(izbor==2)
            {
            for(int i=0; i<brKlijenata; i++)
                cout << brRacuna[i] << ", " << prezimeIme[i] << ", " << saldo[i] << endl;
            cout<<"Suma svih salda iznosi:"<<accumulate(saldo,saldo+brKlijenata, 0.0)<<endl;
            int max_index=max_element(saldo,saldo+brKlijenata)-saldo;
            cout<<"Klijent koji ima najveci saldo: "<< prezimeIme[max_index]<<endl;
            cout<<"Broj racuna sa negativnim saldom: "<<count_if(saldo,saldo+brKlijenata,negativni_saldo)<<endl;
            cout<<"Broj tekucih racuna: "<<count_if(brRacuna,brRacuna+brKlijenata,tekuci)<<endl;
            }
        }
    return 0;
}
