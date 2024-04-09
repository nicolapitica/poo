#include "farmacie.h"
#include <iostream>

int main()
{
    Farmacie DrMax; //Definim DrMax de tip farmacie.
    std::cout<<"Buna ziua! Bine ati venit la farmacia DrMax!"<<'\n';
    DrMax.citirefarmacist(std::cin,DrMax); //Citim primul farmacist.
    int ok=1;
    while(ok==1) //Cat timp nu am selectat comanda 6 care inchide farmacia, aleg cate o comanda.
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
        std::cin.ignore();
        //In functie de comanda aleasa, o sa apelez metoda potrivita din farmacie.
        if(nr==1)
            DrMax.citirefarmacist(std::cin,DrMax);
        else 
        if(nr==2)
            DrMax.citiremedicament(std::cin,DrMax);
        else 
        if(nr==3)
            DrMax.citirevanzare(std::cin,DrMax);
        else 
        if(nr==4)
            DrMax.retragere_casare_expirate();
        else
        if(nr==5)
            operator<<(std::cout, DrMax);
        else
        {
            ok=0;
            std::cout<<"Multumim! O zi buna!";
        }
    }

    return 0;
} 