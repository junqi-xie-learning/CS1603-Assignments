#include <iostream>
using namespace std;

void merge(int A[], int low, int mid, int high)
{
    int first = low, second = mid + 1;
    int temp[high - low + 1] = { };

    int size = 0;
    while (first <= mid && second <= high)
    {
        if (A[first] <= A[second])
        {
            temp[size] = A[first];
            ++first;
        }
        else
        {
            temp[size] = A[second];
            ++second;
        }
        ++size;
    }
    
    // If the tail of the first half is larger, copy it to the end of the original array.
    for (int i = 0; mid - i >= first; ++i)
        A[high - i] = A[mid - i];
    for (int i = 0; i < size; ++i)
        A[low + i] = temp[i];
}

void sort(int A[], int low, int high)
{
    if (high - low > 0)
    {
        int mid = (low + high) / 2;
        sort(A, low, mid);
        sort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main()
{
    int n = 0; 
    cin >> n;
    int A[n] = { };
    for (int i = 0; i < n; ++i)
        cin >> A[i];

    sort(A, 0, n - 1);

    for (int i = 0; i < n - 1; ++i)
        cout << A[i] << ' ';
    cout << A[n - 1];
    return 0;
}