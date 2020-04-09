int knapsack(int n, int s[], int v[], int C)
{
    int result[n + 1][C + 1] = { };
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= C; ++j)
            if (s[i - 1] > j)
                result[i][j] = result[i - 1][j];
            else
                result[i][j] = max(result[i - 1][j], result[i - 1][j - s[i - 1]] + v[i - 1]);
    return result[n][C];
}