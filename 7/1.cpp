bool getdate(int x, int& month, int& day)
{
    if (x > 366)
        return false;
    
    month = 0;
    day = x;
    constexpr int day_per_month[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    while (day > day_per_month[month])
    {
        day -= day_per_month[month];
        ++month;
    }
    ++month;
    return true;
}