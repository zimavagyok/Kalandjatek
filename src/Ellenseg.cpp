#include "Ellenseg.h"
#include "Kiegeszito.h"
#include <iostream>

Ellenseg::Ellenseg() : Karakter("",0,0,0,0,0,0), maxTamadasSzorzo(0.0)
{
}

Ellenseg::Ellenseg(std::string Nev,int Eletero,int Tapasztalat,int Arany,int MinSebzes,int MaxSebzes,int Vedekezes,double MaxTamadasSzorzo)
        : Karakter(Nev,Eletero,Tapasztalat,Arany,MinSebzes,MaxSebzes,Vedekezes), maxTamadasSzorzo(MaxTamadasSzorzo) {}

Ellenseg::Ellenseg(int szint)
{
    setNev(randomNev(rand()%8+1));
    setEletero(rand()%(szint*10)+(szint*2));
    setArany(rand()%szint * 10 + 1);
    setTapasztalat(szint * 100);
    setMinSebzes(szint);
    setMaxSebzes(szint * 2);
    setVedekezes(rand() % szint*5 + 1);
    maxTamadasSzorzo = 1+(szint/10);
}

void Ellenseg::tamadas(Karakter& kit)
{
    int mennyi = getSebzes()*maxTamadasSzorzo-(0.5*kit.getVedekezes());
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
