#include <iostream>
#include <iomanip>
using namespace std;

double sum(double queue[], int size)
{
    double s = 0;
    for (int i = 0; i < size; ++i)
        s += queue[i];
    return s;
}

double queuing(double queue1[5], int size1, double queue2[5], int size2)
{
    double time1 = sum(queue1, size1);
    double time2 = sum(queue2, size2);
    return max(time1, time2);
}

double calling_number(double queue[10], int size)
{
    double time1 = queue[0];
    double time2 = queue[1];

    for (int i = 2; i < size; ++i)
        if (time1 <= time2)
            time1 += queue[i];
        else
            time2 += queue[i];
    return max(time1, time2);
}

int main()
{
    // the first senario
    double queue1[] = { 1, 1, 1, 1, 1 };
    double queue2[] = { 1, 1, 1, 1, 5 };
    cout << fixed << setprecision(1) << queuing(queue1, 5, queue2, 5) << ' ';

    // the second senario
    double time[10] = { };
    for (int i = 0; i < 10; ++i)
    {
        double queue[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        queue[i] = 5;
        time[i] = calling_number(queue, 10);
    }
    cout << sum(time, 10) / 10;

    return 0;
}