#include "funkcje.h"
#include <queue> //na potrzeby algorytmu bfs

stack<punkt> bfs(vector<vector<char>> mapa, pair<int,int> poz_bota)
{

    punkt start = {poz_bota.second, poz_bota.first};

    vector<vector<bool>> check (11, vector<bool> (11, false)); //stworzenie tablicy bool o wymiarach 11 na 11 i wypełnienie jest wartościami False

    queue<pair<punkt, stack<punkt>>> que; //stworzenie kolejki punktow i stosu do najblizszej gwiazdy
    que.push({start, stack<punkt>()}); //dodanie punktu startowego i pustego stosu do kolejki
    check[start.x][start.y] = true;

    //tabice uzywane do sprawdzenia sasiadow obecnego pola
    int zmienx[4] = {-1, 0, 1, 0};
    int zmieny[4] = {0, 1, 0 ,-1}; 

    stack<punkt> curr_sciezka;

    while(!que.empty())
    {
        punkt curr = que.front().first; //obecne wspolrzedne
        curr_sciezka = que.front().second; //obecna sciezka do pierwszej znalezionej gwiazdy

        que.pop();

        if(mapa[curr.y][curr.x] == '*') break;

        for(int i = 0; i < 4; i++)
        {
            int nowyx = curr.x + zmienx[i];
            int nowyy = curr.y + zmieny[i];

            if(mapa[nowyy][nowyx] != '#' && mapa[nowyy][nowyx] != 'P')
            {
                stack<punkt> nowa_sciezka = curr_sciezka;
                nowa_sciezka.push({nowyx, nowyy});
                que.push({{nowyx, nowyy}, nowa_sciezka});
                check[nowyy][nowyx] = true;
            }
        }
    }

    stack<punkt> sciezka;

    //odwrocenie stosu żeby uzyskac sciezkę od punktu startowego bota;
    while(!curr_sciezka.empty())
    {
        sciezka.push(curr_sciezka.top());
        curr_sciezka.pop();
    }

    return sciezka;
}