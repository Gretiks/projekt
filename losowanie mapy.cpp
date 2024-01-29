#include <random>
#include "funkcje.h"

int generowanie()
{
    srand(time(NULL));

    int wybor_mapy = rand()%3;

    return wybor_mapy;

}