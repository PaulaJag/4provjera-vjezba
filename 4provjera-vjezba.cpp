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

bool ispis_podataka(string prezimeIme[], unsigned long long int brRacuna[],double saldo[],int brKlijenata,string pretrazivanje)
{
    int br=0;
    for(int i=0;i<brKlijenata;i++)
    {
        if(prezimeIme[i]==pretrazivanje){
        cout<<brRacuna[i]<<", "<<saldo[i]<<endl;
        br++;}
    }
    if(br==0)
        return false;
    return true;
}

int main()
{

    int brKlijenata=0;
    unsigned long long int *brRacuna=new unsigned long long int[1000];
    unsigned long long int *brRacuna2=new unsigned long long int[1000];
    string *prezimeIme=new string[1000];
    string *prezimeIme2=new string[1000];
    double *saldo=new double[1000];
    double *saldo2=new double[1000];
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

            else if(izbor==3)
            {
            cout<< "Unesite ime i prezime koje pretrazujete: ";
            string pretrazivanje;
            cin.ignore();
            getline(cin,pretrazivanje);
            if(ispis_podataka(prezimeIme,brRacuna,saldo,brKlijenata,pretrazivanje)==false)
                cout<<"Nema takvih klijenata"<<endl;
            }

            else if(izbor==4)
            {
            unsigned long long broj;int i;
            cout<<"Unesite broj racuna koji zelite izbrisati: ";
            cin>>broj;
            for(i=0;i<brKlijenata;i++)
            {
                if(brRacuna[i]==broj)
                {
                    for(int j=0;j<brKlijenata;j++)
                    {
                        brRacuna[j]=brRacuna[j+1];
                        prezimeIme[j]=prezimeIme[j+1];
                        saldo[j]=saldo[j+1];
                    }
                    brKlijenata--;
                    break;
                }
            }
            if(i==brKlijenata)
                cout<<"Trazenog broja nema.";
            }

        else if(izbor==5)
        {
            cout<<"Racuni sortirani A-Z: "<<endl;
            copy(prezimeIme,prezimeIme+brKlijenata,prezimeIme2);
            copy(saldo,saldo+brKlijenata,saldo2);
            copy(brRacuna,brRacuna+brKlijenata,brRacuna2);
            for(int i=0;i<brKlijenata;i++)
            {
                for(int j=brKlijenata-1;j>i;j--)
                {
                  if(prezimeIme[i]>prezimeIme[i+1])
                  {
                      swap(prezimeIme2[i],prezimeIme2[i+1]);
                      swap(saldo2[i],saldo2[i+1]);
                      swap(brRacuna2[i],brRacuna2[i+1]);
                  }
                }

            }
                for(int i=0; i<brKlijenata; i++)
                    cout << brRacuna2[i]<< ", "<< prezimeIme2[i]<<", "<<saldo2[i]<<endl;
        }


        }
    return 0;
}
