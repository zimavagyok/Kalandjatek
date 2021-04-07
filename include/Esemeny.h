#ifndef ESEMENY_H
#define ESEMENY_H

/**
 * \file Esemeny.h
 *
 * Esemeny osztály deklarációja
 */

#include "Jatekos.h"
#include "Ellenseg.h"
#include "Targy.h"
#include <vector>

/// Esemeny osztály
///
class Esemeny
{
    public:
        /// Konstruktor, ami létrehozza az objektumot
        Esemeny();

        /// Virtuális destruktor
        virtual ~Esemeny();

        /// Utazás esemény véletlenszerű generálása
        /// @param jatekos - A játékos referenciája, akivel történik az esemény
        /// @param targyak - A játékban található tárgyak listája
        void generalEsemeny(Jatekos& jatekos,std::vector<Targy*> targyak, int iter);

        /// Bolt esemény logikája
        /// @param jatekos - A játékos referenciája, aki vásárol
        /// @param targyak - A játékban található tárgyak listája
        void boltTalalkozas(Jatekos& jatekos,std::vector<Targy*> targyak);

        /// Harc esemény logikája
        /// @param jatekos - A játékos referenciája, aki harcba keveredik
        /// @param maxEllenfelek - A maximális ellenfelek száma
        void ellenfelTalalkozas(Jatekos& jatekos, const int maxEllenfelek);
};

#endif // ESEMENY_H
