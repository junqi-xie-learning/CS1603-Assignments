#include <iomanip>

class Time
{
    int seconds;
    int htos(int h) const { return h * 60 * 60; }
    int mtos(int m) const { return m * 60; }

public:
    Time(int h = 0, int m = 0, int s = 0);
    void settime(int h, int m, int s);
    int hour() const;
    int minute() const;
    int second() const;

    void add(int addition);
    void display() const;
};

Time::Time(int h, int m, int s)
    : seconds{ htos(h) + mtos(m) + s } { }

void Time::settime(int h, int m, int s)
{
    seconds = htos(h) + mtos(m) + s;
}

int Time::hour() const
{
    return seconds / (60 * 60);
}

int Time::minute() const
{
    return (seconds - htos(hour())) / 60;
}

int Time::second() const
{
    return seconds - htos(hour()) - mtos(minute());
}

void Time::add(int addition)
{
    seconds = (seconds + addition) % htos(24);
}

void Time::display() const
{
    cout.fill('0');
    cout << setw(2) << hour() << ':'
         << setw(2) << minute() << ':'
         << setw(2) << second() << endl;
}