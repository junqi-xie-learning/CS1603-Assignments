#include <iostream>
using namespace std;

int main()
{
    int a = 0, b = 0;
    cin >> a >> b;

    int larger = (a >= b ? a : b);
    if (larger < 11 || abs(a - b) <= 1)
        cout << "Unknown";
    else if (larger == 11 || abs(a - b) == 2)
        cout << (a > b ? "A win" : "B win");
    else
        cout << "Illegal";
    return 0;
}