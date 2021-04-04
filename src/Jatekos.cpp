#include "Jatekos.h"
#include "Ellenseg.h"

#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>

Jatekos::Jatekos() : Karakter("",0,0,0,0,0,0),szint(0),kovetkezoSzint(0),maxEletero(0),ero(0),eleteroSzint(0),statPontok(0),elsodlegesFegyver(NULL)
{
}

void Jatekos::initJatekos(const std::string Nev)
{
    setNev(Nev);
    setArany(100);
    szint = 1;
    setTapasztalat(0);
    setVedekezes(10);

    ero = 5;
    eleteroSzint = 5;

    statPontok = 0;

    this->statFrissites();
}

void Jatekos::statFrissites()
{
    kovetkezoSzint = (int)((50/3)*szint*szint- 6*szint*szint + 17*szint - 12 + 100);
    maxEletero = eleteroSzint*5 + ero + szint*5;
    setMinSebzes(ero);
    setMaxSebzes(ero+10);
    setEletero(maxEletero);
}

void Jatekos::stathozAdas(int stat, int value)
{
    if(stat == 0)
    {
        ero += value;
        std::cout<<"Megnovelted az erodet!\n";
    }
    else
    {
        eleteroSzint += value;
        std::cout<<"Megnovelted az eleteroszinted!\n";
    }

    this->statFrissites();
}

void Jatekos::szintLepes()
{
    if(getTapasztalat() > kovetkezoSzint)
    {
        setTapasztalat(getTapasztalat()-kovetkezoSzint);
        szint++;
        statPontok++;

        this->statFrissites();

        std::cout<<"Szintet leptel! Az uj szinted: "<<szint<<std::endl;
    }
    else
    {
        std::cout<<"Nincs eleg tapasztalatod a szintlepeshez!\n";
    }
}

void Jatekos::addItal(const Ital& ujItal)
{
    italok.push_back(ujItal.clone());
    std::cout<<"Sikeres hozzaadas!\n";
}

void Jatekos::removeTargy(int index)
{
    if(index<0 || index>italok.size()-1)
        std::cout<<"Nem lehet torolni a megadott elemet!\n";
    else
    {
        delete italok[i];
        italok.erase(italok.begin() + index);
        std::cout<<"Ital sikeresen eltavolitva az italjaid kozul!\n";
    }
}

const Ital& Jatekos::getItal(const int index) const
{
    if(index>ital.size()-1 || index < 0)
    {
        std::cout<<"Nincs nalad ennyi ital!\n";
        return NULL;
    }
    else
        return italok[i];
}

const Fegyver& Jatekos::getElsodlegesFegyver() const
{
    if(elsodlegesFegyver!=NULL)
        return elsodlegesFegyver;
    else
    {
        std::cout<<"Nincs fegyvered!\n";
        return NULL;
    }
}

void Jatekos::italokKilistazasa()
{
    if(italok.size()>0)
    {
        for(size_t i = 0;i<italok.size();i++)
        {
            std::cout << italok[i];
        }
    }
    else
    {
        std::cout<<"Nincs nalad egy ital sem...\n";
    }
}

void Jatekos::tamadas(Karakter& kit)
{
    int mennyi = 0;
    if(getElsodlegesFegyver!=NULL)
    {
        mennyi += getElsodlegesFegyver().getTamadasPlusz();
        int esely = rand() % 10 + 1;
        if(esely > 7)
        {
            mennyi += getElsodlegesFegyver().getKri
        }
    }
    mennyi += getSebzes()-(0.5*kit.getVedekezes());
    kit.takeSebzes(mennyi);
    std::cout<<"Az altalad kioszott sebzes: "<<mennyi<<std::endl;
}

std::ostream& operator<<(std::ostream& out, const Jatekos& jatekos)
{
    out << (Karakter&)jatekos
        << "Szint: " << jatekos.getSzint()
        << "\nKovetkezo szinthez szukseges tapasztalat: " << jatekos.getKovetkezoSzint()
        << "\nEro: " << jatekos.getEro()
        << "\nEletero szint: " << jatekos.getEleteroSzint();
        << "\nFelhasznalhato statisztika pontjaid: " << jatekos.getStatPontok()
        << "\nFegyvered: " << jatekos.getElsodlegesFegyver() == NULL ? "Nincs" : jatekos.getElsodlegesFegyver()
        << "\nNalad levo targyak: \n" << jatekos.targyakKilistazasa() << std::endl;
}

void Jatekos::setElsodlegesFegyver(const Fegyver& ujFegyver)
{
    if(elsodlegesFegyver==NULL)
    {
        delete elsodlegesFegyver;
    }
    elsodlegesFegyver = ujTargy.clone();
}

Jatekos::~Jatekos()
{
    if(elsodlegesFegyver!=NULL)
    {
        delete elsodlegesFegyver;
    }
    if(targyak.size()>0)
    {
        for(size_t i = targyak.size();i>0;i--)
        {
            delete targyak[i];
            targyak.pop_back();
        }
    }
}
