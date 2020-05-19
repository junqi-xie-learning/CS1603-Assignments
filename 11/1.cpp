#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
private:
    int month, day, year;
    bool leapyear(int y) const;
    int days_in_month(int m, bool is_leapyear) const;
    bool is_date(int m, int d, int y) const;

public:
    Date() :month{ 1 }, day{ 1 }, year{ 1900 } { }
    Date(int m, int d, int y) :month{ 1 }, day{ 1 }, year{ 1900 } { setDate(m, d, y); }
    void setDate(int m, int d, int y);

    int get_month() const { return month; }
    int get_day() const { return day; }
    int get_year() const { return year; }

    Date &operator+=(int n);
    Date &operator++() { *this += 1; return *this; }
    Date operator++(int) { Date temp = *this; ++*this; return temp; }
    bool operator<(const Date& date) const;
};

bool Date::leapyear(int y) const
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int Date::days_in_month(int m, bool is_leapyear) const
{
    constexpr int day_per_month[] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && is_leapyear)
        return day_per_month[0];
    else
        return day_per_month[m];
}

bool Date::is_date(int m, int d, int y) const
{
    if (d <= 0) 
        return false;
    else if (m < 1 || m > 12) 
        return false;
    else if (days_in_month(m, leapyear(y)) < d) 
        return false;
    return true;
}

void Date::setDate(int m, int d, int y)
{
    if (!is_date(m, d, y))
    {
        cout << "Invalid date." << endl;
        return;
    }

    month = m;
    day = d;
    year = y;
}

Date &Date::operator+=(int n)
{
    day += n;
    while (days_in_month(month, leapyear(year)) < day)
    {
        if (month == 12) {
            day -= days_in_month(month, leapyear(year));
            month = 1;
            ++year;
        }
        else
        {
            day -= days_in_month(month, leapyear(year));
            ++month;
        }
    }
    return *this;
}

bool Date::operator<(const Date& other) const
{
    if (year != other.year)
        return year < other.year;
    else if (month != other.month)
        return month < other.month;
    else
        return day < other.day;
}

ostream& operator<<(ostream& os, const Date& d)
{
    os.fill('0');
    return os << d.get_year() << '-' 
        << setw(2) << d.get_month() << '-'
        << setw(2) << d.get_day();
}