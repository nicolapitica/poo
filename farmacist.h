<<<<<<< HEAD
#ifndef FARMACIST_H
#define FARMACIST_H

#include <iostream>
#include <string>

class Farmacist 
{
private:
    std::string numeFarmacist;

public:
    //Constructor
    Farmacist(const std::string numeFarmacist);
    //Getter
    const std::string get_numeFarmacist() const;
    //Functie friend pentru afisare
    friend std::ostream& operator<<(std::ostream& os, const Farmacist& farm1);
};

=======
#ifndef FARMACIST_H
#define FARMACIST_H

#include <iostream>
#include <string>

class Farmacist 
{
private:
    std::string numeFarmacist;

public:
    //Constructor
    Farmacist(const std::string numeFarmacist);
    //Getter
    const std::string get_numeFarmacist() const;
    //Functie friend pentru afisare
    friend std::ostream& operator<<(std::ostream& os, const Farmacist& farm1);
};

>>>>>>> cdc4721027c532e5d4d051be8583c5a2324dbbc6
#endif