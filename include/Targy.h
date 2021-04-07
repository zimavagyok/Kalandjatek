#ifndef TARGY_H
#define TARGY_H

/**
 * \file Targy.h
 *
 * Targy oszt�ly deklar�ci�ja �s glob�lis f�ggv�nyei
 */

#include <string>
class Jatekos;

/// Targy oszt�ly
///
class Targy
{
    std::string nev; ///< T�rgy neve
    int veteliAr; ///< T�rgy v�teli �ra
    int eladasiAr; ///< T�rgy elad�si �ra
    int tamadasPlusz; ///< T�rgy plusz t�mad�sa

    public:
        /// Konstruktor be�ll�tja az attrib�tumokat
        Targy();

        /// T�bb param�teres konstruktor
        /// @param Nev - T�rgy neve
        /// @param VeteliAr - T�rgy v�teli �ra
        /// @param EladasiAr - T�rgy elad�si �ra
        /// @param TamadasPlusz - T�rgy plusz t�mad�sa
        Targy(std::string Nev, int VeteliAr, int EladasiAr, int TamadasPlusz);

        /// Virtu�lis destruktor
        virtual ~Targy();

        /// N�v lek�rdez�se
        /// @return - N�v
        std::string getNev() const {return nev;}

        /// N�v be�ll�t�sa
        /// @param Nev - N�v
        void setNev(std::string Nev) {nev = Nev;}

        /// V�teli �r be�ll�t�sa
        /// @return - V�teli �r
        int getVeteliAr() const {return veteliAr;}

        /// V�teli �r be�ll�t�sa
        /// @param VeteliAr - V�teli �r
        void setVeteliAr(const int VeteliAr) {veteliAr = VeteliAr;}

        /// Elad�si �r lek�rdez�se
        /// @return - Elad�si �r
        int getEladasiAr() const {return eladasiAr;}

        /// Elad�si �r be�ll�t�sa
        /// @param EladasiAr - Elad�si �r
        void setEladasiAr(const int EladasiAr) {eladasiAr = EladasiAr;}

        /// Plusz t�mad�s lek�rdez�se
        /// @return - Plusz t�mad�s
        int getTamadasPlusz() const {return tamadasPlusz;}

        /// Plusz t�mad�s be�ll�t�sa
        /// @param TamadasPlusz - Plusz t�mad�s
        void setTamadasPlusz(const int TamadasPlusz) {tamadasPlusz = TamadasPlusz;}

        /// Tiszt�n virtu�lis t�rgy haszn�lata
        /// @param jatekos - J�t�kos referencia
        virtual void hasznal(Jatekos& jatekos)=0;

        /// Tiszt�n virtu�lis t�rgy v�s�rl�sa
        /// @param jatekos - J�t�kos referencia
        virtual void vasarol(Jatekos& jatekos)=0;
};

/// Glob�lis inserter
/// @param out - output stream referencia
/// @param targy - Targy referencia
/// @return - output stream referencia
std::ostream& operator<<(std::ostream& out,const Targy& targy);

#endif // TARGY_H
