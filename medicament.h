#ifndef MEDICAMENT_H
#define MEDICAMENT_H

#include <iostream>
#include <string>

class Medicament 
{
private:
    std::string nume;
    double pret;
    int cantitate;
    std::string data_exp;


public:
    //Constructorul
    Medicament(const std::string nume, double pret, int cantitate, const std::string data_exp);
    //Getteri 
    const std::string& get_nume() const;
    int get_cantitate() const;
    double get_pret() const;
    const std::string& get_data_exp() const;
    //Setteri
    void set_cantitate(int cantitate_noua);
    //Functie friend pentru afisare
    friend std::ostream& operator<<(std::ostream& os, const Medicament& m1);
};

#endif