#include <iostream>
using namespace std;

int main()
{
    long long int n = 0;
    cin >> n;

    int steps = 0;
    while (!(n % 3))
    {
        n /= 3;
        steps += 2; // First apply the 2nd procedure, then apply the 1st once.
    }
    while (!(n % 5))
    {
        n /= 5;
        steps += 3; // First apply the 3rd procedure, then apply the 1st twice.
    }
    while (!(n % 2))
    {
        n /= 2;
        steps += 1; // Apply the 1st procedure once.
    }

    cout << (n == 1 ? steps : -1);
    return 0;
}