#ifndef FEGYVER_H
#define FEGYVER_H

/**
 * \file Fegyver.h
 *
 * Fegyver osztály deklarációja és globális függvényei
 */

#include "Targy.h"
#include <string>

/// Fegyver osztály
///
class Fegyver : public Targy
{
    int kritikusSebzes; ///< A fegyver által okozott kritikus sebzés

    public:
        /// Konstruktor beállítja az attribútumokat
        Fegyver();

        /// Több paraméteres konstruktor, ami beállítja az attribútumokat
        /// @param Nev - A fegyver neve
        /// @param VeteliAr - A fegyver vételi ára
        /// @param EladasiAr - A fegyver eladási ára
        /// @param TamadasPlusz - A fegyver által okozott plusz sebzés
        /// @param KritikusSebzes - A fegyver által okozott kritikus sebzés
        Fegyver(std::string Nev,int VeteliAr,int EladasiAr,int TamadasPlusz,int KritikusSebzes);

        // Virtuális destruktor
        virtual ~Fegyver();

        /// Kritikus sebzés lekérdezése
        /// @return - kritikus sebzés
        int getKritikusSebzes() const {return kritikusSebzes;}

        /// Kritikus sebzés beállítása
        /// @param KritikusSbezes - Kritikus sebzés mértéke
        void setKritikusSebzes(int KritikusSebzes) {kritikusSebzes = KritikusSebzes;}

        /// Fegyver klónozása
        /// @return - A fegyver másolatára mutató pointer
        Fegyver* clone() const;

        /// A fegyver használata
        /// @param jatekos - A játékos referenciája aki használja
        void hasznal(Jatekos& jatekos);

        /// A fegyver megvásárlása
        /// @param jatekos - Referencia a vásárlóra
        void vasarol(Jatekos& jatekos);
};

/// Globális inserter
/// @param out - output stream referencia
/// @param fegyver - Fegyver referencia
/// @return - output stream referencia
std::ostream& operator<<(std::ostream& out,const Fegyver& fegyver);

#endif // FEGYVER_H
