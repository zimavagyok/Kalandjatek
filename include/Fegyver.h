#ifndef FEGYVER_H
#define FEGYVER_H

/**
 * \file Fegyver.h
 *
 * Fegyver oszt�ly deklar�ci�ja �s glob�lis f�ggv�nyei
 */

#include "Targy.h"
#include <string>

/// Fegyver oszt�ly
///
class Fegyver : public Targy
{
    int kritikusSebzes; ///< A fegyver �ltal okozott kritikus sebz�s

    public:
        /// Konstruktor be�ll�tja az attrib�tumokat
        Fegyver();

        /// T�bb param�teres konstruktor, ami be�ll�tja az attrib�tumokat
        /// @param Nev - A fegyver neve
        /// @param VeteliAr - A fegyver v�teli �ra
        /// @param EladasiAr - A fegyver elad�si �ra
        /// @param TamadasPlusz - A fegyver �ltal okozott plusz sebz�s
        /// @param KritikusSebzes - A fegyver �ltal okozott kritikus sebz�s
        Fegyver(std::string Nev,int VeteliAr,int EladasiAr,int TamadasPlusz,int KritikusSebzes);

        // Virtu�lis destruktor
        virtual ~Fegyver();

        /// Kritikus sebz�s lek�rdez�se
        /// @return - kritikus sebz�s
        int getKritikusSebzes() const {return kritikusSebzes;}

        /// Kritikus sebz�s be�ll�t�sa
        /// @param KritikusSbezes - Kritikus sebz�s m�rt�ke
        void setKritikusSebzes(int KritikusSebzes) {kritikusSebzes = KritikusSebzes;}

        /// Fegyver kl�noz�sa
        /// @return - A fegyver m�solat�ra mutat� pointer
        Fegyver* clone() const;

        /// A fegyver haszn�lata
        /// @param jatekos - A j�t�kos referenci�ja aki haszn�lja
        void hasznal(Jatekos& jatekos);

        /// A fegyver megv�s�rl�sa
        /// @param jatekos - Referencia a v�s�rl�ra
        void vasarol(Jatekos& jatekos);
};

/// Glob�lis inserter
/// @param out - output stream referencia
/// @param fegyver - Fegyver referencia
/// @return - output stream referencia
std::ostream& operator<<(std::ostream& out,const Fegyver& fegyver);

#endif // FEGYVER_H
