#include "Jatek.h"

Jatek::Jatek()
{
    valasztas = 0;
    jatekFut = true;
    jatekos = NULL;
}

void Jatek::initJatek()
{
    if(betoltottTargyak.size()==0)
    {
        std::cout<<"Nem sikerult az adatok betoltese!\n";
        jatekFut = false;
    }
}

void Jatek::foMenu()
{
    std::cout<<"Udvozollek a jatekban! Valassz a kovetkezo menupontok kozul!\n";
    std::cout <<"0. Kilépés\n1.Jatek inditasa\n";
    std::cout<<"Valasztasod: ";
    std::cin >> valasztas;
    while(valasztas<0 || valasztas > 1)
    {
        std::cout<<"Hibas valasztas!\n";
        std::cout<<"Valasztasod: ";
        std::cin >> valasztas;
    }
    if(valasztas==0)
    {
        jatekFut = false;
        std::cout<<"A viszont latasra!\n";
    }
    else
    {
        elvalasztas();
        this->initJatek();
        this->ujJatekosKeszitese();
        if(jatekos!=NULL)
        {
            std::cout<<"Jatekos sikeresen letrehozva!\n";
            this->jatekMenu();
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
    jatekos.initJatekos(nev);
}

void Jatek::jatekMenu()
{
    while(jatekFut || jatekos.eletben())
    {
        elvalasztas();
        std::cout<<"Udvozollek "<<jatekos.getNev()<<"! Valassz az alabbi lehetosegek kozul!\n";
        if(jatekos.getTapasztalat() >= jatekos.getKovetkezoSzint())
        {
            std::cout<<"==SZINT LEPES LEHETSEGES==";
        }
        std::cout<<"0. Kilepes\n1. Utazas\n2. Pihenes\n3. Karakter statisztikai\n4. Szintlepes\nValasztas: ";
        std::cin >> valasztas;
        while(valasztas<0 || valasztas>4)
        {
            std::cout<<"Hibas valasztas!\n";
            std::cout<<"Valasztas: ";
            cin >> valasztas;
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
}

void Jatek::utazas()
{
    Esemeny esemeny;

    elvalasztas();
    esemeny.generalEsemeny(jatekos,betoltottTargyak);
}

void Jatek::pihenes()
{
    int pihenesAr = (jatekos.getMaxEletero() - jatekos.getEletero()) / 2;
    elvalasztas();
    std::cout<<"==PIHENES==\n";
    std::cout<<"A pihenes ara: "<<pihenesAr<<std::endl;
    std::cout<<"A te penzed: "<<jatekos.getArany()<<std::endl;

    if(jatekos.getArany < pihenesAr)
    {
        std::cout<<"Sajnos nincs eleg aranyad a piheneshez!\n";
    }
    else if(jatekos.getEletero >= jatekos.getMaxEletero)
    {
        std::cout<<"Nem tudsz tobbet pihenni!\n";
    }
    else
    {
        std::cout<<"Szeretnel pihenni? (1) Igen : (2) Nem\n";
        std::cout<<"Valasztas: ";
        int pihenesValasztas;
        std::cin >> pihenesValasztas;
        while(pihenesValasztas<1 || pihenesValasztas>2)
        {
            std::cout<<"Hibas valasztas!\n";
            std::cout<<"Valasztas: ";
            std::cin >> pihenesValasztas;
        }

        if(pihenesValasztas==1)
        {
            jatekos.maxElet();
            jatekos.levonArany(pihenesAr);
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
    if(jatekos.getTapasztalat >= jatekos.getKovetkezoSzint())
        jatekos.szintLepes();

    std::cout<<"Kepessegeid szintjei:\nEro:"<<jatekos.getEro()<<"\nEletero szint:"<<jatekos.getEleteroSzint()<<std::endl;
    std::cout<<"Felhasznalhato stat pontjaid: "<<jatekos.getStatPontok()<<std::endl;
    if(jatekos.getStatPontok()>0)
    {
        std::cout<<"==SZINT NOVELESE==\n0. Kilepes\n1. Ero\n2. Eletero szint\nValasztas: ";
        int statValasztas;
        cin >> statValasztas;
        while(statValasztas<0 || statValasztas>2)
        {
            std::cout<<"Hibas valasztas!\nValasztas: ";
            cin>>statValasztas;
        }
        if(statValasztas==0)
        {
            break;
        }
        else if(statValasztas==1)
        {
            jatekos.stathozAdas(0,1); //ERO
        }
        else
        {
            jatekos.statFrissites(1,1); //ELETERO SZINT
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
    while(invValasztas<0 || invValasztas>3)
    {
        std::cout<<"Hibas valasztas!\n";
        std::cout<<"Valasztas: ";
        std::cin>>invValasztas;
    }
    if(invValasztas==0)
    {
        break;
    }
    else if(invValasztas==1)
    {
        std::cout<<jatekos;
    }
    else if(invValasztas==2)
    {
        jatekos.italokKilistazasa();
    }
    else if(invValasztas==3)
    {
        if(jatekos.getElsodlegesFegyver() != NULL)
        {
            std::cout<<jatekos.getElsodlegesFegyver();
        }
        else
        {
            std::cout<<"Nincs fegyvered!\n";
        }
    }
}

Jatek::~Jatek()
{
    //dtor
}
