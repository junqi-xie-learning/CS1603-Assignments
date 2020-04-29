int index(const char *p, char ch)
{
    for (int i = 0; i < 128; ++i)
        if (p[i] == ch)
            return i;
    return -1;
}

void set(const char *s1, char *s)
{
    int i = 255, dot = index(s1, '.');
    while (i > 128 + dot)
    {
        s[i] = '0';
        --i;
    }
    while (i > 128 + dot - strlen(s1))
    {
        s[i] = s1[128 + dot - i];
        --i;
    }
    while (i >= 0)
    {
        s[i] = '0';
        --i;
    }
}

void show(const char *s, char *res)
{
    int i = 255, j = 0;
    while (s[i] == '0')
        --i;
    int size = i;
    while (i >= 0)
    {
        res[j] = s[i];
        --i;
        ++j;
    }
    while (res[size] == '0')
        --size;
    ++size;
    res[size] = '\0';
}

void add_float(char* a, char* b, char* res)
{
    char p1[256] = { }, p2[256] = { }, s[256] = { };
    set(a, p1);
    set(b, p2);

    int j = 0;
    for (int i = 0; i < 256; ++i)
        if (p1[i] == '.')
            s[i] = '.';
        else
        {
            s[i] = p1[i] - '0' + p2[i] - '0' + j;
            if (s[i] >= 10)
                j = s[i] / 10;
            else
                j = 0;
            s[i] = s[i] % 10 + '0';
        }

    show(s, res);
}