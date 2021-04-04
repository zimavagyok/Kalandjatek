#ifndef KARAKTER_H
#define KARAKTER_H

#include <string>

class Karakter
{
    std::string nev;
    int eletero;
    int tapasztalat;
    int arany;
    int minSebzes;
    int maxSebzes;
    int vedekezes;
    public:
        Karakter();
        Karakter(std::string,int,int,int,int,int,int);
        virtual ~Karakter();

        std::string getNev() const {return nev;}
        void setNev(std::string Nev) {nev = Nev;}
        int getEletero() const {return eletero;}
        void setEletero(int Eletero) {eletero = Eletero;}
        int getTapasztalat() const {return tapasztalat;}
        void setTapasztalat(int Tapasztalat) {return tapasztalat = Tapasztalat;}
        int getArany() const {return arany;}
        void setArany(int Arany) {arany = Arany;}
        int getMinSebzes() const {return minSebzes;}
        void setMinSebzes(int MinSebzes) {minSebzes = MinSebzes;}
        int getMaxSebzes() const {return maxSebzes;}
        void setMaxSebzes(int MaxSebzes) {maxSebzes = MaxSebzes;}
        int getVedekezes() const {return vedekezes;}
        void setVedekezes(int Vedekezes) {vedekezes = Vedekezes;}
        int getSebzes() const {return rand() % maxSebzes + minSebzes;}
        void addEletero(int mennyit) {eletero += mennyit;}
        virtual void tamadas(Karakter&, Karakter&) = 0;

        void takeSebzes(int Sebzes);
        bool eletben() {return eletero > 0;}
};

std::ostream& operator<<(std::ostream&, const Karakter&);

#endif // KARAKTER_H
