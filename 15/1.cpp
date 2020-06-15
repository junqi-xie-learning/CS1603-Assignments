#include <iostream>
#include <stdexcept>
using namespace std;

class integer
{
    friend integer operator+(const integer &i1, const integer &i2);
    friend integer operator-(const integer &i1, const integer &i2);
    friend integer operator*(const integer &i1, const integer &i2);
    friend integer operator/(const integer &i1, const integer &i2);

    friend ostream &operator<<(ostream &os, const integer &i);

private:
    int inner_rep;

public:
    integer(int i) :inner_rep{ i } { }
};

integer operator+(const integer &i1, const integer &i2)
{
    long long int lli1 = i1.inner_rep, lli2 = i2.inner_rep;
    int result = i1.inner_rep + i2.inner_rep;
    if (lli1 + lli2 != result)
        throw overflow_error{ "Overflow in addition!" };
    return integer{ result };
}

integer operator-(const integer &i1, const integer &i2)
{
    long long int lli1 = i1.inner_rep, lli2 = i2.inner_rep;
    int result = i1.inner_rep - i2.inner_rep;
    if (lli1 - lli2 != result)
        throw overflow_error{ "Overflow in subtraction!" };
    return integer{ result };
}

integer operator*(const integer &i1, const integer &i2)
{
    long long int lli1 = i1.inner_rep, lli2 = i2.inner_rep;
    int result = i1.inner_rep * i2.inner_rep;
    if (lli1 * lli2 != result)
        throw overflow_error{ "Overflow in multiplication!" };
    return integer{ result };
}

integer operator/(const integer &i1, const integer &i2)
{
    long long int lli1 = i1.inner_rep, lli2 = i2.inner_rep;
    int result = i1.inner_rep / i2.inner_rep;
    if (lli1 / lli2 != result)
        throw overflow_error{ "Overflow in division!" };
    return integer{ result };
}

ostream &operator<<(ostream &os, const integer &i)
{
    return os << i.inner_rep;
}