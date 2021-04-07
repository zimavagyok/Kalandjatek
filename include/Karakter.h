#ifndef KARAKTER_H
#define KARAKTER_H

/**
 * \file Karakter.h
 *
 * Karakter osztály deklarációja és globális függvényei
 */

#include <string>

/// Karakter osztály
///
class Karakter
{
    std::string nev; ///< Karakter neve
    int eletero; ///< Karakter életereje
    int tapasztalat; ///< Karakter tapasztalata
    int arany; ///< Karakter aranya
    int minSebzes; ///< Karakter minimális sebzése
    int maxSebzes; ///< Karakter maximális sebzése
    int vedekezes; ///< Karakter védekezése
    public:
        /// Konstruktor beállítja az attribútumokat
        Karakter();
        /// Több paraméteres konstruktor
        /// @param Nev - Név
        /// @param Eletero - Életerő
        /// @param Tapasztalat - Tapasztalat
        /// @param Arany - Arany
        /// @param MinSebzes - Minimális sebzés
        /// @param MaxSebzes - Maximális sebzés
        /// @param Vedekezes - Védekezés
        Karakter(std::string Nev,int Eletero,int Tapasztalat,int Arany,int MinSebzes,int MaxSebzes,int Vedekezes);

        /// Virtuális destruktor
        virtual ~Karakter();

        /// Név lekérdezése
        /// @return - Név
        std::string getNev() const {return nev;}

        /// Név beállítása
        /// @param Nev- Név
        void setNev(const std::string Nev) {nev = Nev;}

        /// Életerő lekérdezése
        /// @return - Életerő
        int getEletero() const {return eletero;}

        /// Életerő beállítása
        /// @param Eletero - Életerő
        void setEletero(const int Eletero) {eletero = Eletero;}

        /// Tapasztalat lekérdezése
        /// @return - Tapasztalat
        int getTapasztalat() const {return tapasztalat;}

        /// Tapasztalat beállítása
        /// @param Tapasztalat - Tapasztalat
        void setTapasztalat(const int Tapasztalat) {tapasztalat = Tapasztalat;}

        /// Arany lekérdezése
        /// @return - Arany
        int getArany() const {return arany;}

        /// Arany beállítása
        /// @param Arany - Arany
        void setArany(const int Arany) {arany = Arany;}

        /// Arany levonása
        /// @param Arany - Levonandó arany
        void levonArany(const int Arany) {arany -= Arany;}

        /// Minimális sebzés lekérdezése
        /// @return - Minimális sebzés
        int getMinSebzes() const {return minSebzes;}

        /// Minimális sebzés beállítása
        /// @param MinSebzes - Minimális sebzés
        void setMinSebzes(const int MinSebzes) {minSebzes = MinSebzes;}

        /// Maximális sebzés lekérdezése
        /// @return - Maximális sebzés
        int getMaxSebzes() const {return maxSebzes;}

        /// Maximális sebzés beállítása
        /// @param MaxSebzes - Maximális sebzés
        void setMaxSebzes(const int MaxSebzes) {maxSebzes = MaxSebzes;}

        /// Védekezés lekérdezése
        /// @return - Védekezés
        int getVedekezes() const {return vedekezes;}

        /// Védekezés beállítása
        /// @param Vedekezes - Védekezés
        void setVedekezes(const int Vedekezes) {vedekezes = Vedekezes;}

        /// Sebzés lekérdezése
        /// @return - Sebzés
        int getSebzes() const {return rand() % maxSebzes + minSebzes;}

        /// Arany hozzáadása a karakter aranyához
        /// @param mennyit - Hozzáadandó arany
        void addArany(const int mennyit) {arany+=mennyit;}

        /// Tapasztalat hozzáadása a karakter tapasztalatához
        /// @param mennyit - Hozzáadandó tapasztalat
        void addTp(const int mennyit) {tapasztalat+=mennyit;}

        /// Tisztán virtuális támadás függvény
        /// @param kit - Karakter referencia
        virtual void tamadas(Karakter& kit) = 0;

        /// Sebzés levonása
        /// @param Sebzes - Levonandó sebzés
        void takeSebzes(const int Sebzes);

        /// Karakter életben van-e lekérdezése
        /// @return - Életben van-e
        bool eletben() {return eletero > 0;}
};

/// Globális inserter
/// @param out - output stream referencia
/// @param karakter - Karakter referencia
/// @return - output stream referencia
std::ostream& operator<<(std::ostream& out, const Karakter& karakter);

#endif // KARAKTER_H
