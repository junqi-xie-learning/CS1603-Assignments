class Josephus
{
private:
    bool *cycle;
    const int n, m;
    int sum();

public:
    Josephus(int num, int gap);
    ~Josephus();
    void simulate();
};

int Josephus::sum()
{
    int s = 0;
    for (bool *p = cycle; p != cycle + n; ++p)
        s += *p;
    return s;
}

Josephus::Josephus(int num, int gap)
    : cycle{new bool[num]}, n{num}, m{gap}
{
    for (int i = 0; i < n; ++i)
        cycle[i] = true;
}

void Josephus::simulate()
{
    int current = 0;
    while (sum())
    {
        for (int i = 0; i < m; ++i)
        {
            current = (current + 1) % n;
            while (!cycle[current])
                current = (current + 1) % n;
        }
        cycle[current] = false;
        cout << current + 1 << endl;
    }
}

Josephus::~Josephus()
{
    delete[] cycle;
}