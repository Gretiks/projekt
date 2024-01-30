#include "funkcje.h"
#include <conio.h> //zbieranie inputu bez entera

void print(vector<vector<char>> mapa) //wypisywanie aktualnego stanu planszy
{
    for(auto x: mapa)
    {
        for(auto y: x)
            cout << y;

        cout << '\n';
    }
}

int gra()
{
    int punkty_gracza = 0;
    int punkty_bota = 0;

    pair <int, int> pozycja_gracza = make_pair(9,1);
    pair <int, int> pozycja_bota = make_pair(1, 9);
    vector<vector<char>> plansza;

    //wylosowanie mapy i rozstawienie punktów
    for(auto x: mapa())
        plansza.push_back(x);

    char znak = ' ';

    while(punkty_bota != 20 || punkty_gracza != 20)
    {
        print(plansza);
        znak = char(_getch());

        if(znak == 'w')
        {
            if(plansza[pozycja_gracza.first-1][pozycja_gracza.second] == '*')
            {
                punkty_gracza++;
                plansza[pozycja_gracza.first][pozycja_gracza.second] = ' ';
                pozycja_gracza.first--;
                plansza[pozycja_gracza.first][pozycja_gracza.second] = 'P';
            }
            if(plansza[pozycja_gracza.first-1][pozycja_gracza.second] != '#' && plansza[pozycja_gracza.first-1][pozycja_gracza.second] != 'E')
            {
                plansza[pozycja_gracza.first][pozycja_gracza.second] = ' ';
                pozycja_gracza.first--;
                plansza[pozycja_gracza.first][pozycja_gracza.second] = 'P';
            }
        }
        else if(znak == 's')
        {
            if(plansza[pozycja_gracza.first+1][pozycja_gracza.second] == '*')
            {
                punkty_gracza++;
                plansza[pozycja_gracza.first][pozycja_gracza.second] = ' ';
                pozycja_gracza.first++;
                plansza[pozycja_gracza.first][pozycja_gracza.second] = 'P';
            }
            else if(plansza[pozycja_gracza.first+1][pozycja_gracza.second] != '#' && plansza[pozycja_gracza.first+1][pozycja_gracza.second] != 'E')
            {
                plansza[pozycja_gracza.first][pozycja_gracza.second] = ' ';
                pozycja_gracza.first++;
                plansza[pozycja_gracza.first][pozycja_gracza.second] = 'P';
            }
        }
        else if(znak == 'a')
        {
            if(plansza[pozycja_gracza.first][pozycja_gracza.second-1] == '*')
            {
                punkty_gracza++;
                plansza[pozycja_gracza.first][pozycja_gracza.second] = ' ';
                pozycja_gracza.second--;
                plansza[pozycja_gracza.first][pozycja_gracza.second] = 'P';
            }
            else if(plansza[pozycja_gracza.first][pozycja_gracza.second-1] != '#' && plansza[pozycja_gracza.first][pozycja_gracza.second-1] != 'E')
            {
                plansza[pozycja_gracza.first][pozycja_gracza.second] = ' ';
                pozycja_gracza.second--;
                plansza[pozycja_gracza.first][pozycja_gracza.second] = 'P';
            }
        }
        else if(znak == 'd')
        {
            if(plansza[pozycja_gracza.first][pozycja_gracza.second+1] == '*')
            {
                punkty_gracza++;
                plansza[pozycja_gracza.first][pozycja_gracza.second] = ' ';
                pozycja_gracza.second++;
                plansza[pozycja_gracza.first][pozycja_gracza.second] = 'P';
            }
            else if(plansza[pozycja_gracza.first][pozycja_gracza.second+1] != '#' && plansza[pozycja_gracza.first][pozycja_gracza.second+1] != 'E')
            {
                plansza[pozycja_gracza.first][pozycja_gracza.second] = ' ';
                pozycja_gracza.second++;
                plansza[pozycja_gracza.first][pozycja_gracza.second] = 'P';
            }
        }

        system("cls");
    }

    print(plansza);



    return 0;
}


