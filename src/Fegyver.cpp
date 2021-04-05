#include "Fegyver.h"
#include "Jatekos.h"

#include <iostream>

Fegyver::Fegyver() : Targy("",0,0,0), kritikusSebzes(0)
{
    //ctor
}

Fegyver::Fegyver(std::string Nev,int VeteliAr,int EladasiAr,int TamadasPlusz,int KritikusSebzes) : Targy(Nev,VeteliAr,EladasiAr,TamadasPlusz), kritikusSebzes(KritikusSebzes) {}

Fegyver* Fegyver::clone() const
{
    return new Fegyver(*this);
}

void Fegyver::hasznal(Jatekos& jatekos)
{
    std::cout<<"A fegyvered mar hasznalatban van!\n";
}

std::ostream& operator<<(std::ostream& out, Fegyver& fegyver)
{
    return out << (Targy&)fegyver
        << "\tKritikus sebzes: " << fegyver.getKritikusSebzes() << std::endl;
}

void Fegyver::vasarol(Jatekos& jatekos)
{
    jatekos.setElsodlegesFegyver(*this);
}

Fegyver::~Fegyver()
{
    //dtor
}
