#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    if (b > 407)
        b = 407; // There's no Pesudo Armstrong Numbers larger than 407

    bool found = false;
    for (int i = a; i <= b; ++i)
    {
        int j = i, digit_sum = 0;
        while (j)
        {
            digit_sum += pow(j % 10, 3);
            j /= 10;
        }

        if (digit_sum == i)
        {
            found = true;
            cout << i << ' ';
        }
    }

    if (!found)
        cout << "NONE";
    return 0;
}