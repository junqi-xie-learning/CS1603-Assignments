#include <iostream>
using namespace std;

class LongLongInt
{
    friend LongLongInt operator+(const LongLongInt &lli1, const LongLongInt &lli2);
    friend LongLongInt operator-(const LongLongInt &lli1, const LongLongInt &lli2);
    friend bool operator!=(const LongLongInt &lli1, const LongLongInt &lli2);
    friend bool operator==(const LongLongInt &lli1, const LongLongInt &lli2) { return !(lli1 != lli2); }
    friend bool operator<(const LongLongInt &lli1, const LongLongInt &lli2);
    friend ostream &operator<<(ostream &os, const LongLongInt &lli);
protected:
    char *num;
    LongLongInt(char *num_rep) :num{ num_rep } { }
    void create_space(const LongLongInt &other);

public:
    LongLongInt(const char *num);
    LongLongInt(const LongLongInt &other);
    LongLongInt &operator=(const LongLongInt &other);
    ~LongLongInt() { delete[] num; }
};

void LongLongInt::create_space(const LongLongInt &other)
{
    int length = strlen(other.num);
    this->num = new char[length + 1];
    strcpy(this->num, other.num);
}

LongLongInt::LongLongInt(const char *num)
{
    int length = strlen(num);
    this->num = new char[length + 1];
    strcpy(this->num, num);
    for (int i = length / 2 - 1; i >= 0; --i)
        swap(this->num[i], this->num[length - i - 1]);
}

LongLongInt::LongLongInt(const LongLongInt &other)
{
    create_space(other);
}

LongLongInt &LongLongInt::operator=(const LongLongInt &other)
{
    delete[] num;
    create_space(other);
    return *this;
}

LongLongInt operator+(const LongLongInt &lli1, const LongLongInt &lli2)
{
    char *ptr1 = lli1.num, *ptr2 = lli2.num;
    int new_len = max(strlen(ptr1), strlen(ptr2));
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

        j = static_cast<int>(result[i] >= 10);
        result[i] = result[i] % 10 + '0';
    }
    if (j > 0)
    {
        result[new_len] = j + '0';
        result[new_len + 1] = '\0';
    }
    else
        result[new_len] = '\0';
    return LongLongInt{ result };
}

LongLongInt operator-(const LongLongInt &lli1, const LongLongInt &lli2)
{
    char *ptr1 = lli1.num, *ptr2 = lli2.num;
    int new_len = strlen(ptr1);
    char *result = new char[new_len + 1];
    int j = 0;
    for (int i = 0; i < new_len; ++i)
    {
        if (i >= strlen(ptr2))
            result[i] = (ptr1[i] - '0') - j;
        else
            result[i] = (ptr1[i] - '0') - (ptr2[i] - '0') - j;

        j = static_cast<int>(result[i] < 0);
        result[i] = (result[i] + 10) % 10 + '0';
    }
    result[new_len] = '\0';
    while (result[new_len - 1] == '0' and new_len > 1)
    {
        result[new_len - 1] = '\0';
        --new_len;
    }
    return LongLongInt{ result };
}

bool operator!=(const LongLongInt &lli1, const LongLongInt &lli2)
{
    return static_cast<bool>(strcmp(lli1.num, lli2.num));
}

bool operator<(const LongLongInt &lli1, const LongLongInt &lli2)
{
    int length1 = strlen(lli1.num), length2 = strlen(lli2.num);
    if (length1 != length2)
        return length1 < length2;
    
    for (int i = length1 - 1; i >= 0; --i)
        if (lli1.num[i] != lli2.num[i])
            return lli1.num[i] < lli2.num[i];
    return false;
}

ostream &operator<<(ostream &os, const LongLongInt &lli)
{
    for (int i = strlen(lli.num) - 1; i >= 0; --i)
        os << lli.num[i];
    return os;
}

class signLLI : public LongLongInt
{
    friend signLLI operator-(const signLLI &slli);
    friend signLLI operator+(const signLLI &slli1, const signLLI &slli2);
    friend signLLI operator-(const signLLI &slli1, const signLLI &slli2) { return slli1 + (-slli2); }
    friend ostream &operator<<(ostream &os, const signLLI &slli);
private:
    bool sign; // 0 for positive, 1 for negative
    signLLI(const LongLongInt &temp, bool s)
        :LongLongInt{ temp }, sign{ s } { }
public:
    signLLI(const char *num);
};

signLLI::signLLI(const char *num)
    :LongLongInt{ num }, sign{ false }
{
    int length = strlen(num);
    if (this->num[length - 1] == '-')
    {
        sign = true;
        this->num[length - 1] = '\0';
    }
}

signLLI operator-(const signLLI &slli)
{
    signLLI result = slli;
    result.sign = !result.sign;
    return result;
}

signLLI operator+(const signLLI &slli1, const signLLI &slli2)
{
    const LongLongInt &lli1 = slli1, &lli2 = slli2;
    if (slli1.sign == slli2.sign)
        return signLLI{ lli1 + lli2, slli1.sign };
    else if (lli1 == lli2)
        return "0";
    else if (lli1 < lli2)
        return signLLI{ lli2 - lli1, slli2.sign };
    else
        return signLLI{ lli1 - lli2, slli1.sign };
}

ostream &operator<<(ostream &os, const signLLI &slli)
{
    if (slli.sign)
        os << '-';
    return os << static_cast<LongLongInt>(slli);
}