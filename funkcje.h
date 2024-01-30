#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct punkt
{
    int x, y;
};

vector<vector<char>> mapa();
int gra();
void dodanie_punktu(vector<vector<char>>, int);
stack<punkt> bfs(vector<vector<char>>, pair<int,int>);