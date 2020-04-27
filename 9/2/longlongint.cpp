#include "longlongint.h"

void read_int(Long_long_int &li)
{
    char str[201] = {};
    cin >> str;

    int size = strlen(str);
    for (int i = 0; i < size; ++i)
        li.int_rep[i] = str[size - 1 - i];
    for (int i = size; i < 200; ++i)
        li.int_rep[i] = '0';
}

Long_long_int add_int(const Long_long_int &li1, const Long_long_int &li2)
{
    Long_long_int result;
    int j = 0;
    for (int i = 0; i < 200; ++i)
    {
        result.int_rep[i] = li1.int_rep[i] - '0' + li2.int_rep[i] - '0' + j;
        if (result.int_rep[i] >= 10)
            j = result.int_rep[i] / 10;
        else
            j = 0;
        result.int_rep[i] = result.int_rep[i] % 10 + '0';
    }
    return result;
}

void output_int(const Long_long_int &li)
{
    int i = 199;
    while (li.int_rep[i] == '0')
        --i;
    while (i >= 0)
    {
        cout << li.int_rep[i];
        --i;
    }
}