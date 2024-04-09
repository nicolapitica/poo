#include "farmacist.h"
#include <iostream>
#include <string>

//Implementarea constructorului
Farmacist::Farmacist(const std::string numeFarmacist): numeFarmacist(numeFarmacist) {}
//Implementarea getter-ului
const std::string Farmacist::get_numeFarmacist() const 
{
    return this->numeFarmacist;
}
//Implementarea functiei pentru afisare
std::ostream& operator<<(std::ostream& os, const Farmacist& farm1)
{
    os << "Nume farmacist: " << farm1.numeFarmacist << '\n';
    return os;
}
