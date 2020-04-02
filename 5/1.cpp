#include <iostream>
using namespace std;

int main()
{
    constexpr int difference_of_date[] = { 31, 31, 28, 31, 30, 
        31, 30, 31, 31, 30, 31, 30, 29 };
        // in order: December, January, February, ..., leap year February
    
    int n = 0;
    cin >> n;
    
    int times[7] = { }; // in order: Sunday, Monday, ...
    int current = 3; // set current date to 12/13/1899

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 12; ++j)
        {
            int year = 1900 + i;
            if (j == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) // is leap year
                current = (current + difference_of_date[12]) % 7;
            else
                current = (current + difference_of_date[j]) % 7;
            ++times[current];
        }

    for (int i = 1; i < 7; ++i)
        cout << times[i] << ' '; // from Monday to Saturday
    cout << times[0]; // Sunday
    return 0;
}