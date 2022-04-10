#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define DLUGOSC_MAX 20

using namespace std;

int const STOS_PELNY = 3;
int const STOS_PUSTY = 2;
int const OK = 1;
int szczyt = 0;
char Stos[DLUGOSC_MAX + 1];
int push(char x);
int pop(char *w);
int StanStosu();
int priority(char x);
char stack_first();

void clear()
{
    szczyt = 0;
}

int main()
{
    int i, n;
    char a, dummy;
    cout << "Podaj n: " << endl;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if(priority(a) == -1) // zmienna
            cout << " " << a; // pokaż zmienną
        else if(priority(a) > 0) // operator
        {
            if(StanStosu() == STOS_PUSTY) // jeżeli stos pusty
                push(a); // wstaw do stosu
            else if(priority(a) > priority(stack_first()))
                push(a);
            else
            {
                while(priority(a) <= priority(stack_first()))
                {
                    pop(&dummy);
                    cout << " " << dummy;
                }
                push(a);
            }
        }
        else
        {
            if(a == '(')
                push(a);
            if(a == ')')
            {
                while(stack_first() != '(')
                {
                    pop(&dummy);
                    cout << " " << dummy;
                }
                pop(&dummy);
            }
        }
    }
    while(StanStosu() != STOS_PUSTY)
    {
        pop(&dummy);
        cout << " " << dummy;
    }
    return 0;
}

char stack_first()
{
    return Stos[szczyt - 1];
}

int StanStosu()
{
    switch(szczyt)
    {
        case 0:
            return(STOS_PUSTY);

        case DLUGOSC_MAX + 1:
            return (STOS_PELNY);
        
        default:
            return (OK);
    }
}

int push(char x)
{
    if(szczyt <= DLUGOSC_MAX)
    {
        Stos[szczyt++] = x;
        return (OK);
    }
    else
        return (STOS_PELNY);
}

int pop(char *w)
{
    if (szczyt > 0)
    {
        *w = Stos[--szczyt];
        return (OK);
    }
    else
        return (STOS_PUSTY);
}

int priority(char x)
{
    switch(x)
    {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '^':
            return 3;
        case '(':
            return 0;
        case ')':
            return 0;
        default:
            return -1;
    }
}