#include <iostream>
#include <cstring>
using namespace std;

void del_char(char **strings, int size, char ch)
{
    for (int i = 0; i < size; ++i)
    {
        char *str = new char[31];
        char *p = str;
        for (char *q = strings[i]; *q != '\0'; ++q)
            if (*q != ch)
            {
                *p = *q;
                ++p;
            }
        *p = '\0';
        delete[] strings[i];
        strings[i] = str;
    }
}

void sort(char **strings, int size)
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < i; ++j)
            if (strcmp(strings[i], strings[j]) > 0)
            {
                char* temp = strings[i];
                strings[i] = strings[j];
                strings[j] = temp;
            }
}

int main()
{
    int n = 0;
    cin >> n;
    char **strings = new char*[n];

    for (int i = 0; i < n; ++i)
    {
        strings[i] = new char[31];
        cin >> strings[i];
    }

    char ch = 0;
    cin >> ch;

    del_char(strings, n, ch);
    sort(strings, n);

    for (int i = 0; i < n; ++i)
    {
        cout << strings[i] << endl;
        delete[] strings[i];
    }
    delete[] strings;
    return 0;
}