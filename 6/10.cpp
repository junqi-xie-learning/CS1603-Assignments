#include <iostream>
using namespace std;

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
    constexpr int moves[8][2] = { { -1, 2 }, { -1, -2 }, { -2, 1 }, { -2, -1 },
        { 1, 2 }, { 1, -2 }, { 2, 1 }, { 2, -1 } };

    if (is_solution(chess_board, n))
        return true;

    for (int i = 0; i < 8; ++i)
    {
        int new_x = x + moves[i][0];
        int new_y = y + moves[i][1];

        if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n || 
            chess_board[new_x][new_y])
            continue;
        
        chess_board[new_x][new_y] = current_step + 1;
        if (go(chess_board, n, new_x, new_y, current_step + 1))
            return true;
        else
            chess_board[new_x][new_y] = 0;
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