#ifndef TARGY_H
#define TARGY_H

#include <string>
class Jatekos;

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
        virtual void vasarol(Jatekos&)=0;
};

std::ostream& operator<<(std::ostream&,Targy&);

#endif // TARGY_H
