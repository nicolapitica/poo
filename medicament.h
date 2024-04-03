#ifndef medicament_H
#define medicament_H

#include <iostream>
#include <cstring>

class Medicament 
{
private:
    char* nume;
    double pret;
    int cantitate;
    char* data_exp;


public:
    Medicament(const char* nume, double pret, int cantitate, const char* data_exp);
    ~Medicament();
    char* get_nume() const;
    int get_cantitate() const;
    void set_cantitate(int cantitate_noua);
    char* get_data_exp() const;
    double get_pret() const;
    friend std::ostream& operator<<(std::ostream& os, Medicament m1);
};

#endif