#include <cstring>

char *oddstr(char str[])
{
    int size = strlen(str);
    char *result = new char[size / 2 + 1];
    for (int i = 0; i < size / 2; ++i)
        result[i] = str[2 * i + 1];
    result[size / 2] = '\0';
    return result;
}