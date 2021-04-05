#ifndef TARGY_H
#define TARGY_H

#include "Jatekos.h"
#include <string>

class Targy
{
    std::string nev;
    int veteliAr;
    int eladasiAr;
    int tamadasPlusz;

    public:
        Targy();
        Targy(std::string Nev, int VeteliAr, int EladasiAr, int TamadasPlusz);
        virtual ~Targy();

        std::string getNev() const {return nev;}
        void setNev(std::string Nev) {nev = Nev;}
        int getVeteliAr() const {return veteliAr;}
        void setVeteliAr(int VeteliAr) {veteliAr = VeteliAr;}
        int getEladasiAr() const {return eladasiAr;}
        void setEladasiAr(int EladasiAr) {eladasiAr = EladasiAr;}
        int getTamadasPlusz() const {return tamadasPlusz;}
        void setTamadasPlusz(int TamadasPlusz) {tamadasPlusz = TamadasPlusz;}
        virtual void hasznal(Jatekos& jatekos)=0;
};

std::ostream& operator<<(std::ostream&,const Targy&);

#endif // TARGY_H
