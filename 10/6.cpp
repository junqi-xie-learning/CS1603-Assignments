class orderArray
{
private:
    int *array;
    int size, buffer;
    bool sorted;
    void sort();

public:
    orderArray(int n);
    ~orderArray();
    void add(int x);
    int findnum(int i);
    void show();
};

void orderArray::sort()
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < i; ++j)
            if (array[j] > array[i])
                swap(array[j], array[i]);
    sorted = true;
}

orderArray::orderArray(int n)
    :array{ new int[n] }, size{ 0 }, buffer{ n }, sorted{ true } { }

orderArray::~orderArray()
{
    delete[] array;
}

void orderArray::add(int x)
{
    if (!buffer)
    {
        int *new_array = new int[2 * size];
        for (int i = 0; i < size; ++i)
            new_array[i] = array[i];

        delete[] array;
        array = new_array;
        buffer = size;
    }

    array[size] = x;
    if (size > 0 && array[size] < array[size - 1])
        sorted = false;
    ++size;
    --buffer;
}

int orderArray::findnum(int i)
{
    if (!sorted)
        sort();
    return array[i];
}

void orderArray::show()
{
    if (!sorted)
        sort();
    for (int i = 0; i < size - 1; ++i)
        cout << array[i] << ' ';
    cout << array[size - 1] << endl;
}