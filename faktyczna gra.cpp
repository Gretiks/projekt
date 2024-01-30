#include "funkcje.h"
#include <conio.h> //zbieranie inputu bez entera

pair <int,int> dodanie_punktu(vector<vector<char>> mapa)
{
    int los1 = 0, los2 = 0;

    while(mapa[los1][los2] != ' ')
    {
        los1 = rand()%11;
        los2 = rand()%11;
    }

    return make_pair(los1, los2);
}

void print(vector<vector<char>> mapa, int punkty_gracza, int punkty_bota) //wypisywanie aktualnego stanu planszy
{
    cout << "Gracz  Bot\n";
    cout << punkty_gracza << "      " << punkty_bota << "\n\n";

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
    int curr_liczba_punktow = 5;
    bool czy_dalej = true; //kontynuowanie gry

    pair <int, int> punkt; //wspolrzedne wylosowanego kolejnego punktu na mapie 
    pair <int, int> pozycja_gracza = make_pair(9,1);
    pair <int, int> pozycja_bota = make_pair(1, 9);
    vector<vector<char>> plansza;

    //wylosowanie mapy i rozstawienie punktów
    for(auto x: mapa())
        plansza.push_back(x);

    char znak = ' ';

    while(czy_dalej)
    {
        if(punkty_gracza == 20 || punkty_bota == 20) break;

        print(plansza, punkty_gracza, punkty_bota);
        znak = char(_getch());

        if(znak == 'w')
        {
            if(plansza[pozycja_gracza.first-1][pozycja_gracza.second] == '*')
            {
                punkty_gracza++;
                punkt = dodanie_punktu(plansza);
                plansza[punkt.first][punkt.second] = '*';
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
                punkt = dodanie_punktu(plansza);
                plansza[punkt.first][punkt.second] = '*';
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
                punkt = dodanie_punktu(plansza);
                plansza[punkt.first][punkt.second] = '*';
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
                punkt = dodanie_punktu(plansza);
                plansza[punkt.first][punkt.second] = '*';
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

    if(punkty_bota == 20)
    cout << "PRZEGRANA\n\n";
    else
    cout << "WYGRANA\n\n";

    cout << "Gracz  Bot\n";
    cout << punkty_gracza << "      " << punkty_bota;

    system("pause");

    return 0;
}


