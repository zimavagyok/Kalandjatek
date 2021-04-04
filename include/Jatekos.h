#ifndef JATEKOS_H
#define JATEKOS_H

#include "Karakter.h"
#include <vector>

class Jatekos : public Karakter
{
    int szint;
    int kovetkezoSzint;
    int maxEletero;

    int ero;
    int eleteroSzint;

    int statPontok;

    std::vector<Targy*> targyak;
    Targy *elsodlegesFegyver;

    public:
        Jatekos();
        void initJatekos(const std::string); //done
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
        void tamadas(Karakter&, Karakter&);

        void stathozAdas(int stat, int value); //done
        void statFrissites(); //done
        void szintLepes(); //done
        bool tartalmazTargy(const Targy&) const; //done
        void addTargy(const Targy&); //done
        void removeTargy(int); //done
        const Targy& getTargy(const int index) const; //done
        const Targy& getElsodlegesFegyver() const; //done
        void targyakKilistazasa(); //done

        void setElsodlegesFegyver(const Targy& ujTargy) {elsodlegesFegyver = ujTargy.clone();}
};

std::ostream& operator<<(std::ostream&, const Jatekos&);

#endif // JATEKOS_H
