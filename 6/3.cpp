bool find(int set[], int n, int num)
{
    for (int i = 0; i < n; ++i)
        if (set[i] == num)
            return true;
    return false;
}

int delete_duplicate(int set[], int n)
{
    int result[n] = { };
    int size = 0;

    for (int i = 0; i < n; ++i)
        if (!find(result, size, set[i]))
        {
            result[size] = set[i];
            ++size;
        }
    
    for (int i = 0; i < size; ++i)
        set[i] = result[i];
    return size;
}

void sort(int set[], int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (set[j] > set[i])
            {
                int temp = set[i];
                set[i] = set[j];
                set[j] = temp;
            }
}

void print(int set[], int n)
{
    if (n == 0)
    {
        cout << "NoOutput";
        return;
    }
    for (int i = 0; i < n; ++i)
        cout << set[i] << ' ';
}

void Add(int set[], int n, int num)
{
    // add
    int result[n + 1] = { };
    for (int i = 0; i < n; ++i)
        result[i] = set[i];
    result[n] = num;

    int size = delete_duplicate(result, n + 1);
    sort(result, size);
    print(result, size);
}

void Find(int set[], int n, int num)
{
    cout << find(set, n, num);
}

void Intersection(int set1[], int n, int set2[], int m)
{
    int result[n] = { };
    int size = 0;

    // intersection
    for (int i = 0; i < n; ++i)
        if (find(set2, m, set1[i]))
        {
            result[size] = set1[i];
            ++size;
        }

    size = delete_duplicate(result, size);
    sort(result, size);
    print(result, size);
}

void Union(int set1[], int n, int set2[], int m)
{
    // union
    int result[m + n] = { };
    for (int i = 0; i < n; ++i)
        result[i] = set1[i];
    for (int i = 0; i < m; ++i)
        result[n + i] = set2[i];
    
    int size = delete_duplicate(result, n + m);
    sort(result, size);
    print(result, size);
}