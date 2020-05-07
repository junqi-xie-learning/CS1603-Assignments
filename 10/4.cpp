class LongLongInt
{
private:
    char *num;

public:
    LongLongInt(char *num);
    LongLongInt(const LongLongInt &lli);

    void display() const;
    LongLongInt add(LongLongInt b);
};

LongLongInt::LongLongInt(char *num)
{
    int length = strlen(num);
    this->num = new char[length + 1];
    strcpy(this->num, num);
    for (int i = length / 2 - 1; i >= 0; --i)
        swap(this->num[i], this->num[length - i - 1]);
}

LongLongInt::LongLongInt(const LongLongInt &lli)
{
    int length = strlen(lli.num);
    this->num = new char[length + 1];
    strcpy(this->num, lli.num);
}

void LongLongInt::display() const
{
    for (int i = strlen(num) - 1; i >= 0; --i)
        cout << num[i];
}

LongLongInt LongLongInt::add(LongLongInt b)
{
    int new_len = max(strlen(num), strlen(b.num));
    char *ptr1 = num, *ptr2 = b.num;
    if (new_len != strlen(ptr1))
        swap(ptr1, ptr2);

    char *result = new char[new_len + 2];
    int j = 0;
    for (int i = 0; i < new_len; ++i)
    {
        if (i >= strlen(ptr2))
            result[i] = ptr1[i] - '0' + j;
        else
            result[i] = ptr1[i] - '0' + ptr2[i] - '0' + j;

        if (result[i] >= 10)
            j = result[i] / 10;
        else
            j = 0;
        result[i] = result[i] % 10 + '0';
    }
    if (j > 0)
    {
        result[new_len] = j + '0';
        result[new_len + 1] = '\0';
    }
    else
        result[new_len] = '\0';
    delete[] num;
    num = result;
    return *this;
}