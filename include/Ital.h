#ifndef ITAL_H
#define ITAL_H

/**
 * \file Ital.h
 *
 * Ital osztály deklarációja
 */

#include "Targy.h"
class Jatekos;

/// Ital osztály
///
class Ital : public Targy
{
    int eleteroPlusz; ///< Ital által feltöltött életerő

    public:
        /// Konstruktor beállítja az attribútumokat
        Ital();

        /// Több paraméteres konstruktor
        /// @param Nev - Az ital neve
        /// @param VeteliAr - Az ital vételi ára
        /// @param EladasiAr - Az ital eladási ára
        /// @param TamadasPlusz - Az ital által okozott plusz sebzés
        /// @param EleteroPlusz - Az ital által feltöltött életerő
        Ital(std::string Nev,int VeteliAr,int EladasiAr,int TamadasPlusz,int EleteroPlusz);

        /// Virtuális destruktor
        virtual ~Ital();

        /// Ital által feltöltött életerő lekérdezése
        /// @return - ital által feltöltött életerő
        int getEleteroPlusz() const {return eleteroPlusz;}

        /// Ital által feltöltött életerő beállítása
        /// @param EleteroPlusz - Ital által feltöltött életerő
        void setEleteroPlusz(int EleteroPlusz) {eleteroPlusz = EleteroPlusz;}

        /// Ital klónozása
        /// @return - Az ital másolatára mutató pointer
        Ital* clone() const;

        /// Ital használata
        /// @param jatekos - A használó játékos referenciája
        void hasznal(Jatekos& jatekos);

        /// Ital megvásárlása
        /// @param jatekos - A használó játékos referenciája
        void vasarol(Jatekos& jatekos);
};


/// Globális inserter
/// @param out - output stream referencia
/// @param ital - Ital referencia
/// @return - output stream referencia
std::ostream& operator<<(std::ostream& out, const Ital& ital);

#endif // ITAL_H
