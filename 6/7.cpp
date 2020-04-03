void force(long long int stream[], int size)
{
    for (int i = 0; i < size - 1; ++i)
        stream[i] = stream[i + 1];
    stream[size - 1] = stream[size - 2] + stream[size - 3];
}

long long int fib()
{
    static long long int stream[3] = { 0, 0, 1 };
    force(stream, 3);
    return stream[1];
}