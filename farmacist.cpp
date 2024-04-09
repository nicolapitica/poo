<<<<<<< HEAD
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
=======
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
>>>>>>> cdc4721027c532e5d4d051be8583c5a2324dbbc6
