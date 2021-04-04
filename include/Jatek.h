#ifndef JATEK_H
#define JATEK_H


class Jatek
{
    int valasztas;
    bool jatekFut;
    Karakter jatekos;
    std::vector<Targy*> betoltottTargyak;

    public:
        Jatek();
        virtual ~Jatek();

        void initJatek();
        void foMenu();
        void jatekMenu();
        void ujJatekosKeszitese();
        void karakterSzintlepes();
        void utazas();
        void pihenes();
};

#endif // JATEK_H
