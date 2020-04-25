void set(const char *s1, char *s)
{
    int j = 0;
    for (int i = strlen(s1) - 1; i >= 0; --i)
    {
        s[j] = s1[i];
        ++j;
    }
    while (j < 128)
    {
        s[j] = '0';
        ++j;
    }
}

void show(const char *s, char *res)
{
    int i = 127, j = 0;
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

int index(const char *p, char ch)
{
    for (int i = 0; i < 128; ++i)
        if (p[i] == ch)
            return i;
    return -1;
}

void add_float(char* a, char* b, char* res)
{
    char *p1 = new char[128]{ }, *p2 = new char[128]{ }, *s = new char[128]{ };
    set(a, p1);
    set(b, p2);
    set("0", s);

    int difference = index(p1, '.') - index(p2, '.');
    if (difference < 0)
    {
        char *temp = p2;
        p2 = p1;
        p1 = temp;
    }

    difference = abs(difference);
    int i = 0, j = 0;
    while (i < difference)
    {
        s[i] = p1[i];
        ++i;
    }
    while (i < 128 - difference + 1)
    {
        if (p1[i] == '.')
            s[i] = '.';
        else
        {
            s[i] = p1[i] - '0' + p2[i - difference] - '0' + j;
            if (s[i] >= 10)
                j = s[i] / 10;
            else
                j = 0;
            s[i] = s[i] % 10 + '0';
        }
        ++i;
    }

    show(s, res);
    delete[] p1;
    delete[] p2;
    delete[] s;
}