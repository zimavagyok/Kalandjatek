#include "Fegyver.h"

#include <iostream>

Fegyver::Fegyver() : Targy("",0,0,0), kritikusSebzes(0)
{
    //ctor
}

Fegyver::Fegyver(std::string Nev,int VeteliAr,int EladasiAr,int TamadasPlusz,double KritikusSebzes) : Targy(Nev,VeteliAr,EladasiAr,TamadasPlusz), kritikusSebzes(KritikusSebzes) {}

Fegyver& Fegyver::clone() const
{
    return new Fegyver(*this);
}

void Fegyver::hasznal(Jatekos& jatekos)
{
    std::cout<<"A fegyvered mar hasznalatban van!\n";
}

std::ostream& operator<<(std::ostream& out, const Fegyver& fegyver)
{
    out << (Targy&)fegyver
        << "\tKritikus sebzes: " << fegyver.getKritikusSebzes() << std::endl;
}

Fegyver::~Fegyver()
{
    //dtor
}
