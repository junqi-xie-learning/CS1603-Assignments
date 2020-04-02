#include <iostream>
using namespace std;

int main()
{
    int month = 0, day = 0, year = 0;
    cin >> month >> day >> year;

    // check if the date is valid
    bool is_valid = false;
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        is_valid = (day >= 1 && day <= 31);
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        is_valid = (day >= 1 && day <= 30);
        break;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) // is leap year
            is_valid = (day >= 1 && day <= 29);
        else
            is_valid = (day >= 1 && day <= 28);
        break;
    default:
        break;
    }

    // calculate the dayNum
    int dayNum = 0;
    if (is_valid)
    {
        dayNum = 31 * (month - 1) + day;
        if (month > 2)
        {
            dayNum -= (4 * month + 23) / 10;
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) // is leap year
                dayNum += 1;
        }
    }

    cout << dayNum;
    return 0;
}