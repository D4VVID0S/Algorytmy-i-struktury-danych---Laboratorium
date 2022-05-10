#include <stdio.h>
#include <iostream>

using namespace std;

int binSearch(int liczby[],int size, int key)
{
    int lewo = 0;
    int prawo = size - 1;
    while (lewo <= prawo)
    {
        int curr = (lewo + prawo) / 2;
        if (key == liczby[curr])
        {
            cout << "Znaleziono liczbe " << key << "." << endl;
            return 0;
        }
        else if (key < liczby[curr])
            prawo = curr - 1;
        else
            lewo = curr + 1;
    }
    cout << "Nie znaleziono liczby " << key << ".";
    return -1;
}

int main()
{
    int liczby[15] = {13, 23, 25, 27, 34, 42, 60, 64, 67, 69, 81, 86, 87, 88, 97};
    int size = sizeof(liczby) / sizeof(liczby[0]);
    int key = 0;

    cout << "Podaj liczbe do wyszukania: ";
    cin >> key;

    binSearch(liczby, size, key);  
}