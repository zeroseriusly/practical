#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
int mutex = 1, full = 0, empty1 = 10, x = 0;

void producer()
{
    --mutex;
    ++full;
    x++;
    cout << "Producer produces item " << x;
    ++mutex;
}

void consumer()
{
    --mutex;
    --full;
    ++empty1;
    cout << "Consumer consumes item " << x;
    x--;
    ++empty1;
    cout << "Consumer consumes item " << x;
    x--;
    ++mutex;
}

int main()
{
    int n, i;
    cout << "Press 1 for Producer\nPress 2 for Consumer\nPress 3 for exit";
    for (i = 1; i > 0; i++)
    {
        cout << "Enter your choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            if (mutex == 1 && full != 0)
                producer();
            else
                cout << "Buffer is full";
            break;
        case 2:
            if (mutex == 1 && full != 0)
                consumer();
            else
                cout << "Buffer is empty";
            break;
        case 3:
            exit(0);
            break;

        default:
            break;
        }
    }
}