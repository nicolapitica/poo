#include "medicament.h"
#include "farmacie.h"
#include "farmacist.h"
#include <iostream>
#include <cstring>

Farmacie::Farmacie() : inventar(NULL), farmacisti(NULL), stoc(0), nrFarmacisti(0),expirate(NULL) {}

Farmacie::~Farmacie() 
{
    // if(inventar!=NULL)
    //     delete[]this->inventar;
    // if(farmacisti!=NULL)
    //     delete[]this->farmacisti;
    // if(expirate!=NULL)
    //     delete[]this->expirate;
}
double Farmacie::pret_total(double pret,int cantitate) const
{
    return pret*cantitate;
}
void Farmacie::retragere_casare_expirate() 
{
    int index = 0;
    for (int i = 0; i < stoc; ++i) 
    {
        if (strcmp(inventar[i].get_data_exp(),"2024-04-03")<=0) 
        { 
            expirate[index] = new char[strlen(inventar[i].get_nume()) + 1];
            expirate.push_back(inventar[i].get_nume());
            index++;
        }
    }
    for (int i = 0; i < index; ++i) 
    {
        for (int j = 0; j < stoc; ++j) 
        {
            if (strcmp(expirate[i].c_str(),inventar[j].get_nume())==0) 
            {
                for (int k = j; k < stoc - 1; ++k) 
                    inventar[k] = inventar[k + 1];
                stoc--;
                delete[]this-> inventar[stoc].get_nume();
                break;
            }
        }
    }
}

void Farmacie::adaugaFarmacist(const char* numeFarmacist) 
{
    nrFarmacisti++;
    Farmacist* aux = new Farmacist(numeFarmacist);
    farmacisti.push_back(*aux);
    // if (farmacisti == NULL) 
    // {
    //     farmacisti = aux;
    // } 
    // else 
    // {
    //     std::vector<Farmacist> auxFarmacisti;
    //     for (int i = 0; i < nrFarmacisti - 1; ++i)
    //         auxFarmacisti[i] = farmacisti[i];        
    //     auxFarmacisti[nrFarmacisti - 1] = *aux;
    //     delete[]this-> farmacisti;
    //     farmacisti(auxFarmacisti);
    // }
    // delete aux;
    /*
    nrFarmacisti++;
    farmacisti[nrFarmacisti] = new Farmacist(numeFarmacist);
    */
}

void Farmacie::adaugaMedicament(const char* nume, double pret, int cantitate, const char* data_exp) 
{
    int ok=0;
    for(int i=0; i<stoc; i++)
    {
        if (strcmp(inventar[i].get_nume(), nume)==0) 
        {
            inventar[i].set_cantitate(inventar[i].get_cantitate() + cantitate);
            ok=1;
        }
    }
    if(ok==0)
    {
        // Medicament* auxInventar = new Medicament[stoc + 1]; 
        // for (int i = 0; i < stoc; ++i) 
        //     auxInventar[i] = inventar[i];
        // auxInventar[stoc++] = Medicament(nume, pret, cantitate, data_exp);
        // delete[]this-> inventar;
        // inventar = auxInventar;
        Medicament deadaugat = Medicament(nume, pret, cantitate, data_exp);
        inventar.push_back(deadaugat);
    }
}

void Farmacie::vindeMedicament(Medicament& medicament, int cantitate) 
{
    double plata = pret_total( medicament.get_pret(), cantitate);
    if (medicament.get_cantitate() >= cantitate) 
    {
        medicament.set_cantitate(medicament.get_cantitate() - cantitate);
        std::cout << cantitate << " cutii de " << medicament.get_nume() << " costa " << plata << " lei." <<'\n';
    } 
    else 
    {
        std::cout << "Stoc insuficient." << '\n';
    }
}

void Farmacie::afisare_inventar()  
{
    if (stoc != 0) 
        for (int i = 0; i < stoc; ++i) 
            std::cout << inventar[i];
    else 
        std::cout << "Inventar gol." << '\n';
}
void Farmacie::afisare_farmacisti()  
{
    if(farmacisti.size() > 0){
        for(auto farmacist : farmacisti){
            std::cout << farmacist;
        }
    }
    else{
        std::cout << "Nu s-au adaugat farmacisti." << '\n';
    }    
}

std::ostream& operator<<(std::ostream& os, Farmacie &f1){
    os << "Lista farmacisti: " << std::endl;
    f1.afisare_farmacisti();
    os << "Lista inventar: " << std::endl;
    f1.afisare_inventar();
}

int main(){
    return 0;
}