#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
constexpr double PI = 3.14;

int main()
{
    int radius = 0;
    cin >> radius;

    double area = 4 * PI * pow(radius, 2);
    double volume = 4.0 / 3 * PI * pow(radius, 3);

    cout << fixed << setprecision(1) << area << ' ' << volume;
    return 0;
}