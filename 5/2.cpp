#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    bool is_prime[2000001] = { };
    
    int n = 0;
    cin >> n;
    // initialize the array
    for (int i = 2; i <= n; ++i)
        is_prime[i] = true;
    
    // perform the sieve of Eratosthenes
    for (int i = 2; i <= static_cast<int>(sqrt(n)); ++i)
        if (is_prime[i])
            for (int j = pow(i, 2); j <= n; j += i)
                is_prime[j] = false;

    // output the result
    for (int i = 2; i <= n; ++i)
        if (is_prime[i])
            cout << i << ' ';
    return 0;
}