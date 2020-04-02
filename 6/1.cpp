#include <iostream>
using namespace std;

bool perfectnum(int x)
{
    int sum = 0;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            sum += i;
            if (i * i != x)
                sum += x / i;
        }
    }
    return sum == 2 * x;
}

int main()
{
    int m = 0, n = 0;
    cin >> m >> n;

    bool has_perfect = false;
    for (int i = m; i <= n; ++i)
        if (perfectnum(i))
        {
            has_perfect = true;
            cout << i << endl;
        }
    if (!has_perfect)
        cout << "NONE";
    return 0;
}