#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int array[n] = { };
    for (int i = 0; i < n; ++i)
        cin >> array[i];
    
    int target = 0;
    cin >> target;

    int result[2] = { };
    // Find the leftmost element
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (array[mid] >= target)
            high = mid;
        else
            low = mid + 1;
    }
    result[0] = low;
    
    // Find the rightmost element
    low = 0, high = n - 1;
    while (low < high)
    {
        int mid = (low + high) / 2 + 1;
        if (array[mid] <= target)
            low = mid;
        else
            high = mid - 1;
    }
    result[1] = high;

    if (result[0] <= result[1]) // the target exists in the original array
        cout << result[0] << ' ' << result[1] << endl;
    else
        cout << -1 << ' ' << -1 << endl;
    return 0;
}