#include "farmacie.h"
#include <iostream>

int main()
{
    Farmacie DrMax;
    std::cout<<"Buna ziua! Va rugam introduceti un utilizator nou:";
    citirefarmacist(std::cin,DrMax);
    int ok=1;
    while(ok==1)
    {
        std::cout<<"Alegeti una din urmatoarele comenzi:"<<std::endl;
        std::cout<<"   1. Logare noua"<<std::endl;
        std::cout<<"   2. Adaugare in stoc"<<std::endl;
        std::cout<<"   3. Vanzare medicamente"<<std::endl;
        std::cout<<"   4. Retragerea si casarea medicamentelor expirate"<<std::endl;
        std::cout<<"   5. Afisarea informatiilor despre farmacie"<<std::endl;
        std::cout<<"   6. Final de zi. Inchide farmacia"<<std::endl;
        int nr;
        std::cin>> nr;
        if(nr==1)
            citirefarmacist(std::cin,DrMax);
        else 
        if(nr==2)
            citiremedicament(std::cin,DrMax);
        else 
        if(nr==3)
            DrMax.vindeMedicament(med1,cant);
        else 
        if(nr==4)
            DrMax.retragere_casare_expirate();
        else
        if(nr==5)
            operator<<(std::cout, DrMax);
        else
            ok=0;
                    
    }

    return 0;
}