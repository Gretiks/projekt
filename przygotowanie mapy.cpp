#include "funkcje.h"
#include <random>

/*Ten plik służy wylosowaniu mapy na której będzie odbywała się rozgrywka i rozmieszczeniu początkowych punktów*/

int generowanie()
{
    int wybor_mapy = rand()%3;

    return wybor_mapy;
}

vector <vector<char>> mapa()
{

    vector<vector<char>> mapa1;
    mapa1.push_back({'#','#','#','#','#','#','#','#','#','#','#'});
    mapa1.push_back({'#',' ',' ',' ',' ',' ',' ',' ',' ','E','#'});
    mapa1.push_back({'#',' ','#','#',' ',' ',' ','#','#',' ','#'});
    mapa1.push_back({'#',' ','#',' ',' ',' ',' ',' ','#',' ','#'});
    mapa1.push_back({'#',' ',' ',' ','#','#','#',' ',' ',' ','#'});
    mapa1.push_back({'#',' ','#',' ','#','#','#',' ','#',' ','#'});
    mapa1.push_back({'#',' ',' ',' ','#','#','#',' ',' ',' ','#'});
    mapa1.push_back({'#',' ','#',' ',' ',' ',' ',' ','#',' ','#'});
    mapa1.push_back({'#',' ','#','#',' ',' ',' ','#','#',' ','#'});
    mapa1.push_back({'#','P',' ',' ',' ',' ',' ',' ',' ',' ','#'});
    mapa1.push_back({'#','#','#','#','#','#','#','#','#','#','#'});

vector <vector<char>> mapa2;
    mapa2.push_back({'#','#','#','#','#','#','#','#','#','#','#'});
    mapa2.push_back({'#',' ',' ',' ',' ',' ',' ',' ',' ','E','#'});
    mapa2.push_back({'#',' ','#',' ','#','#','#',' ','#',' ','#'});
    mapa2.push_back({'#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'});
    mapa2.push_back({'#','#',' ',' ','#',' ','#',' ',' ','#','#'});
    mapa2.push_back({'#','#',' ',' ',' ',' ',' ',' ',' ','#','#'});
    mapa2.push_back({'#','#',' ',' ','#',' ','#',' ',' ','#','#'});
    mapa2.push_back({'#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'});
    mapa2.push_back({'#',' ','#',' ','#','#','#',' ','#',' ','#'});
    mapa2.push_back({'#','P',' ',' ',' ',' ',' ',' ',' ',' ','#'});
    mapa2.push_back({'#','#','#','#','#','#','#','#','#','#','#'});

vector <vector<char>> mapa3;
    mapa3.push_back({'#','#','#','#','#','#','#','#','#','#','#'});
    mapa3.push_back({'#',' ',' ',' ',' ',' ',' ',' ',' ','E','#'});
    mapa3.push_back({'#',' ','#',' ','#',' ','#',' ','#',' ','#'});
    mapa3.push_back({'#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'});
    mapa3.push_back({'#',' ','#',' ','#',' ','#',' ','#',' ','#'});
    mapa3.push_back({'#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'});
    mapa3.push_back({'#',' ','#',' ','#',' ','#',' ','#',' ','#'});
    mapa3.push_back({'#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'});
    mapa3.push_back({'#',' ','#',' ','#',' ','#',' ','#',' ','#'});
    mapa3.push_back({'#','P',' ',' ',' ',' ',' ',' ',' ',' ','#'});
    mapa3.push_back({'#','#','#','#','#','#','#','#','#','#','#'});

    int los = generowanie(); //losowanie

    int ilosc_punktow = 5;
    vector<vector<char>> wybrana_mapa;

    switch (los)
    {
    case 0:
        for(auto x: mapa1)
            wybrana_mapa.push_back(x);
        break;
    case 1:
        for(auto x: mapa2)
            wybrana_mapa.push_back(x);
        break;
    case 2:
        for(auto x: mapa3)
            wybrana_mapa.push_back(x);
        break;
    }

    //losowanie punktu gdzie bedzie wstawiony startowy punkt do zebrania
    int los1 = 0, los2 = 0;


    for(int i = 0; i < ilosc_punktow; i++)
    {
        while(wybrana_mapa[los1][los2] != ' ')
        {
            los1 = rand()%11;
            los2 = rand()%11;
        }
        wybrana_mapa[los1][los2] = '*';
    }

    return wybrana_mapa;
}