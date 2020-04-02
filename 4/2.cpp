#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int n = 0, p = 0;
    cin >> n >> p;

    int counter = 0;
    long long int ith_power = 0;
    for (int i = 1; ith_power <= n; ++i)
    {
        ith_power = pow(p, i);
        counter += n / ith_power;
    }

    cout << counter;
    return 0;
}