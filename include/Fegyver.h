#ifndef FEGYVER_H
#define FEGYVER_H

#include "Targy.h"
#include <string>

class Fegyver : public Targy
{
    double kritikusSebzesEsely;
    double kritikusSebzesSzorzo;

    public:
        Fegyver();
        Fegyver(std::string,int,int,int,int,double,double,bool);
        virtual ~Fegyver();

        double getKritikusSebzesEsely() {return kritikusSebzesEsely;}
        void setKritikusSebzesEsely(double KritikusSebzesEsely) {kritikusSebzesEsely = KritikusSebzesEsely;}
        double getKritikusSebzesSzorzo() {return kritikusSebzesSzorzo;}
        void setKritikusSebzesSzorzo(double KritikusSebzesSzorzo)  {kritikusSebzesSzorzo = KritikusSebzesSzorzo;}
        Targy& clone() const;
};

std::ostream& operator<<(std::ostream&, const Fegyver&);

#endif // FEGYVER_H
