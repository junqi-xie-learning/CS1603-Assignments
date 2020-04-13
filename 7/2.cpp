void max2(int a[], int n, int *first, int *second)
{
    int first1 = 0, second1 = 0, first2 = 0, second2 = 0;
    switch (n)
    {
    case 1:
        *first = a[0];
        *second = INT32_MIN;
        return;
    case 2:
        if (a[0] >= a[1])
        {
            *first = a[0];
            *second = a[1];
        }
        else
        {
            *first = a[1];
            *second = a[0];
        }
        return;
    default:
        max2(a, n / 2, &first1, &second1);
        max2(a + n / 2, n - n / 2, &first2, &second2);
        if (first1 < first2)
            swap(first1, first2);
        *first = first1;
        *second = max(first2, max(second1, second2));
        return;
    }
}