#include <iostream>
using namespace std;

int main()
{
    int N = 0, L = 0;
    cin >> N >> L;
    int balls[N] = { };
    for (int i = 0; i < N; ++i)
        cin >> balls[i];

    if (N == 1)
    {
        cout << L - balls[0] << ' ' << L - balls[0] << endl;
        return 0;
    }
    
    int even_min = balls[0], even_max = balls[0];
    for (int i = 0; i < N; i += 2)
    {
        if (balls[i] < even_min)
            even_min = balls[i];
        if (balls[i] > even_max)
            even_max = balls[i];
    }

    int odd_min = balls[1], odd_max = balls[1];
    for (int i = 1; i < N; i += 2)
    {
        if (balls[i] < odd_min)
            odd_min = balls[i];
        if (balls[i] > odd_max)
            odd_max = balls[i];
    }

    cout << min(L - even_max, odd_min) << ' '
        << max(L - even_min, odd_max) << endl;
    return 0;
}