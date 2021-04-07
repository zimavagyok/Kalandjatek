#ifndef JATEKOS_H
#define JATEKOS_H

/**
 * \file Jatekos.h
 *
 * Jatekos osztály deklarációja és globális függvényei
 */

#include "Karakter.h"
#include "Ital.h"
#include "Fegyver.h"
#include <vector>


/// Jatekos osztály
///
class Jatekos : public Karakter
{
    int szint; ///< Játékos szintje
    int kovetkezoSzint; ///< Következő szinthez szükséges tapasztalati pont
    int maxEletero; ///< Játékos maximális életereje

    int ero; ///< Játékos erejének a szintje
    int eleteroSzint; ///< Játékos életerejének a szintje

    int statPontok; ///< Játékos által elkölthető statisztika pontok

    std::vector<Ital*> italok; ///< A játékosnál található italok listája
    Fegyver *elsodlegesFegyver; ///< A játékosnál található fegyverre mutató pointer

    public:
        /// Konstruktor beállítja az attribútumokat
        Jatekos();

        /// Függvény, amely beállítja az attribútumokat
        /// @param Nev - Játékos neve
        void initJatekos(const std::string Nev); //done

        /// Virtuális destruktor
        virtual ~Jatekos();

        /// Maximális életerő lekérdezés
        /// @return - maximális életerő
        int getMaxEletero() const {return maxEletero;}

        /// Maximális életerő beállítása
        /// @param MaxEletero - Maximális életerő
        void setMaxEletero(const int MaxEletero) {maxEletero = MaxEletero;}

        /// Szint lekérdezése
        /// @return - szint
        int getSzint() const {return szint;}

        /// Szint beállítása
        /// @param Szint - szint
        void setSzint(const int Szint) {szint = Szint;}

        /// Következő szinthez szükséges tapasztalat lekérdezése
        /// @return - Következő szinthez szükséges tapasztalat
        int getKovetkezoSzint() const {return kovetkezoSzint;}

        /// Következő szinthez szükséges tapasztalat beállítása
        /// @param KovetkezoSzint - Következő szinthez szükséges tapasztalat
        void setKovetkezoSzint(const int KovetkezoSzint) {kovetkezoSzint = KovetkezoSzint;}

        /// Erő lekérdezése
        /// @return - Erő
        int getEro() const {return ero;}

        /// Erő beállítása
        /// @param Ero - Erő
        void setEro(const int Ero) {ero = Ero;}

        /// Életerő szintjének lekérdezése
        /// @return - Életerő szint
        int getEleteroSzint() const {return eleteroSzint;}

        /// Életerő szintjének beállítása
        /// @param EleteroSzint - Életerő szint
        void setEleteroSzint(const int EleteroSzint) {eleteroSzint = EleteroSzint;}

        /// Maximális élet beállítása
        void maxElet() {setEletero(maxEletero);}

        /// Statisztika pontok lekérdezése
        /// @return - Statisztika pontok
        int getStatPontok() const {return statPontok;}

        /// Statisztika pontok beállítása
        /// @param StatPontok - Statisztika pontok
        void setStatPontok(const int StatPontok) {statPontok = StatPontok;}

        /// Játékos támadásának megvalósítása
        /// @param kit - Megtámadott karakter referencia
        void tamadas(Karakter& kit);

        /// Tulajdonság szintjének növelése
        /// @param stat - Tulajdonság
        /// @param value - Növelés mértéke
        void stathozAdas(const int stat,const int value); //done

        /// Tulajdonságok alapján attribútumok frissítése
        void statFrissites(); //done

        /// Szint növelése
        void szintLepes(); //done

        /// Ital hozzáadása a játékos italaihoz
        /// @param ujItal - Ital referencia
        void addItal(const Ital& ujItal); //done

        /// Ital eltávolítása a játékos italai közül
        /// @param index - Az ital indexe
        void removeItal(const int index); //done

        /// Ital lekérdezése
        /// @param index - Ital indexe
        Ital* getItal(const int index) const; //done

        /// Ital eladása
        /// @param index - Ital indexe
        void eladItal(const int index);

        /// Italok számának lekérdezése
        /// @return - Játékosnál található italok száma
        int italokSzama() {return italok.size();}

        /// Fegyver lekérdezése
        /// @return - Fegyverre mutató pointer
        Fegyver* getElsodlegesFegyver() const; //done

        /// Játékosnál található italok kilistázása
        void italokKilistazasa(); //done

        /// Játékos életerejének növelése
        /// @param mennyit - Növelés mértéke
        void addEletero(const int mennyit);

        /// Fegyver beállítása
        /// @param ujFegyver - Fegyver referencia
        void setElsodlegesFegyver(const Fegyver& ujFegyver);
};

/// Globális inserter
/// @param out - output stream referencia
/// @param jatekos - Jatekos referencia
/// @return - output stream referencia
std::ostream& operator<<(std::ostream& out, const Jatekos& jatekos);

#endif // JATEKOS_H
