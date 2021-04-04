#ifndef ELLENSEG_H
#define ELLENSEG_H

#include "Karakter.h"
#include <string>

class Ellenseg : public Karakter
{
    double maxTamadasSzorzo;
    public:
        Ellenseg();
        Ellenseg(std::string,int,int,int,int,int,int,double);
        virtual ~Ellenseg();

        double getMaxTamadasSzorzo() const {return maxTamadasSzorzo;}
        void setMaxTamadasSzorzo(double maxTamadasSzorzo) {maxTamadasSzorzo = MaxTamadasSzorzo;}
        void tamadas(Karakter&, Karakter&);
};

std::ostream& operator<<(std::ostream&,const Ellenseg&);

#endif // ELLENSEG_H
