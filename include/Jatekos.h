#ifndef JATEKOS_H
#define JATEKOS_H

#include "Karakter.h"
#include "Ital.h"
#include "Fegyver.h"
#include <vector>

class Jatekos : public Karakter
{
    int szint;
    int kovetkezoSzint;
    int maxEletero;

    int ero;
    int eleteroSzint;

    int statPontok;

    std::vector<Ital*> italok;
    Fegyver *elsodlegesFegyver;

    public:
        Jatekos();
        void initJatekos(const std::string Nev) //done
        virtual ~Jatekos();

        int getMaxEletero() const {return maxEletero;}
        void setMaxEletero(int MaxEletero) {maxEletero = MaxEletero;}
        int getSzint() const {return szint;}
        void setSzint(int Szint) {szint = Szint;}
        int getKovetkezoSzint() const {return kovetkezoSzint;}
        void setKovetkezoSzint(int KovetkezoSzint) {kovetkezoSzint = KovetkezoSzint;}
        int getEro() const {return ero;}
        void setEro(int Ero) {ero = Ero;}
        int getEleteroSzint() const {return eleteroSzint;}
        void setEleteroSzint(int EleteroSzint) {eleteroSzint = EleteroSzint;}
        int getStatPontok() const {return statPontok;}
        void setStatPontok() {statPontok = StatPontok;}
        int getTargyakSzama() const {return targyak.size();}
        void tamadas(Karakter& kit);

        void Jatekos::stathozAdas(int stat, int value); //done
        void statFrissites(); //done
        void szintLepes(); //done
        void addItal(const Ital& ujItal); //done
        void removeItal(int index); //done
        const Ital& getItal(const int index) const; //done
        const Fegyver& getElsodlegesFegyver() const; //done
        void italokKilistazasa(); //done

        void setElsodlegesFegyver(const Fegyver& ujFegyver);
};

std::ostream& operator<<(std::ostream&, const Jatekos&);

#endif // JATEKOS_H
