#include "Farmacist.h"
#include "Medicament.h"
#include <iostream>
#include <cstring>

Farmacist::Farmacist(const char* numeFarmacist) 
{
    this->numeFarmacist = new char[strlen(numeFarmacist) + 1];
    strcpy(this->numeFarmacist, numeFarmacist);
}

Farmacist::~Farmacist() 
{
    delete[]this->numeFarmacist;
}

const char* Farmacist::get_numeFarmacist() const 
{
    return this->numeFarmacist;
}

std::ostream& operator<<(std::ostream& os, Farmacist farm1)
{
    os << "Nume farmacist: " << farm1.numeFarmacist << '\n';
    return os;
}

int main(){
    return 0;
}