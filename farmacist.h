#ifndef farmacist_H
#define farmacist_H

#include <iostream>
#include <cstring>

class Medicament;

class Farmacist 
{
private:
    char* numeFarmacist;

public:
    Farmacist(const char* numeFarmacist);
    ~Farmacist();
    const char* get_numeFarmacist() const;
    friend std::ostream& operator<<(std::ostream& os, Farmacist farm1);
};

#endif