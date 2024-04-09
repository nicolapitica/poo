#include "medicament.h"
#include <iostream>

//Implementarea constructorului
Medicament::Medicament(const std::string nume, double pret, int cantitate,const std::string data_exp) :
    nume(nume), pret(pret), cantitate(cantitate), data_exp(data_exp) {}

const std::string& Medicament::get_nume() const 
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

const std::string& Medicament::get_data_exp() const 
{
    return this->data_exp;
}
//Implementarea setter-ului
void Medicament::set_cantitate(int cantitate_noua) 
{
    cantitate = cantitate_noua;
}
//Implementarea functiei de afisare
std::ostream& operator<<(std::ostream& os, const Medicament& m1)
{

    os<< "Nume: " << m1.nume <<'\n';
    os<< "Pret: " << m1.pret <<" lei"<<'\n';
    os<< "Cantitate: " << m1.cantitate<<'\n';
    os<< "Data expirare: " << m1.data_exp<<'\n';
    return os;
}