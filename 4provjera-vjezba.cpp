#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<utility>
#include<numeric>

using namespace std;

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
    }
    return 0;
}
