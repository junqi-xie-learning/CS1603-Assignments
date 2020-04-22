long long quickPow(int n, int k)
{
    if (k == 0)
        return 1;
    
    long long int result = quickPow(n, k / 2);
    if (k % 2 == 0)
        return result * result;
    else
        return n * result * result;
}