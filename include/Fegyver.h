#ifndef FEGYVER_H
#define FEGYVER_H

#include "Targy.h"
#include <string>

class Fegyver : public Targy
{
    int kritikusSebzes;

    public:
        Fegyver();
        Fegyver(std::string Nev,int VeteliAr,int EladasiAr,int TamadasPlusz,int KritikusSebzes);
        virtual ~Fegyver();

        int getKritikusSebzes() const {return kritikusSebzes;}
        void setKritikusSebzes(int KritikusSebzes) {kritikusSebzes = KritikusSebzes;}
        Fegyver* clone() const;
        void hasznal(Jatekos& jatekos);
        void vasarol(Jatekos&);
};

std::ostream& operator<<(std::ostream& out,const Fegyver& fegyver);

#endif // FEGYVER_H
