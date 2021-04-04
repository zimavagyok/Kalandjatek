#include "Ellenseg.h"

#include <iostream>

Ellenseg::Ellenseg() : Karakter("",0,0,0,0,0,0), maxTamadasSzorzo(0.0)
{
}

Ellenseg::Ellenseg(std::string Nev,int Eletero,int Tapasztalat,int Arany,int MinSebzes,int MaxSebzes,int Vedekezes,double VedekezesSzorzo,double MaxTamadasSzorzo)
        : Karakter(Nev,Eletero,Tapasztalat,Arany,MinSebzes,MaxSebzes,Vedekezes), maxTamadasSzorzo(MaxTamadasSzorzo) {}

void Ellenseg::tamadas(Karakter& ki, Karakter& kit)
{
    int mennyi = ki.getSebzes()*maxTamadasSzorzo-(0.5*kit.getVedekezes());
    kit.takeSebzes(mennyi);
    std::cout<<"Az elszenvedett sebzes: "<<mennyi<<std::endl;
}

std::ostream& operator<<(std::ostream& out,const Ellenseg& ellenseg)
{
    out << (Karakter&)ellenseg
        << "Az ellenseged tamadas szorzoja: " << ellenseg.getMaxTamadasSzorzo() << std::endl;
}

Ellenseg::~Ellenseg()
{
    //dtor
}
