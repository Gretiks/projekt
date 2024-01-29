#include "funkcje.h"
#include <ctime>

int main()
{
    srand(time(NULL));

    for(auto x: mapa())
    {
        for(auto y: x)
            cout << y << " ";
        cout << '\n';
    }

    return 0;
}