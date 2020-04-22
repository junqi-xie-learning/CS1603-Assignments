void print(int n)
{
    static int blanks = 0;
    if (n > 1)
    {
        ++blanks;
        print(n - 1);
        --blanks;
    }
    
    for (int i = 0; i < blanks; ++i)
        cout << ' ';
    for (int i = 0; i < 2 * n - 1; ++i)
        cout << '*';
    cout << endl;
}