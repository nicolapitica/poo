#ifndef farmacie_H
#define farmacie_H
#include <iostream>
#include <string>
#include <vector>
class Medicament;
class Farmacist;

class Farmacie 
{
private:
    std::vector<Medicament> inventar;
    std::vector<Farmacist> farmacisti;
    std::vector<std::string> expirate;
    int stoc;
    int nrFarmacisti;
    
    double pret_total(double pret,int cantitate) const;
    

public:
    Farmacie();
    ~Farmacie();

    void adaugaFarmacist(const char* numeFarmacist);
    void adaugaMedicament(const char* nume, double pret, int cantitate, const char* data_exp);
    void vindeMedicament(Medicament& medicament, int cantitate);
    void afisare_inventar();
    void afisare_farmacisti(); 
    void retragere_casare_expirate();
    
    friend std::ostream& operator<<(std::ostream& os, const Farmacie f1);
};

#endif