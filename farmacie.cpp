#include "medicament.h"
#include "farmacist.h"
#include "farmacie.h"
#include <iostream>
#include <cstring>

Farmacie::Farmacie() : inventar(), farmacisti(), stoc(0), nrFarmacisti(0) {}

double Farmacie::pret_total(double pret,int cantitate) const
{
    return pret*cantitate;
}

void Farmacie::adaugaFarmacist(const char* numeFarmacist) 
{
    nrFarmacisti++; //Incrementăm numarul de farmacisti.
    Farmacist aux = Farmacist(numeFarmacist); //Creăm un nou farmacist.
    farmacisti.push_back(aux); //Adăugăm farmacistul in vectorul de farmacisti.
    std::cout<< "Noul farmacist a fost adaugat."<<'\n';
}
std::istream& Farmacie::citirefarmacist(std::istream& is,Farmacie& farmacie)
{   //Functia de citire a farmacistilor.
    std::string numeFarmacist;
    std::cout << "Logare noua: ";
    getline(is, numeFarmacist);
    //Apelam functia care adauga farmacistul citit.
    farmacie.adaugaFarmacist(numeFarmacist.c_str());
    return is;
}

std::istream& Farmacie::citiremedicament(std::istream& is,Farmacie& farmacie)
{   //Functia de citire a medicamentelor.
    std::string nume;
    std::cout << "Nume medicament: ";
    getline(is, nume);
    double pret;
    std::cout << "Pret medicament: ";
    is>> pret;
    int cantitate;
    std::cout << "Numar bucati: ";
    is>> cantitate;
    std::string data_exp;
    std::cout << "Data expirarii: ";
    is.ignore();
    getline(is, data_exp);
    //Apelam functia care adauga medicamentele in inventar.
    farmacie.adaugaMedicament(nume.c_str(),pret,cantitate,data_exp.c_str());
    return is;
}

void Farmacie::adaugaMedicament(const char* nume, double pret, int cantitate, const char* data_exp) 
{
    int ok=0;
    for(int i=0; i<stoc; i++) //Parcurgem inventarul.
    {
        if (inventar[i].get_nume()==nume) //Dacă medicamentul este deja în inventar, mărim cantitatea.
        {
            inventar[i].set_cantitate(inventar[i].get_cantitate() + cantitate);
            ok=1;
        }
    }
    if(ok==0) //Altfel îl adăugăm în inventar.
    {
        Medicament deadaugat = Medicament(nume, pret, cantitate, data_exp);
        inventar.push_back(deadaugat);
        stoc++;
    }
    std::cout<< "Medicamentul a fost adaugat."<<'\n';
}

void Farmacie::retragere_casare_expirate() 
{
    //Creăm un vector care sa memoreze medicamentele in termen valabil.
    std::vector<Medicament> nouInventar;
    //Parcurgem inventarul
    for (int i = 0; i < stoc; ++i) {
        if (inventar[i].get_data_exp() > "2024-04-10") //Verificăm daca medicamentul a expirat.
        {
            //Adaugăm medicamentele valabile in noul inventar.
            nouInventar.push_back(inventar[i]);
        }
    }
    //Verificăm dacă au fost șterse medicamente si afisăm mesajul potrivit.
    if (nouInventar.size() < stoc) 
    {
        std::cout << "Medicamentele expirate au fost retrase." << '\n';
    } else 
    {
        std::cout << "Nu exista medicamente expirate." << '\n';
    }
    //Actualizăm inventarul cu medicamentele valabile si dimensiunea lui.
    inventar = nouInventar;
    stoc = inventar.size();
}

std::istream& Farmacie::citirevanzare(std::istream& is,Farmacie& farmacie)
{   //Functia de citire a medicamentului pe care îl vindem.
    std::string nume;
    std::cout << "Nume medicament vandut: ";
    getline(is, nume);
    int cantitate;
    std::cout << "Numar bucati: ";
    is>> cantitate;
    //Apelăm metoda care modifica inventarul.
    farmacie.vindeMedicament(nume.c_str(),cantitate);
    return is;
}

void Farmacie::vindeMedicament(const char* nume, int cantitate) 
{
    if (stoc != 0) //Daca am medicamente in stoc il parcurgem pentru a gasi medicamentul cautat.
    {
        int ok=0; //Variabila stegulet pentru a afla daca am gasit medicamentul in inventar.
        for (int i = 0; i < stoc && ok==0; i++) 
            if(inventar[i].get_nume()==nume) //Daca il gasim calculam pretul achizitiei.
            {
                double plata = pret_total(inventar[i].get_pret(),cantitate);
                ok=1;
                if (inventar[i].get_cantitate() >= cantitate) //Daca avem suficiente bucati in stoc le vindem, afisam pretul si actualizam nr de bucati.
                {
                    inventar[i].set_cantitate(inventar[i].get_cantitate() - cantitate);
                    std::cout << cantitate << " cutii de " << inventar[i].get_nume() << " costa " << plata << " lei." <<'\n';
                } 
                else //Altfel nu il vindem,iar stocul ramane la fel.
                {
                    std::cout << "Stoc insuficient." << '\n';
                }
            }
        if(ok==0)
            std::cout<< "Nu exista medicamentul in inventar." << '\n';
    }
    else 
        std::cout << "Inventar gol." << '\n';
}

void Farmacie::afisare_inventar() const 
{
    //Daca sunt medicamente in inventar, parcurgem inventarul si le afisam.
    if (stoc != 0) 
        for (int i = 0; i < stoc; ++i) 
            std::cout << inventar[i];
    else 
        std::cout << "Inventar gol." << '\n';
}
void Farmacie::afisare_farmacisti() const 
{
    //Daca sunt farmacisti in vector ii afisam prin parcurgerea vectorului.
    if(farmacisti.size() > 0)
    {
        for(auto& farmacist : farmacisti)
        {
            std::cout << farmacist;
        }
    }
    else
    {
        std::cout << "Nu s-au adaugat farmacisti." << '\n';
    }    
}

std::ostream& operator<<(std::ostream& os, const Farmacie& f1)
{   //Afisam informatiile despre farmacie.
    os << "Lista farmacisti: " << std::endl;
    f1.afisare_farmacisti();
    os << "Lista inventar: " << std::endl;
    f1.afisare_inventar();
    return os;
}