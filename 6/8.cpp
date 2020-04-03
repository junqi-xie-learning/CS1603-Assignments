#include <iostream>
#include <cstring>
using namespace std;

void convert(char dst[], char src[], int n)
{
    if (n == 1)
    {
        strcpy(dst, src);
        return;
    }

    int cycle_len = 2 * n - 2;
    int size = strlen(src);
    int index = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j + i < size; j += cycle_len)
        {
            dst[index] = src[j + i];
            ++index;

            if (i != 0 && i != n - 1 && j + cycle_len - i < size)
            {
                dst[index] = src[j + cycle_len - i];
                ++index;
            }
        }
    dst[index] = '\0';
}

int main()
{
    int n = 0;
    char src[31] = "";
    cin >> n;
    cin.get();
    cin.getline(src, 31);

    char dst[31] = "";
    convert(dst, src, n);
    cout << dst;
    return 0;
}