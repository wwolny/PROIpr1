#include <iostream>
#include "Unit.h"
using namespace std;
class JakasKlasa
{
    int a;
    char b;
    std::string c;
public:
    JakasKlasa();
};

JakasKlasa::JakasKlasa()
{
    cout << "Klasa utworzona, wartosci zmiennych: " << endl;
    cout << "a = " << a << endl;
    cout << "b = '" << b << "'" << endl;
    cout << "c = \"" << c << "\"" << endl;
    a = 123;
    b = 'x';
    c = "napis";
    cout << "Wartosci zmiennych po zainicjowaniu w konstruktorze: " << endl;
    cout << "a = " << a << endl;
    cout << "b = '" << b << "'" << endl;
    cout << "c = \"" << c << "\"" << endl;
}

int main()
{

    /*JakasKlasa tZmienna;
    Unit a;
    a.createUnit();
    a.Wypisz();*/
    return( 0 );
}
