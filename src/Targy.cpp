#include "Targy.h"
#include <iostream>

Targy::Targy() : nev(""), veteliAr(0), eladasiAr(0),tamadasPlusz(0)
{
    //ctor
}

Targy::Targy(std::string Nev, int VeteliAr, int EladasiAr, int TamadasPlusz) : nev(Nev), veteliAr(VeteliAr), eladasiAr(EladasiAr), tamadasPlusz(TamadasPlusz) {}

std::ostream& operator<<(std::ostream& out,const Targy& targy)
{
    return out << targy.getNev()
                << "\n\tVeteli ar: " << targy.getVeteliAr()
                << "\n\tEladasi ar: " << targy.getEladasiAr()
                << "\n\tTamadas plusz: " << targy.getTamadasPlusz() << std::endl;
}

Targy::~Targy()
{
    //dtor
}
