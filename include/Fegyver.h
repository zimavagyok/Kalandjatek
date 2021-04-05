#ifndef FEGYVER_H
#define FEGYVER_H

#include "Targy.h"
#include <string>

class Fegyver : public Targy
{
    double kritikusSebzes;

    public:
        Fegyver();
        Fegyver(std::string Nev,int VeteliAr,int EladasiAr,int TamadasPlusz,double KritikusSebzes);
        virtual ~Fegyver();

        double getKritikusSebzes() {return kritikusSebzes;}
        void setKritikusSebzes(double KritikusSebzes) {kritikusSebzes = KritikusSebzes;}
        Fegyver& clone() const;
        void hasznal(Jatekos& jatekos);
};

std::ostream& operator<<(std::ostream& out, const Fegyver& fegyver);

#endif // FEGYVER_H
