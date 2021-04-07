#include "Esemeny.h"
#include "Kiegeszito.h"

Esemeny::Esemeny()
{
    //ctor
}

void Esemeny::generalEsemeny(Jatekos& jatekos, std::vector<Targy*> targyak)
{
    int randomSzam = rand() % 100 + 1;
    if(randomSzam>80)
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
            std::cin.clear();
			std::cin.ignore(100, '\n');
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
            std::cout<<"\nA boltban talalhato targyak:\n";
            std::cout<<"-1. Kilepes\n";
            for(size_t i = 0;i<targyak.size();i++)
            {
                std::cout<<i<<". "<<(*targyak[i]);
            }
            std::cout<<"Valasztas: ";
            int vasarlasValaszt = 0;
            std::cin>>vasarlasValaszt;
            while(vasarlasValaszt<-1 || vasarlasValaszt>=(int)targyak.size())
            {
                std::cout<<"Hibas valasztas!\n";
                std::cin.clear();
                std::cin.ignore(100, '\n');
                std::cout<<"Valasztas: ";
                std::cin>>vasarlasValaszt;
            }
            if(vasarlasValaszt==-1)
            {
                std::cout<<"Legkozelebb!\n";
            }
            else
            {
                if(jatekos.getArany()>=targyak[vasarlasValaszt]->getVeteliAr())
                {
                    jatekos.levonArany(targyak[vasarlasValaszt]->getVeteliAr());
                    targyak[vasarlasValaszt]->vasarol(jatekos);
                    std::cout<<"\nTargy sikeresen megvasarolva!\n";
                }
                else
                {
                    std::cout<<"\nNincs eleg penzed a vasarlashoz!\n";
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
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                    std::cout<<"Valasztas: ";
                    std::cin>>eladasValasztas;
                }
                if(eladasValasztas==-1)
                {
                    std::cout<<"Legkozelebb!\n";
                }
                else
                {
                    std::cout<<jatekos.getItal(eladasValasztas)->getEladasiAr()<<" aranyat kaptal!\n";
                    jatekos.eladItal(eladasValasztas);
                }
            }
            else
            {
                std::cout<<"Nincs nalad eladhato targy!\n\n";
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
    const int maxEllenfelek = 3;
    int ellenfelekSzama = rand() % maxEllenfelek + 1;
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
            std::cout<<"0. Futas\n1. Tamadas\n2. Ital hasznalata\n3. Ellensegek\n";
            std::cout<<"Valasztas: ";
            std::cin>>valasztas;
            while(std::cin.fail() || valasztas > 3 || valasztas < 0)
            {
                std::cout<<"Rossz valasztas!\n";
                std::cin.clear();
                std::cin.ignore(100, '\n');
                std::cout<<"Valasztas: ";
                std::cin>>valasztas;
            }

            switch(valasztas)
            {
                case 0: elfut = true;
                        std::cout<<"\n\nGYAVA!\n\n";
                        break;
                case 1: //TAMADAS
                    {
                        std::cout<<"Valaszd ki az ellenseget: \n";
                        for(size_t i = 0;i<ellensegek.size();i++)
                        {
                            elvalasztas();
                            std::cout<<i<<". :"<<(*ellensegek[i]);
                            elvalasztas();
                        }

                        std::cout<<"Valasztas: ";
                        std::cin>>valasztas;

                        while(std::cin.fail() || (size_t)valasztas >= ellensegek.size() || valasztas<0)
                        {
                            std::cout<<"Rossz valasztas!\n";
                            std::cin.clear();
                            std::cin.ignore(100, '\n');
                            std::cout<<"Valasztas: ";
                            std::cin>>valasztas;
                        }

                        int jatekosVeletlen = rand() % jatekos.getMaxEletero() + 1;
                        int ellenfelVeletlen = rand() % ellensegek[valasztas]->getEletero() + 10;
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
                        jatekosKor = false;
                        break;
                    }
                case 2:
                    {
                        if(jatekos.italokSzama()>0)
                        {
                            std::cout<<"Nalad levo targyak: \n";
                            std::cout<<"-1. Kilepes\n";
                            jatekos.italokKilistazasa();
                            std::cout<<"Valasztas: ";
                            std::cin>>valasztas;
                            while(std::cin.fail() || valasztas<-1 || valasztas >= jatekos.italokSzama())
                            {
                                std::cout<<"Hibas valasztas!\n";
                                std::cin.clear();
                                std::cin.ignore(100, '\n');
                                std::cout<<"Valasztas: ";
                                std::cin>>valasztas;
                            }

                            if(valasztas==-1)
                            {
                                break;
                            }
                            else
                            {
                                jatekos.addEletero(jatekos.getItal(valasztas)->getEleteroPlusz());
                                std::cout<<"Megittad az italt! Az uj eleterod: "<<jatekos.getEletero()<<std::endl;
                                jatekos.removeItal(valasztas);
                            }
                        }
                        else
                        {
                            std::cout<<"Nincs nalad ital!\n";
                        }
                        break;
                    }
                case 3:
                    {
                        for(size_t i = 0;i<ellensegek.size();i++)
                        {
                            elvalasztas();
                            std::cout<<i<<". :"<<(*ellensegek[i]);
                            elvalasztas();
                        }
                        break;
                    }
                default: break;
            }
        }
        else if(!jatekosKor && !jatekosLegyozve && !elfut && !ellensegekLegyozve)
        {
            elvalasztas();
            std::cout<<"==ELLENFEL KOR==\n";
            for(size_t i = 0;i<ellensegek.size();i++)
            {
                int jatekosVeletlen = rand() % jatekos.getMaxEletero() + 1;
                int ellenfelVeletlen = rand() % ellensegek[i]->getEletero() + 10;
                if(jatekosVeletlen<ellenfelVeletlen)
                {
                    std::cout<<"\nTALALT!\n";
                    int sebzes = ellensegek[i]->getSebzes();
                    jatekos.takeSebzes(sebzes);

                    std::cout<<"Sebzes: "<<sebzes<<"!\n";
                    std::cout<<"Eleterod: "<<jatekos.getEletero() << " / "<<jatekos.getMaxEletero()<<std::endl;

                    if(!jatekos.eletben())
                    {
                        std::cout<<"Legyoztek!\n";
                        jatekosLegyozve = true;
                        break;
                    }
                }
                else
                {
                    std::cout<<"\nNEM TALALT!\n";
                }
            }
            jatekosKor = true;
        }

        if(!jatekos.eletben())
        {
            jatekosLegyozve = true;
        }
        else if(ellensegek.size() <= 0)
        {
            ellensegekLegyozve = true;
        }
    }
    for(size_t i = ellensegek.size();i>0;i--)
    {
        delete ellensegek[i-1];
        ellensegek.pop_back();
    }
}

Esemeny::~Esemeny()
{
    //dtor
}
