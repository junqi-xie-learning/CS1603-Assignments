#include <iostream>
using namespace std;

int main()
{
    int R = 0, C = 0;
    cin >> R >> C;
    int matrix[10][10] = { };
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> matrix[i][j];
    
    // initialize
    int result[10][10] = { };
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            result[i][j] = true;
    
    // mark the max
    for (int i = 0; i < R; ++i)
    {
        // find the max of row i
        int max = matrix[i][0];
        for (int j = 1; j < C; ++j)
            if (matrix[i][j] > max)
                max = matrix[i][j];
        
        // mark the row
        for (int j = 0; j < C; ++j)
            result[i][j] &= matrix[i][j] == max;
    }

    // mark the min
    for (int j = 0; j < C; ++j)
    {
        // find the min of column j
        int min = matrix[0][j];
        for (int i = 1; i < R; ++i)
            if (matrix[i][j] < min)
                min = matrix[i][j];
        
        // mark the column
        for (int i = 0; i < R; ++i)
            result[i][j] &= matrix[i][j] == min;
    }

    bool has_saddle_point = false;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (result[i][j])
            {
                has_saddle_point = true;
                cout << i + 1 << ' ' << j + 1 << endl;
            }
    if (!has_saddle_point)
        cout << "NONE" << endl;
    return 0;
}