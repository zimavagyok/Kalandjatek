#include "Ital.h"

Ital::Ital() : Targy("",0,0,0), eleteroPlusz(0)
{
    //ctor
}

Ital::Ital(std::string Nev,int VeteliAr,int EladasiAr,int TamadasPlusz,int EleteroPlusz): Targy(Nev,VeteliAr,EladasiAr,TamadasPlusz), eleteroPlusz(EleteroPlusz) {}

Ital& Ital::clone() const
{
    return new Ital(*this);
}

std::ostream& operator<<(std::ostream& out, const Ital& ital)
{
    out << (Targy&)ital
        << "\tPlusz eletero: " << ital.getEleteroPlusz() << std::endl;
}

Ital::~Ital()
{
    //dtor
}
