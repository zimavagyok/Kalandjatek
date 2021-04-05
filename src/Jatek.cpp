#include "Jatek.h"
#include "Esemeny.h"
#include "Kiegeszito.h"
#include <iostream>
#include <fstream>

Jatek::Jatek()
{
    valasztas = 0;
    jatekFut = true;
    jatekos = NULL;
}

void Jatek::initJatek()
{
    std::ifstream fegyverek;
    fegyverek.open("fegyverek.txt",std::ifstream::in);
    if(!fegyverek.is_open())
    {
        std::cout<<"Nem sikerult a Fegyver fajl megnyitasa!\n";
    }
    else
    {
        int hossz;
        fegyverek >> hossz;
        std::string nev;
        int vet,ela,tamP,krit;
        for(int i = 0;i<hossz;i++)
        {
            fegyverek >> nev >> vet >> ela >> tamP >> krit;
            Fegyver* ujFegyver = new Fegyver(nev,vet,ela,tamP,krit);
            betoltottTargyak.push_back(ujFegyver);
        }
    }
    fegyverek.close();

    std::ifstream italok;
    italok.open("italok.txt",std::ifstream::in);
    if(!italok.is_open())
    {
        std::cout<<"Nem sikerult az Italok fajl megnyitasa!\n";
    }
    else
    {
        int hossz;
        italok >> hossz;
        std::string nev;
        int vet,ela,tamP,eletP;
        for(int i = 0;i<hossz;i++)
        {
            italok >> nev >> vet >> ela >> tamP >> eletP;
            Ital* ujItal = new Ital(nev,vet,ela,tamP,eletP);
            betoltottTargyak.push_back(ujItal);
        }
    }
    italok.close();

    if(betoltottTargyak.size()==0)
    {
        std::cout<<"Nem sikerult az adatok betoltese!\n";
        jatekFut = false;
    }
}

void Jatek::foMenu()
{
    std::cout<<"Udvozollek a jatekban! Valassz a kovetkezo menupontok kozul!\n";
    std::cout <<"1. Kilepes\n2. Jatek inditasa\n";
    std::cout<<"Valasztasod: ";
    std::cin >> valasztas;
    while(valasztas<1 || valasztas > 2)
    {
        std::cout<<"Hibas valasztas!\n";
        std::cout<<"Valasztasod: ";
        std::cin >> valasztas;
    }
    if(valasztas==1)
    {
        jatekFut = false;
        std::cout<<"A viszont latasra!\n";
    }
    else
    {
        elvalasztas();
        this->initJatek();
        if(betoltottTargyak.size()!=0)
            this->ujJatekosKeszitese();
        if(jatekos!=NULL)
        {
            std::cout<<"Jatekos sikeresen letrehozva!\n";
            this->jatekMenu();
        }
        else if(betoltottTargyak.size()==0)
        {
            std::cout<<"Hiba tortent a targyak betoltese kozben!\n";
            jatekFut = false;
        }
        else
        {
            std::cout<<"Hiba tortent a jatekos letrehozasa soran!\n";
            jatekFut = false;
        }
    }
}

void Jatek::ujJatekosKeszitese()
{
    std::cout<<"Hozz letre egy uj jatekost!\nNev:";
    std::string nev;
    std::cin >> nev;
    jatekos = new Jatekos();
    jatekos->initJatekos(nev);
}

void Jatek::jatekMenu()
{
    while(jatekFut && jatekos->eletben())
    {
        elvalasztas();
        std::cout<<"Udvozollek "<<jatekos->getNev()<<"! Valassz az alabbi lehetosegek kozul!\n";
        if(jatekos->getTapasztalat() >= jatekos->getKovetkezoSzint())
        {
            std::cout<<"==SZINT LEPES LEHETSEGES==\n";
        }
        std::cout<<"0. Kilepes\n1. Utazas\n2. Pihenes\n3. Karakter statisztikai\n4. Szintlepes\nValasztas: ";
        std::cin >> valasztas;
        while(std::cin.fail() || valasztas<0 || valasztas>4)
        {
            std::cout<<"Hibas valasztas!\n";
            std::cout<<"Valasztas: ";
            std::cin >> valasztas;
        }
        if(valasztas==0)
        {
            jatekFut = false;
            std::cout<<"A viszont latasra!\n";
        }
        else if(valasztas==1)
        {
            this->utazas();
        }
        else if(valasztas==2)
        {
            this->pihenes();
        }
        else if(valasztas==3)
        {
            this->karakterMenu();
        }
        else if(valasztas==4)
        {
            this->karakterSzintlepes();
        }
    }
    if(!jatekos->eletben())
    {
        std::cout<<"LEGYOZTEK!\n";
        jatekFut = false;
    }
}

