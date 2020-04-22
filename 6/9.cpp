#include <iostream>
using namespace std;

constexpr int moves[8][2] = { { -1, 2 }, { -1, -2 }, { -2, 1 }, { -2, -1 },
    { 1, 2 }, { 1, -2 }, { 2, 1 }, { 2, -1 } };
constexpr int impossible = 11; // Impossible token

bool is_valid(int chess_board[10][10], int n, int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n && !chess_board[x][y];
}

int count_next(int chess_board[10][10], int n, int x, int y)
{
    int count = 0;
    for (int i = 0; i < 8; ++i)
    {
        int new_x = x + moves[i][0];
        int new_y = y + moves[i][1];
        if (is_valid(chess_board, n, new_x, new_y))
            ++count;
    }
    return count;
}

int min(int array[], int n)
{
    int min_num = impossible;
    for (int i = 0; i < n; ++i)
        if (array[i] < min_num)
            min_num = array[i];
    return min_num;
}

bool is_solution(int chess_board[10][10], int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (chess_board[i][j] == 0)
                return false;
    return true;
}

bool go(int chess_board[10][10], int n, int x, int y, int current_step)
{
    if (is_solution(chess_board, n))
        return true;

    int steps[8] = { };
    for (int i = 0; i < 8; ++i)
    {
        int new_x = x + moves[i][0];
        int new_y = y + moves[i][1];
        if (is_valid(chess_board, n, new_x, new_y))
            steps[i] = count_next(chess_board, n, new_x, new_y);
        else
            steps[i] = impossible;
    }

    while (min(steps, 8) != impossible)
    {
        int min_step = min(steps, 8);
        for (int i = 0; i < 8; ++i)
        {
            if (steps[i] == min_step)
            {
                int new_x = x + moves[i][0];
                int new_y = y + moves[i][1];

                chess_board[new_x][new_y] = current_step + 1;
                if (go(chess_board, n, new_x, new_y, current_step + 1))
                    return true;
                else
                    chess_board[new_x][new_y] = 0;
                steps[i] = impossible;
            }
        }
    }
    return false;
}

int main()
{
    int n = 0; 
    cin >> n;
    int chess_board[10][10] = { };

    int x = 0, y = 0;
    cin >> x >> y;
    
    chess_board[x - 1][y - 1] = 1;
    if (go(chess_board, n, x - 1, y - 1, 1))
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                cout << chess_board[i][j] << ' ';
            cout << endl;
        }
    else
        cout << "None";
    return 0;
}