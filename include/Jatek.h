#ifndef JATEK_H
#define JATEK_H

#include "Jatekos.h"
#include "Targy.h"
#include "Jatek.h"
#include "memtrace.h"

class Jatek
{
    int valasztas;
    bool jatekFut;
    Jatekos* jatekos;
    std::vector<Targy*> betoltottTargyak;

    public:
        Jatek();
        virtual ~Jatek();

        void initJatek();
        void foMenu();
        void jatekMenu();
        void karakterMenu();
        void ujJatekosKeszitese();
        void karakterSzintlepes();
        void utazas();
        void pihenes();
};

#endif // JATEK_H
