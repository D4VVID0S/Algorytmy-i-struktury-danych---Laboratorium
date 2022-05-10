#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void przyklad_1(int liczby[], int size)
{
    int min;
    int max;
    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i+1; j < size; j++)
        {
            if (liczby[j] < liczby[min]) 
                min = j;
        }
    int temp = liczby[min];
    liczby[min] = liczby[i];
    liczby[i] = temp;
    }
}

void przyklad_2(int liczby[], int size)
{
    int key;
    for (int i = 0; i < size; i++)
    {
        key = liczby[i];
        int j = i - 1;
        while ((j>=0)&&(liczby[j]>key))
        {
            liczby[j + 1] = liczby[j];
            j--;
        }
    liczby[j + 1] = key;
    }
}

void przyklad_3(int liczby[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (liczby[j-1]>liczby[j])
            {
                int temp = liczby[j];
                liczby[j] = liczby[j - 1];
                liczby[j - 1] = temp;
            }
        }
    }
}

void przyklad_4(int liczby[], int lewo, int prawo)
{
    int i, j;
    int x, y;
    i = lewo; j = prawo;
    x = liczby[(lewo + prawo) / 2];

    do
    {
        while (liczby[i] < x)
            i++;
        while (x < liczby[j])
            j--;

        if (i <= j)
        {
            y = liczby[i];
            liczby[i] = liczby[j];
            liczby[j] = y;
            i++;
            j--;
        }
    } while (i <= j);

    if (lewo < j)
        przyklad_4(liczby, lewo, j);
    if (i < prawo)
        przyklad_4(liczby, i, prawo);
}

// int merge(int lewo[], int prawo[])
// {
// int sizeP = sizeof(prawo) / sizeof(prawo[0]);
// int sizeL = sizeof(lewo) / sizeof(lewo[0]);
// int sizeLP = sizeL = sizeP;
// int wynik[] = new int[sizeLP];
// int INDEX_lewy = 0, INDEX_prawy = 0, INDEX_wynik = 0;
// while (INDEX_lewy < sizeL || INDEX_prawy < sizeP)
// {
//     if (INDEX_lewy < sizeL && INDEX_prawy < sizeP)
//     { 
//         if (lewo[INDEX_lewy] <= prawo[INDEX_prawy])
//         {
//             wynik[INDEX_wynik] = lewo[INDEX_lewy];
//             INDEX_lewy++;
//             INDEX_wynik++;
//         }
//         else
//         {
//             wynik[INDEX_wynik] = prawo[INDEX_prawy];
//             INDEX_prawy++;
//             INDEX_wynik++;
//         }
//     }
//     else if (INDEX_lewy < sizeL)
//     {
//         wynik[INDEX_wynik] = lewo[INDEX_lewy];
//         INDEX_lewy++;
//         INDEX_wynik++;
//     }
//     else if (INDEX_prawy < sizeP)
//     {
//         wynik[INDEX_wynik] = prawo[INDEX_prawy];
//         INDEX_prawy++;
//         INDEX_wynik++;
//     }
// }
// return wynik;
// }

// void przyklad_5(int liczby[], int size)
// {
//     int lewo[] = {};
//     int prawo[] = {};
//     int wynik[] = new int[size];
//     if (size <= 1)
//         return array.Length; 
//     int srodek = size / 2;
//     lewo = new int[srodek];
//     if (size % 2 == 0)
//         prawo = new int[srodek];
//     else
//         prawo = new int[srodek + 1];
//     for (int i = 0; i < srodek; i++)
//         lewo[i] = array[i];
//     int x = 0;
//     for (int i = srodek; i < size; i++)
//     {
//         prawo[x] = array[i];
//         x++;
//     }
//     lewo = przyklad_5(lewo);
//     prawo = przyklad_5(prawo);
//     wynik = merge(lewo, prawo);
//     return wynik;
// }

void print_array(string note, int liczby[15])
{
    cout << note;
    cout << "[ ";
    for (int i = 0; i < 15; ++i)
    {
        cout << liczby[i] << " ";
    }
    cout << "]" << endl;
}

void resetArray(int*& liczby)
{
    int def[15] = {42, 69, 88, 67, 87, 81, 60, 64, 13 ,23, 25, 97, 34, 27, 86};
    for(int i = 0; i < 15; ++i)
    {
        liczby[i] = def[i];
    }
}

int main()
{
    int liczby[15] = {42, 69, 88, 67, 87, 81, 60, 64, 13 ,23, 25, 97, 34, 27, 86};
    int* tmp = liczby;
    int size = sizeof(liczby) / sizeof(liczby[0]);
    
    print_array("[Sortowanie przez proste wybieranie]\nBefore:\t", liczby);
    przyklad_1(liczby, size);
    print_array("After:\t", liczby);
    resetArray(tmp);

    print_array("[Sortowanie przez wstawianie]\nBefore:\t", liczby);
    przyklad_2(liczby, size);
    print_array("After:\t", liczby);
    resetArray(tmp);

    print_array("[Sortowanie babelkowe]\nBefore:\t", liczby);
    przyklad_3(liczby, size);
    print_array("After:\t", liczby);
    resetArray(tmp);

    print_array("[Sortowanie szybkie]\nBefore:\t", liczby);
    przyklad_4(liczby, 0, size - 1);
    print_array("After:\t", liczby);
    resetArray(tmp);

    // print_array("[Sortowanie szybkie]\nBefore:\t", liczby);
    // przyklad_5(liczby, size - 1);
    // print_array("After:\t", liczby);
    // resetArray(tmp);
}