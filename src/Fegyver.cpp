#include "Fegyver.h"

Fegyver::Fegyver() : Targy("",0,0,0), kritikusSebzes(0)
{
    //ctor
}

Fegyver::Fegyver(std::string Nev,int VeteliAr,int EladasiAr,int TamadasPlusz,double KritikusSebzes) : Targy(Nev,VeteliAr,EladasiAr,TamadasPlusz), kritikusSebzes(KritikusSebzes) {}

Fegyver& Fegyver::clone() const
{
    return new Fegyver(*this);
}

Fegyver::~Fegyver()
{
    //dtor
}
