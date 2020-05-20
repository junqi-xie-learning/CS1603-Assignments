#include <iostream>
#include <cstring>
using namespace std;

class LongLongInt
{
    friend LongLongInt operator+(const LongLongInt &lli1, const LongLongInt &lli2);
    friend bool operator!=(const LongLongInt &lli1, const LongLongInt &lli2);
    friend bool operator==(const LongLongInt &lli1, const LongLongInt &lli2) { return !(lli1 != lli2); }
    friend ostream &operator<<(ostream &os, const LongLongInt &lli);
private:
    char *num;
    LongLongInt(char *num_rep, int) :num{ num_rep } { }
    void create_space(const LongLongInt &other);

public:
    LongLongInt(char *num);
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

LongLongInt::LongLongInt(char *num)
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
    return LongLongInt{ result, 0 };
}

bool operator!=(const LongLongInt &lli1, const LongLongInt &lli2)
{
    return static_cast<bool>(strcmp(lli1.num, lli2.num));
}

ostream &operator<<(ostream &os, const LongLongInt &lli)
{
    for (int i = strlen(lli.num) - 1; i >= 0; --i)
        os << lli.num[i];
    return os;
}

class longlongintcomplex
{
    friend longlongintcomplex operator+(const longlongintcomplex &llic1, const longlongintcomplex &llic2);
private:
    LongLongInt real, imag;

public:
    longlongintcomplex(LongLongInt r = "0", LongLongInt i = "0");
    LongLongInt get_real() const { return real; }
    LongLongInt get_imag() const { return imag; }
};

longlongintcomplex::longlongintcomplex(LongLongInt r, LongLongInt i)
    : real{ r }, imag{ i } { }

longlongintcomplex operator+(const longlongintcomplex &llic1, const longlongintcomplex &llic2)
{
    LongLongInt real = llic1.get_real() + llic2.get_real();
    LongLongInt imag = llic1.get_imag() + llic2.get_imag();
    return longlongintcomplex{ real, imag };
}

ostream &operator<<(ostream &os, const longlongintcomplex &llic)
{
    if (llic.get_real() != "0" || llic.get_imag() == "0")
        os << llic.get_real();
    if (llic.get_real() != "0" && llic.get_imag() != "0")
        os << '+';
    if (llic.get_imag() != "0")
        os << llic.get_imag() << 'i';
    return os;
}