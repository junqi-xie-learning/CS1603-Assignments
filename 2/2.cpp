#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a = pow(2, 80) + 1 - pow(2, 80);
    int b = 10; b *= 2 + 100;
    int c = 123 - 0x123;

    cout << a << endl
        << b << endl
        << c << endl;
    return 0;
}