void Jatek::utazas()
{
    Esemeny esemeny;

    elvalasztas();
    esemeny.generalEsemeny(*jatekos,betoltottTargyak);
}

void Jatek::pihenes()
{
    int pihenesAr = (jatekos->getMaxEletero() - jatekos->getEletero()) / 2;
    elvalasztas();
    std::cout<<"==PIHENES==\n";
    std::cout<<"A pihenes ara: "<<pihenesAr<<std::endl;
    std::cout<<"A te penzed: "<<jatekos->getArany()<<std::endl;

    if(jatekos->getArany() < pihenesAr)
    {
        std::cout<<"Sajnos nincs eleg aranyad a piheneshez!\n";
    }
    else if(jatekos->getEletero() >= jatekos->getMaxEletero())
    {
        std::cout<<"Nem tudsz tobbet pihenni!\n";
    }
    else
    {
        std::cout<<"Szeretnel pihenni? (1) Igen : (2) Nem\n";
        std::cout<<"Valasztas: ";
        int pihenesValasztas;
        std::cin >> pihenesValasztas;
        while(std::cin.fail() || pihenesValasztas<1 || pihenesValasztas>2)
        {
            std::cout<<"Hibas valasztas!\n";
            std::cout<<"Valasztas: ";
            std::cin >> pihenesValasztas;
        }

        if(pihenesValasztas==1)
        {
            jatekos->maxElet();
            jatekos->levonArany(pihenesAr);
            std::cout<<"Pihentel!\n";
        }
        else
        {
            std::cout<<"Talalkozunk legkozelebb!\n";
        }
    }
}

void Jatek::karakterSzintlepes()
{
    elvalasztas();
    if(jatekos->getTapasztalat() >= jatekos->getKovetkezoSzint())
        jatekos->szintLepes();

    std::cout<<"Kepessegeid szintjei:\nEro:"<<jatekos->getEro()<<"\nEletero szint:"<<jatekos->getEleteroSzint()<<std::endl;
    std::cout<<"Felhasznalhato stat pontjaid: "<<jatekos->getStatPontok()<<std::endl;
    if(jatekos->getStatPontok()>0)
    {
        std::cout<<"==SZINT NOVELESE==\n0. Kilepes\n1. Ero\n2. Eletero szint\nValasztas: ";
        int statValasztas;
        std::cin >> statValasztas;
        while(std::cin.fail() || statValasztas<0 || statValasztas>2)
        {
            std::cout<<"Hibas valasztas!\nValasztas: ";
            std::cin>>statValasztas;
        }
        if(statValasztas==0)
        {
        }
        else if(statValasztas==1)
        {
            jatekos->stathozAdas(0,1); //ERO
        }
        else
        {
            jatekos->stathozAdas(1,1); //ELETERO SZINT
        }
    }
}

void Jatek::karakterMenu()
{
    elvalasztas();
    std::cout<<"==KARAKTER MENU==\n";
    std::cout<<"0. Kilepes\n1. Jatekos info\n2. Italok kilistazasa\n3. Fegyvered\n";
    std::cout<<"Valasztas: ";
    int invValasztas;
    std::cin >> invValasztas;
    while(std::cin.fail() || invValasztas<0 || invValasztas>3)
    {
        std::cout<<"Hibas valasztas!\n";
        std::cout<<"Valasztas: ";
        std::cin>>invValasztas;
    }
    if(invValasztas==0)
    {
        //
    }
    else if(invValasztas==1)
    {
        elvalasztas();
        std::cout<< (*jatekos);
    }
    else if(invValasztas==2)
    {
        elvalasztas();
        jatekos->italokKilistazasa();
    }
    else if(invValasztas==3)
    {
        if(jatekos->getElsodlegesFegyver() != NULL)
        {
            std::cout<<(*jatekos->getElsodlegesFegyver());
        }
        else
        {
            std::cout<<"Nincs fegyvered!\n";
        }
    }
}

Jatek::~Jatek()
{
    if(jatekos!=NULL)
        delete jatekos;
    if(betoltottTargyak.size() > 0)
    {
        for(size_t i = betoltottTargyak.size();i>0;i--)
        {
            delete betoltottTargyak[i-1];
            betoltottTargyak.pop_back();
        }
    }
}
