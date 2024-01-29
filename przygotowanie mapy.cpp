#include "funkcje.h"
#include <random>

/*Ten plik służy wylosowaniu mapy na której będzie odbywała się rozgrywka i rozmieszczeniu początkowych punktów*/

int generowanie()
{
    // srand(time(NULL));

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

    if(los == 0)
    {
        return mapa1;
    }
    else if(los == 1)
    {
        return mapa2;
    }
    else
    {
        return mapa3;
    }

}