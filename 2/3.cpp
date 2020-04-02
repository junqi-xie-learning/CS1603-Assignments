#include <iostream>
using namespace std;

int main()
{
    constexpr int unit_price = 6; // the unit used is "jiao"

    long long int amount = 0;
    cin >> amount;

    long long int total_price = amount * unit_price;
    long long int yuan = total_price / 10;
    int jiao = total_price % 10;

    if (jiao != 0)
        cout << yuan << '.' << jiao << endl;
    else
        cout << yuan << endl;
    cout << yuan << ' ' << jiao;
    return 0;
}