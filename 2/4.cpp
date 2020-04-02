#include <iostream>
using namespace std;

int main()
{
    constexpr int minute_per_hour = 60;
    constexpr int second_per_minute = 60;

    int time = 0;
    cin >> time;

    int hour = time / minute_per_hour / second_per_minute;
    time -= hour * minute_per_hour * second_per_minute;
    int minute = time / second_per_minute;
    time -= minute * second_per_minute;
    int second = time;

    cout << hour << ':' << minute << ':' << second;
    return 0;
}