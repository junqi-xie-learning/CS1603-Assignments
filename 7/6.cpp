#include <iostream>
#include <iomanip>
using namespace std;

int stoi(const char *begin, const char *end)
{
    int i = 0;
    for (const char *p = begin; p != end; ++p)
        i = i * 10 + *p - '0';
    return i;
}

bool leapyear(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int days_in_month(int m, bool is_leapyear)
{
    constexpr int day_per_month[] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && is_leapyear)
        return day_per_month[0];
    else
        return day_per_month[m];
}

void add_day(int date[3], int n)
{
    int &y = date[0], &m = date[1], &d = date[2];

    d += n;
    while (days_in_month(m, leapyear(y)) < d) {
        if (m == 12) {
            d -= days_in_month(m, leapyear(y));
            m = 1;
            ++y;
        }
        else {
            d -= days_in_month(m, leapyear(y));
            ++m;
        }
    }
}

int main()
{
    char str[9] = { };
    cin.get(str, 9);
    int day = 0;
    cin >> day;

    int date[3] = { stoi(str, str + 4), stoi(str + 4, str + 6), stoi(str + 6, str + 8) };
    add_day(date, day);
    
    if (date[0] >= 10000)
        cout << "out of limit!" << endl;
    else
    {
        cout.fill('0');
        cout << setw(4) << date[0]
            << setw(2) << date[1]
            << setw(2) << date[2] << endl;
    }
    return 0;
}