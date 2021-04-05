#include "Esemeny.h"
#include "Kiegeszito.h"

Esemeny::Esemeny()
{
    //ctor
}

void Esemeny::generalEsemeny(Jatekos& jatekos, std::vector<Targy*> targyak)
{
    int randomSzam = rand() % 100 + 1;
    if(randomSzam>90)
    {
        this->boltTalalkozas(jatekos,targyak);
    }
    else
    {
        this->ellenfelTalalkozas(jatekos);
    }
}

void Esemeny::boltTalalkozas(Jatekos& jatekos,std::vector<Targy*> targyak)
{
    int valasztas = 0;
    bool vasarlas = true;
    elvalasztas();
    while(vasarlas)
    {
        std::cout << "Udvozollek a boltban! Mit szeretnel csinalni?\n";
        std::cout << "Aranyad: "<<jatekos.getArany()<<std::endl;
        std::cout << "0. Kilepes\n1. Vasarlas\n2. Eladas\n";
        std::cout << "Valasztas: ";
        std::cin>>valasztas;
        while(valasztas<0 || valasztas>2)
        {
            std::cout<<"Rossz valasztas!\n";
            std::cout << "Valasztas: ";
            std::cin>>valasztas;
        }
        if(valasztas==0)
        {
            vasarlas = false;
            std::cout<<"Talalkozunk legkozelebb!\n";
        }
        else if(valasztas==1)
        {
            elvalasztas();
            std::cout<<"A boltban talalhato targyak:\n";
            std::cout<<"-1. Kil�p�s\n";
            for(size_t i = 0;i<targyak.size();i++)
            {
                std::cout<<i<<". "<<targyak[i];
            }
            std::cout<<"Valasztas: ";
            int vasarlasValaszt = 0;
            std::cin>>vasarlasValaszt;
            while(vasarlasValaszt<-1 || (size_t)vasarlasValaszt>=targyak.size())
            {
                std::cout<<"Hibas valasztas!\n";
                std::cout<<"Valasztas: ";
                std::cin>>vasarlasValaszt;
            }
            if(vasarlasValaszt==-1)
            {
                std::cout<<"Legkozelebb!\n";
            }
            else
            {
                if(jatekos.getArany()>=targyak[vasarlasValaszt]->getEladasiAr())
                {
                    jatekos.levonArany(targyak[vasarlasValaszt]->getEladasiAr());
                    targyak[vasarlasValaszt]->vasarol(jatekos);
                    std::cout<<"Targy sikeresen megvasarolva!\n";
                }
                else
                {
                    std::cout<<"Nincs eleg penzed a vasarlashoz!\n";
                }
            }
        }
        else if(valasztas==2)
        {
            elvalasztas();
            if(jatekos.italokSzama()>0)
            {
                std::cout<<"A nalad levo italok: \n-1. Kilepes\n";
                jatekos.italokKilistazasa();
                std::cout<<"Valasztas: ";
                int eladasValasztas = 0;
                std::cin>>eladasValasztas;
                while(eladasValasztas<-1 || eladasValasztas>=jatekos.italokSzama())
                {
                    std::cout<<"Hibas valasztas!\n";
                    std::cout<<"Valasztas: ";
                    std::cin>>eladasValasztas;
                }
                if(eladasValasztas==-1)
                {
                    std::cout<<"Legkozelebb!\n";
                }
                else
                {
                    std::cout<<jatekos.getItal(eladasValasztas)->getVeteliAr()<<" aranyat kaptal!\n";
                    jatekos.eladItal(eladasValasztas);
                }
            }
            else
            {
                std::cout<<"Nincs nalad eladhato targy!\n";
            }
        }
    }
}

