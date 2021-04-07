#ifndef ELLENSEG_H
#define ELLENSEG_H

/**
 * \file Ellenseg.h
 *
 * Ellenseg oszt�ly deklar�ci�ja �s glob�lis f�ggv�nyei
 */

#include "Karakter.h"
#include <string>


/// Ellenseg osztaly
///
class Ellenseg : public Karakter
{
    double maxTamadasSzorzo; ///< A v�grehajtott t�mad�s szorz�ja
    public:
        /// Konstruktor be�ll�tja az attrib�tumokat
        Ellenseg();

        /// Egy param�teres konstruktor, ami be�ll�tja az attrib�tumokat
        /// @param szint - J�t�kos szintje
        Ellenseg(int szint);

        /// T�bb param�teres konstruktor
        /// @param Nev - Az ellens�g neve
        /// @param Eletero - Az ellens�g �letereje
        /// @param Tapasztalat - Az ellens�g tapasztalati pontjai
        /// @param Arany - Az ellens�g �ltal birtokolt arany mennyis�ge
        /// @param MinSebzes - Az ellens�g �ltal okozott minim�lis sebz�s
        /// @param MaxSebzes - Az ellens�g �ltal okozott maxim�lis sebz�s
        /// @param Vedekezes - Az ellenf�l v�dekez�si k�pess�ge
        /// @param MaxTamadasSzorzo - Az ellenf�l �ltal v�grehajtott t�mad�s szorz�ja
        Ellenseg(std::string Nev,int Eletero,int Tapasztalat,int Arany,int MinSebzes,int MaxSebzes,int Vedekezes,double MaxTamadasSzorzo);

        /// Virtu�lis destruktor
        virtual ~Ellenseg();

        /// Az ellens�g �ltal v�grehajtott t�mad�s szorz�j�nak lek�rdez�se
        /// @return - t�mad�s szorz�
        double getMaxTamadasSzorzo() const {return maxTamadasSzorzo;}

        /// Az ellens�g �ltal v�grehajtott t�mad�s szorz�j�nak be�ll�t�sa
        /// @param MaxTamadasSzorzo - A t�mad�s szorz�ja
        void setMaxTamadasSzorzo(const double MaxTamadasSzorzo) {maxTamadasSzorzo = MaxTamadasSzorzo;}

        /// Ellens�g t�mad�si logik�ja
        /// @param kit - A megt�madni k�v�nt karakter referenci�ja
        void tamadas(Karakter& kit);
};

/// Glob�lis inserter
/// @param out - output stream referencia
/// @param ellenseg - Ellenseg referencia
/// @return output stream referencia
std::ostream& operator<<(std::ostream& out,const Ellenseg& ellenseg);

#endif // ELLENSEG_H
