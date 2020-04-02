#include <iostream>
using namespace std;

int main()
{
    char chars[80] = { };
    int size = 0;
    for (char ch; cin.get(ch); )
    {
        chars[size] = ch;
        ++size;
    }

    char result[size] = { };
    for (int i = 0; i < size; ++i)
    {
        // find the current max
        char max = 0;
        for (int j = 0; j < size; ++j)
            if (chars[j] > max)
                max = chars[j];
        
        // put the max into the result
        result[i] = max;

        // delete the current max
        for (int j = 0; j < size; ++j)
            if (chars[j] == max)
                chars[j] = 0;
    }

    for (int i = 0; i < size && result[i] != 0; ++i)
        cout << result[i];
    return 0;
}