#include "Karakter.h"
#include <iostream>

Karakter::Karakter()
{
    nev = "";
    eletero = 0;
    tapasztalat = 0;
    arany = 0;
    minSebzes = 0;
    maxSebzes = 0;
    vedekezes = 0;
}

Karakter::Karakter(std::string Nev, int Eletero, int Tapasztalat, int Arany, int MinSebzes, int MaxSebzes, int Vedekezes)
{
    nev = Nev;
    eletero = Eletero;
    tapasztalat = Tapasztalat;
    arany = Arany;
    minSebzes = MinSebzes;
    maxSebzes = MaxSebzes;
    vedekezes = Vedekezes;
}

void Karakter::takeSebzes(const int Sebzes)
{
    eletero-=Sebzes;
    if(eletero<0)
    {
        eletero = 0;
    }
}

std::ostream& operator<<(std::ostream& out, const Karakter& karakter)
{
       return out << karakter.getNev() << "\nHp: " << karakter.getEletero()
        << "\nTp: "<<karakter.getTapasztalat()
        << "\nArany: "<<karakter.getArany()
        << "\nSebzes: "<<karakter.getSebzes()
        << "\nVedekezes: "<<karakter.getVedekezes() << std::endl;
}

Karakter::~Karakter()
{
}
