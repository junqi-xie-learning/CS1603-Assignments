#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    bool matrix[n][n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];
    
    int max = 0;
    for (int i = 0; i < n; ++i)
    {
        int j = 0;
        while (matrix[i][j] == 1)
            ++j;
        
        if (j > max)
            max = j;
    }

    cout << max << endl;
    return 0;
}