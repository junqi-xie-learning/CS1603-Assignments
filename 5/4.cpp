#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int array[n] = { };
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    
    int sorted[n] = { array[0] };
    for (int i = 1; i < n; ++i)
    {
        bool inserted = false;
        int prev = array[i];
        for (int j = 0; j < i; ++j)
        {
            if (!inserted && array[i] <= sorted[j])
                inserted = true;
            
            if (inserted)
            {
                int temp = sorted[j];
                sorted[j] = prev;
                prev = temp;
            }
        }
        if (!inserted)
            sorted[i] = array[i];
        else
            sorted[i] = prev;  
    }

    for (int i = 0; i < n - 1; ++i)
        cout << sorted[i] << ' ';
    cout << sorted[n - 1];
    return 0;
}