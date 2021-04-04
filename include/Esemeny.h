#ifndef ESEMENY_H
#define ESEMENY_H

#include "Jatekos.h"
#include "Ellenseg.h"
#include "Targy.h"
#include <vector>

class Esemeny
{
    public:
        Esemeny();
        virtual ~Esemeny();

        void generalEsemeny(Jatekos&,std::vector<Targy*>);
        void boltTalalkozas(Jatekos&,std::vector<Targy*>);
        void ellenfelTalalkozas(Jatekos&, std::vector<Ellenseg*>);
};

#endif // ESEMENY_H
