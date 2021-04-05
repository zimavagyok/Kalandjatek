#ifndef ITAL_H
#define ITAL_H

#include "Targy.h"

class Ital : public Targy
{
    int eleteroPlusz;

    public:
        Ital();
        Ital(std::string Nev,int VeteliAr,int EladasiAr,int TamadasPlusz,int EleteroPlusz);
        virtual ~Ital();

        int getEleteroPlusz() {return eleteroPlusz;}
        void setEleteroPlusz(int EleteroPlusz) {eleteroPlusz = EleteroPlusz;}
        Targy& clone() const;
        void hasznal(Jatekos& jatekos);
};

std::ostream& operator<<(std::ostream& out, const Ital& ital);

#endif // ITAL_H
