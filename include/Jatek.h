#ifndef JATEK_H
#define JATEK_H

/**
 * \file Jatek.h
 *
 * Jatek osztály deklarációja
 */

#include "Jatekos.h"
#include "Targy.h"
#include "Jatek.h"
#include "memtrace.h"
#include <iostream>

/// Jatek osztály
///
class Jatek
{
    int valasztas; ///< Kiválasztott opció
    bool jatekFut; ///< Játék futását figyeli változó
    Jatekos* jatekos; ///< Játékos karakterére mutató pointer
    std::vector<Targy*> betoltottTargyak; ///< A játékba betöltött tárgyak listája

    public:
        /// Konstruktor beállítja az attribútumokat
        Jatek();

        /// Jatekos lekerdezese
        Jatekos* getJatekos() const { return jatekos;}

        /// Tárgyak lekérdezése
        std::vector<Targy*> getBetoltottTargyak() const {return betoltottTargyak;}

        /// Virtuális destruktor
        virtual ~Jatek();

        /// A játék kezdeti inicializációja, fájlokból való beolvasás
        void initJatek();

        /// A játék főmenüjét megvalósító függvény
        void foMenu();

        /// A játék futás közbeni menüje
        void jatekMenu();

        /// A karakter információ lekérdező menüje
        void karakterMenu();

        /// Új játékos készítése
        void ujJatekosKeszitese();

        /// Karakter szintjét kezelő menü
        void karakterSzintlepes();

        /// Utazás megvalósítása
        /// @param iter - Iteráció száma
        void utazas(int iter = 1);

        /// Pihenés megvalósítása
        void pihenes();
};

#endif // JATEK_H
