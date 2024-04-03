#include "medicament.h"
#include <iostream>

Medicament::Medicament(const char* nume, double pret, int cantitate, const char* data_exp) :
    pret(pret), cantitate(cantitate)
    {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        this->data_exp = new char[strlen(data_exp) + 1];
        strcpy(this->data_exp, data_exp);
    }

Medicament::~Medicament() 
{
    delete[]this->nume;
    delete[]this->data_exp;
}

std::ostream& operator<<(std::ostream& os, Medicament m1)
{

    os<< "Nume: " << m1.nume <<'\n';
    os<< "Pret: " << m1.pret <<" lei"<<'\n';
    os<< "Cantitate: " << m1.cantitate<<'\n';
    os<< "Data expirare: " << m1.data_exp<<'\n';
    return os;
}

char* Medicament::get_nume() const 
{
    return this->nume;
}

double Medicament::get_pret() const 
{
    return pret;
}

int Medicament::get_cantitate() const 
{
    return cantitate;
}

void Medicament::set_cantitate(int cantitate_noua) 
{
    cantitate = cantitate_noua;
}

char* Medicament::get_data_exp() const 
{
    return this->data_exp;
}