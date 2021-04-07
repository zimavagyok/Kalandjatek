#include <iostream>
#include <time.h>
#include "Jatek.h"
#include "Ellenseg.h"
#include "gtest_lite.h"

void test1()
{
    TEST(Fomenu, Fomenu)
    {
        Jatek ujJatek;
        ujJatek.foMenu();
        EXPECT_STREQ("Oke",ujJatek.getJatekos()->getNev().c_str());
        EXPECT_EQ((size_t)7,ujJatek.getBetoltottTargyak().size());
    } ENDM
}

void test2()
{
    TEST(Karakter, Keszites)
    {
        Jatek ujJatek;
        ujJatek.ujJatekosKeszitese();
        EXPECT_STREQ("Gergo", ujJatek.getJatekos()->getNev().c_str());
    } ENDM
}

void test3()
{
    TEST(Karakter,Kiirasok)
    {
        Jatek ujJatek;
        ujJatek.ujJatekosKeszitese();
        for(size_t i = 0;i<3;i++)
            ujJatek.karakterMenu();
    } ENDM
}

void test4()
{
    TEST(Harc, Harc)
    {
        Jatek ujJatek;
        ujJatek.ujJatekosKeszitese();
        ujJatek.initJatek();
        ujJatek.utazas();
        EXPECT_EQ(97,ujJatek.getJatekos()->getArany());
        ujJatek.utazas(2);
    } ENDM
}

void test5()
{
    TEST(Fomenu, Pihenes)
    {
        Jatek ujJatek;
        ujJatek.ujJatekosKeszitese();
        ujJatek.getJatekos()->setEletero(10);
        ujJatek.pihenes();
        EXPECT_EQ(ujJatek.getJatekos()->getMaxEletero(),ujJatek.getJatekos()->getEletero());
    } ENDM
}

void test6()
{
    TEST(Fomenu, Szintlepes)
    {
        Jatek ujJatek;
        ujJatek.ujJatekosKeszitese();
        ujJatek.getJatekos()->setTapasztalat(400);
        ujJatek.karakterSzintlepes();
        EXPECT_EQ(6, ujJatek.getJatekos()->getEro());
    } ENDM
}

void test7()
{
    TEST(Ellenseg, Ellenseg)
    {
        Ellenseg ujEllenseg;
        Ellenseg ujEllenseg2("Nincs",10,10,10,10,10,10,1);
        Jatekos ujJatekos;
        ujJatekos.initJatekos("Valaki");
        ujEllenseg2.tamadas(ujJatekos);
    } ENDM
}

void test8()
{
    TEST(Ital, Ital)
    {
        Ital ujItal;
        Jatekos ujJatekos;
        ujJatekos.initJatekos("Valaki");
        ujItal.hasznal(ujJatekos);
    } ENDM
}

void test9()
{
    TEST(Fegyver, Fegyver)
    {
        Fegyver ujFegyver;
        std::cout<< ujFegyver;
    } ENDM
}

int main()
{
    srand(time(NULL));
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    return 0;
}
