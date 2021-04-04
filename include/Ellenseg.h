#ifndef ELLENSEG_H
#define ELLENSEG_H

#include "Karakter.h"
#include <string>

class Ellenseg : public Karakter
{
    double maxTamadasSzorzo;
    public:
        Ellenseg();
        Ellenseg(std::string Nev,int Eletero,int Tapasztalat,int Arany,int MinSebzes,int MaxSebzes,int Vedekezes,double VedekezesSzorzo,double MaxTamadasSzorzo);
        virtual ~Ellenseg();

        double getMaxTamadasSzorzo() const {return maxTamadasSzorzo;}
        void setMaxTamadasSzorzo(double maxTamadasSzorzo) {maxTamadasSzorzo = MaxTamadasSzorzo;}
        void tamadas(Karakter& kit);
};

std::ostream& operator<<(std::ostream& out,const Ellenseg& ellenseg);

#endif // ELLENSEG_H