void Esemeny::ellenfelTalalkozas(Jatekos& jatekos)
{
    bool jatekosKor = false;
    int valasztas = 0;

    int random = rand() % 2 +1;
    if(random==1)
        jatekosKor = true;
    else
        jatekosKor = false;

    bool elfut = false;
    bool jatekosLegyozve = false;
    bool ellensegekLegyozve = false;

    std::vector<Ellenseg*> ellensegek;
    int ellenfelekSzama = rand() % 4 + 1;
    for(int i = 0;i<ellenfelekSzama;i++)
    {
        ellensegek.push_back(new Ellenseg(jatekos.getSzint() + rand()%2));
    }

    while(!elfut && ! jatekosLegyozve && !ellensegekLegyozve)
    {
        if(jatekosKor && !jatekosLegyozve)
        {
            elvalasztas();
            std::cout<<"==JATEKOS KOR==\n";
            std::cout<<"==HARC MENU==\n";
            std::cout<<"Eletero: "<<jatekos.getEletero() << " / " << jatekos.getMaxEletero() << std::endl;
            std::cout<<"0. Futas\n1. Tamadas\n2. Ital hasznalata\n";
            std::cout<<"Valasztas: ";
            std::cin>>valasztas;
            while(std::cin.fail() || valasztas > 2 || valasztas < 0)
            {
                std::cout<<"Rossz valasztas!\nValasztas: ";
                std::cin>>valasztas;
            }

            switch(valasztas)
            {
                case 0: elfut = true;
                        break;
                case 1: //TAMADAS
                    {
                        std::cout<<"Valaszd ki az ellenseget: \n";
                        for(size_t i = 0;i<ellensegek.size();i++)
                        {
                            std::cout<<i<<". :"<<ellensegek[i];
                        }

                        std::cout<<"Valasztas: ";
                        std::cin>>valasztas;

                        while(std::cin.fail() || (size_t)valasztas >= ellensegek.size() || valasztas<0)
                        {
                            std::cout<<"Rossz valasztas!\nValasztas: ";
                            std::cin>>valasztas;
                        }

                        int jatekosVeletlen = rand() % jatekos.getMaxEletero() + 1;
                        int ellenfelVeletlen = rand() % ellensegek[valasztas]->getEletero() + 1;
                        if(jatekosVeletlen > ellenfelVeletlen)
                        {
                            std::cout<<"TALALT!\n";
                            int sebzes = jatekos.getSebzes();
                            ellensegek[valasztas]->takeSebzes(sebzes);
                            std::cout<<"Sebzes: "<<sebzes<<"!\n";

                            if(!ellensegek[valasztas]->eletben())
                            {
                                std::cout<<"Ellenfel legyozve!\n";
                                int kapottTp = ellensegek[valasztas]->getTapasztalat();
                                int kapottArany = ellensegek[valasztas]->getArany();
                                jatekos.addArany(kapottArany);
                                jatekos.addTp(kapottTp);
                                std::cout<<"Kapott arany: "<<kapottArany<<"!\n";
                                std::cout<<"Kapott tp: "<<kapottTp<<"!\n";
                                delete ellensegek[valasztas];
                                ellensegek.erase(ellensegek.begin() + valasztas);
                            }
                        }
                        else
                        {
                            std::cout<<"NEM TALALT!\n";
                        }
                        break;
                    }
                case 2:
                    {
                        std::cout<<"Nalad levo targyak: \n";
                        std::cout<<"-1. Kilepes\n";
                        jatekos.italokKilistazasa();
                        std::cout<<"Valasztas: ";
                        std::cin>>valasztas;
                        while(std::cin.fail() || valasztas<-1 || valasztas >= jatekos.italokSzama())
                        {
                            std::cout<<"Hibas valasztas!\n";
                            std::cout<<"Valasztas: ";
                            std::cin>>valasztas;
                        }

                        if(valasztas==-1)
                        {
                            break;
                        }
                        else
                        {
                            if(jatekos.italokSzama()>0)
                            {
                                jatekos.addEletero(jatekos.getItal(valasztas)->getEleteroPlusz());
                                std::cout<<"Megittad az italt! Az uj eleterod: "<<jatekos.getEletero()<<std::endl;
                                jatekos.removeItal(valasztas);
                            }
                            else
                            {
                                std::cout<<"Nincs nalad ital!\n";
                            }
                        }
                        break;
                    }
                default: break;
            }
            jatekosKor = false;
        }
        else if(!jatekosKor && !jatekosLegyozve && !elfut && !ellensegekLegyozve)
        {
            elvalasztas();
            std::cout<<"==ELLENFEL KOR==\n";
            for(size_t i = 0;i<ellensegek.size();i++)
            {
                int jatekosVeletlen = rand() % jatekos.getMaxEletero() + 1;
                int ellenfelVeletlen = rand() % ellensegek[valasztas]->getEletero() + 1;
                if(jatekosVeletlen<ellenfelVeletlen)
                {
                    std::cout<<"TALALT!\n";
                    int sebzes = ellensegek[i]->getSebzes();
                    jatekos.takeSebzes(sebzes);

                    std::cout<<"Sebzes: "<<sebzes<<"!\n";
                    std::cout<<"Eletero: "<<jatekos.getEletero() << " / "<<jatekos.getMaxEletero()<<std::endl;

                    if(!jatekos.eletben())
                    {
                        std::cout<<"Legyoztek!\n";
                        jatekosLegyozve = true;
                    }
                }
                else
                {
                    std::cout<<"NEM TALALT!\n";
                }
            }
            jatekosKor = true;
        }

        if(!jatekos.eletben())
        {
            jatekosLegyozve = true;
            for(int i = ellensegek.size()-1;i>0;i++)
            {
                delete ellensegek[i];
                ellensegek.pop_back();
            }
        }
        else if(ellensegek.size() <= 0)
        {
            ellensegekLegyozve = true;
        }
    }
}

Esemeny::~Esemeny()
{
    //dtor
}
