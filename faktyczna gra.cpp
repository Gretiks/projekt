#include "funkcje.h"
#include <conio.h> //zbieranie inputu bez entera
#include <chrono>
#include <thread>

const chrono::milliseconds przerwa(300); // 0.3 s;

pair <int,int> dodanie_punktu(vector<vector<char>> mapa) //dodawanie zebranego punktu na mape
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
    b:
    int punkty_gracza = 0;
    int punkty_bota = 0;
    int curr_liczba_punktow = 5;
    bool czy_dalej = true; //kontynuowanie gry
    stack<punkt> sciezka; // sciezka do punktu ktora bedzie podazac bot


    pair <int, int> punkt; //wspolrzedne wylosowanego kolejnego punktu na mapie 
    pair <int, int> pozycja_gracza = make_pair(9,1);
    pair <int, int> pozycja_bota = make_pair(1, 9);
    vector<vector<char>> plansza; // mapa na której trwa rozgrywka

    //wylosowanie mapy i rozstawienie punktów
    for(auto x: mapa())
        plansza.push_back(x);

    char znak = ' '; //zmienna w której przechowywany jest wciśnięty klawisz
    auto ostatni_ruch = chrono::steady_clock::now(); // czas ostatniego ruchu gracza

    while(czy_dalej)
    {
        auto teraz = chrono::steady_clock::now(); //obecny czas;
        auto roznica_czasu = chrono::duration_cast<chrono::milliseconds>(teraz - ostatni_ruch);

        if(punkty_gracza == 30 || punkty_bota == 30) break; //sprawdzenie warunku wygranej/przegranej

        print(plansza, punkty_gracza, punkty_bota);

        //sekcja bota

        if(roznica_czasu.count() >= przerwa.count())
        {
            sciezka = bfs(plansza, pozycja_bota); //stwozenie sciezki dla bota;
            plansza[pozycja_bota.first][pozycja_bota.second] = ' ';
            pozycja_bota.first = sciezka.top().y;
            pozycja_bota.second = sciezka.top().x;
            plansza[pozycja_bota.first][pozycja_bota.second] = 'E';
            sciezka.pop();
            if(sciezka.empty())
            {
                punkty_bota++;
                punkt = dodanie_punktu(plansza);
                plansza[punkt.first][punkt.second] = '*';
            }
            ostatni_ruch = chrono::steady_clock::now();
        }

        this_thread::sleep_for(chrono::milliseconds(100));


        //sekcja gracza

    if(_kbhit()) //sprawdzenie czy został wciśnięty klawisz
    {
        znak = char(_getch()); //przechwytywanie klwisza
        ostatni_ruch = chrono::steady_clock::now();

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

            if(plansza[pozycja_gracza.first-1][pozycja_gracza.second] != '#' && plansza[pozycja_gracza.first-1][pozycja_gracza.second] != 'E') //zabezpiecznie przed wyjsciem poza mape
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
            else if(plansza[pozycja_gracza.first+1][pozycja_gracza.second] != '#' && plansza[pozycja_gracza.first+1][pozycja_gracza.second] != 'E') //zabezpiecznie przed wyjsciem poza mape
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
            else if(plansza[pozycja_gracza.first][pozycja_gracza.second-1] != '#' && plansza[pozycja_gracza.first][pozycja_gracza.second-1] != 'E') //zabezpiecznie przed wyjsciem poza mape
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
            else if(plansza[pozycja_gracza.first][pozycja_gracza.second+1] != '#' && plansza[pozycja_gracza.first][pozycja_gracza.second+1] != 'E') //zabezpiecznie przed wyjsciem poza mape
            {
                plansza[pozycja_gracza.first][pozycja_gracza.second] = ' ';
                pozycja_gracza.second++;
                plansza[pozycja_gracza.first][pozycja_gracza.second] = 'P';
            }
        }
    }

        system("cls");
    }

    if(punkty_bota == 30)
    cout << "\n\nPRZEGRANA\n\n";
    else
    cout << "\n\nWYGRANA\n\n";

    cout << "Gracz  Bot\n";
    cout << punkty_gracza << "      " << punkty_bota;

    cout << '\n';

    system("pause");

    system("cls");
    cout << "Czy chcesz grac jeszcze?\n1. Tak\n2. Nie\n";


    a:
    znak = char(_getch()); //przechwytywanie klwisza
    if(znak == '1') goto b;
    if(znak == '2') return 0;
    else goto a;
}


