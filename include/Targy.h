#ifndef TARGY_H
#define TARGY_H

/**
 * \file Targy.h
 *
 * Targy osztály deklarációja és globális függvényei
 */

#include <string>
class Jatekos;

/// Targy osztály
///
class Targy
{
    std::string nev; ///< Tárgy neve
    int veteliAr; ///< Tárgy vételi ára
    int eladasiAr; ///< Tárgy eladási ára
    int tamadasPlusz; ///< Tárgy plusz támadása

    public:
        /// Konstruktor beállítja az attribútumokat
        Targy();

        /// Több paraméteres konstruktor
        /// @param Nev - Tárgy neve
        /// @param VeteliAr - Tárgy vételi ára
        /// @param EladasiAr - Tárgy eladási ára
        /// @param TamadasPlusz - Tárgy plusz támadása
        Targy(std::string Nev, int VeteliAr, int EladasiAr, int TamadasPlusz);

        /// Virtuális destruktor
        virtual ~Targy();

        /// Név lekérdezése
        /// @return - Név
        std::string getNev() const {return nev;}

        /// Név beállítása
        /// @param Nev - Név
        void setNev(std::string Nev) {nev = Nev;}

        /// Vételi ár beállítása
        /// @return - Vételi ár
        int getVeteliAr() const {return veteliAr;}

        /// Vételi ár beállítása
        /// @param VeteliAr - Vételi ár
        void setVeteliAr(const int VeteliAr) {veteliAr = VeteliAr;}

        /// Eladási ár lekérdezése
        /// @return - Eladási ár
        int getEladasiAr() const {return eladasiAr;}

        /// Eladási ár beállítása
        /// @param EladasiAr - Eladási ár
        void setEladasiAr(const int EladasiAr) {eladasiAr = EladasiAr;}

        /// Plusz támadás lekérdezése
        /// @return - Plusz támadás
        int getTamadasPlusz() const {return tamadasPlusz;}

        /// Plusz támadás beállítása
        /// @param TamadasPlusz - Plusz támadás
        void setTamadasPlusz(const int TamadasPlusz) {tamadasPlusz = TamadasPlusz;}

        /// Tisztán virtuális tárgy használata
        /// @param jatekos - Játékos referencia
        virtual void hasznal(Jatekos& jatekos)=0;

        /// Tisztán virtuális tárgy vásárlása
        /// @param jatekos - Játékos referencia
        virtual void vasarol(Jatekos& jatekos)=0;
};

/// Globális inserter
/// @param out - output stream referencia
/// @param targy - Targy referencia
/// @return - output stream referencia
std::ostream& operator<<(std::ostream& out,const Targy& targy);

#endif // TARGY_H
