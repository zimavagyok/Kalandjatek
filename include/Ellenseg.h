#ifndef ELLENSEG_H
#define ELLENSEG_H

/**
 * \file Ellenseg.h
 *
 * Ellenseg osztály deklarációja és globális függvényei
 */

#include "Karakter.h"
#include <string>


/// Ellenseg osztaly
///
class Ellenseg : public Karakter
{
    double maxTamadasSzorzo; ///< A végrehajtott támadás szorzója
    public:
        /// Konstruktor beállítja az attribútumokat
        Ellenseg();

        /// Egy paraméteres konstruktor, ami beállítja az attribútumokat
        /// @param szint - Játékos szintje
        Ellenseg(int szint);

        /// Több paraméteres konstruktor
        /// @param Nev - Az ellenség neve
        /// @param Eletero - Az ellenség életereje
        /// @param Tapasztalat - Az ellenség tapasztalati pontjai
        /// @param Arany - Az ellenség által birtokolt arany mennyisége
        /// @param MinSebzes - Az ellenség által okozott minimális sebzés
        /// @param MaxSebzes - Az ellenség által okozott maximális sebzés
        /// @param Vedekezes - Az ellenfél védekezési képessége
        /// @param MaxTamadasSzorzo - Az ellenfél által végrehajtott támadás szorzója
        Ellenseg(std::string Nev,int Eletero,int Tapasztalat,int Arany,int MinSebzes,int MaxSebzes,int Vedekezes,double MaxTamadasSzorzo);

        /// Virtuális destruktor
        virtual ~Ellenseg();

        /// Az ellenség által végrehajtott támadás szorzójának lekérdezése
        /// @return - támadás szorzó
        double getMaxTamadasSzorzo() const {return maxTamadasSzorzo;}

        /// Az ellenség által végrehajtott támadás szorzójának beállítása
        /// @param MaxTamadasSzorzo - A támadás szorzója
        void setMaxTamadasSzorzo(const double MaxTamadasSzorzo) {maxTamadasSzorzo = MaxTamadasSzorzo;}

        /// Ellenség támadási logikája
        /// @param kit - A megtámadni kívánt karakter referenciája
        void tamadas(Karakter& kit);
};

/// Globális inserter
/// @param out - output stream referencia
/// @param ellenseg - Ellenseg referencia
/// @return output stream referencia
std::ostream& operator<<(std::ostream& out,const Ellenseg& ellenseg);

#endif // ELLENSEG_H
