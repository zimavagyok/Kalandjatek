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
        void initJatekos(const std::string Nev); //done
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
        void maxElet() {setEletero(maxEletero);}
        int getStatPontok() const {return statPontok;}
        void setStatPontok(int StatPontok) {statPontok = StatPontok;}
        void tamadas(Karakter& kit);

        void stathozAdas(int stat, int value); //done
        void statFrissites(); //done
        void szintLepes(); //done
        void addItal(const Ital& ujItal); //done
        void removeItal(const int index); //done
        Ital* getItal(const int index) const; //done
        void eladItal(const int index);
        int italokSzama() {return italok.size();}
        Fegyver* getElsodlegesFegyver() const; //done
        void italokKilistazasa(); //done

        void setElsodlegesFegyver(const Fegyver& ujFegyver);
};

std::ostream& operator<<(std::ostream&, const Jatekos&);

#endif // JATEKOS_H
