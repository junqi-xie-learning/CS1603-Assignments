#include <iostream>
#include <cstring>
using namespace std;

char *&funA(char **&p)
{
    static char *a_ptr = nullptr;
    p = &a_ptr;
    return *p;
}

char *funB(char *b, char **p)
{
    char *b_ptr = b;
    for (char *q = *p; *q != '\0'; ++q)
    {
        if ('a' <= *q && *q <= 'z')
            *b_ptr = *q + ('A' - 'a');
        else
            *b_ptr = *q;
        ++b_ptr;
    }
    *b_ptr = '\n';
    ++b_ptr;
    *b_ptr = '\0';
    return b;
}

int main()
{
    char a[100], b[100];
    for(int i = 0; i < 3; ++i) {
        char **p;
        cin >> a;
        funA(p) = a;
        cout << funB(b, p);
    }
    return 0;
}