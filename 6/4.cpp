template <typename T>
void maxmin(T a[], int size)
{
    T max = a[0], min = a[0];
    for (int i = 1; i < size; ++i)
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }
    cout << max << ' ' << min;
}