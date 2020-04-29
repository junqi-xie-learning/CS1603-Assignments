class Complex
{
    int real, imag;

public:
    Complex(int r = 0, int i = 0);
    int get_real() const { return real; }
    int get_imag() const { return imag; }

    void add(const Complex &c1, const Complex &c2);
    void display() const;
};

Complex::Complex(int r, int i)
    : real{ r }, imag{ i } { }

void Complex::add(const Complex &c1, const Complex &c2)
{
    real = c1.get_real() + c2.get_real();
    imag = c1.get_imag() + c2.get_imag();
}

void Complex::display() const
{
    cout << '(';
    if (real != 0 || imag == 0)
        cout << real;
    if (real != 0 && imag > 0)
        cout << '+';
    if (imag != 0)
        cout << imag << 'i';
    cout << ')';
}