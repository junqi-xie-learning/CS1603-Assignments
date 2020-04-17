#include <iostream>
using namespace std;

int sum(bool *begin, bool *end)
{
    int s = 0;
    for (bool *p = begin; p != end; ++p)
        s += *p;
    return s;
}

void move_next(bool cycle[], int n, int &current)
{
    current = (current + 1) % n;
    while (!cycle[current])
        current = (current + 1) % n;
}

int main()
{
    int n = 0;
    cin >> n;
    bool *cycle = new bool[n];
    for (int i = 0; i < n; ++i)
        cycle[i] = true;
    
    int current = n - 1;
    while (sum(cycle, cycle + n) != 1)
    {
        for (int i = 0; i < 3; ++i)
            move_next(cycle, n, current);
        cycle[current] = false;
    }

    for (int i = 0; i < n; ++i)
        if (cycle[i])
            cout << i + 1;
    delete[] cycle;
    return 0;
}