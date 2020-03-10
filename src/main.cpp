#include <iostream>

#include "Database.hh"

using namespace std;

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        cout << endl;
        cout << " Brak opcji okreslajacej rodzaj testu." << endl;
        cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
        cout << endl;
        return 1;
    }

    Database base = {nullptr, 0, 0};

    if (Init(&base, argv[1]) == false)
    {
        cerr << " Inicjalizacja testu nie powiodla sie." << endl;
        return 1;
    }

    cout << endl;
    cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
    cout << endl;

    Expression expression;

    while (GetNextQuestion(&base, &expression))
    {
        Display(expression);
        cout << " = ";
        Display(Solve(expression));
        cout << endl;
    }

    cout << endl;
    cout << " Koniec testu" << endl;
    cout << endl;
}
