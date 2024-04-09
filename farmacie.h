#ifndef FARMACIE_H
#define FARMACIE_H
#include <iostream>
#include <string>
#include <vector>


#include "farmacist.h"
#include "medicament.h"

class Farmacie 
{
private:
    std::vector<Medicament> inventar;
    std::vector<Farmacist> farmacisti;
    int stoc;
    int nrFarmacisti;
    //Metode private
    double pret_total(double pret,int cantitate) const;
    void adaugaFarmacist(const char* numeFarmacist);
    void adaugaMedicament(const char* nume, double pret, int cantitate, const char* data_exp);
    void vindeMedicament(const char* nume, int cantitate);
    void afisare_inventar() const;
    void afisare_farmacisti() const;

public:
    //Constructor
    Farmacie();
    //Functiile pentru citire
     std::istream& citirefarmacist(std::istream& is, Farmacie& farmacie);
     std::istream& citiremedicament(std::istream& is, Farmacie& farmacie);
     std::istream& citirevanzare(std::istream& is, Farmacie& farmacie);
    //Alte metode proprii
    void retragere_casare_expirate(); 
    //Functiei pentru afisare
    friend std::ostream& operator<<(std::ostream& os, const Farmacie& f1);
};

#endif