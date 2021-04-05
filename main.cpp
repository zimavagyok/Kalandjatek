#include <iostream>
#include <time.h>
#include "Jatek.h"
#include "gtest_lite.h"

using namespace std;

int main()
{
    srand(time(NULL));
    Jatek ujJatek;
    ujJatek.foMenu();

    return 0;
}
