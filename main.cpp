#include "funkcje.h"
#include <ctime>
#include <conio.h>

int main()
{
    srand(time(NULL));
    char znak;

    a:
    system("cls");
    cout << "Witaj w mojej grze!\n";
    cout << "1. Graj\n2. Instrukcja\n3. Autor\n4. Wyjscie";

    znak = char(_getch()); //przechwytywanie klwisza
    
    if(znak == '1') gra();
    if(znak == '2') 
    {
        system("cls");
        cout << "1. Poruszasz sie za pomoca klawiszy w a s d\n2. Twoim zadaniem jest zebranie 30 punktow przed twoim przeciwnikiem\n3. Znakiem '#' oznaczone sa sciany\n4. Twoja postac oznaczona jest symbolem 'P'\n5. Przeciwnik oznaczony jest symbolem 'E'\n";
        system("pause");
        goto a;
    }
    if(znak == '3')
    {
        system("cls");
        cout << "Autorem jest Maciej Sztucki grupa 2 lab 4\n";
        system("pause");
        goto a;
    }
    if(znak == '4') return 0;
    else goto a;
}