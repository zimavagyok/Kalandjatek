#include "Kiegeszito.h"

void elvalasztas()
{
    std::cout<<"\n\n#-------------------------------------------------#\n\n";
}

std::string randomNev(int hossz)
{
    char massalhangzo[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
    char maganhangzo[] = {'a','e','i','o','u','y'};

    std::string nev = "";

    int random = rand() % 2;
    int szamol = 0;

    for(int i = 0; i < hossz; i++) {

        if(random < 2 && szamol < 2) {
            nev = nev + massalhangzo[rand() % 19];
            szamol++;
        }
        else {
            nev = nev + maganhangzo[rand() % 5];
            szamol = 0;
        }

        random = rand() % 2;

    }

    return nev;
}
