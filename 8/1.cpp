struct my_complex
{
    int real = 0;
    int imag = 0;
};

my_complex *read_complex()
{
    my_complex *comp = new my_complex{ };
    cin >> comp->real >> comp->imag;
    return comp;
}

my_complex *add_complex(const my_complex *a, const my_complex *b)
{
    my_complex *res = new my_complex{ };
    res->real = a->real + b->real;
    res->imag = a->imag + b->imag;
    return res;
}

void print_complex(const my_complex *a)
{
    cout << a->real << '+' << a->imag << 'i';
}