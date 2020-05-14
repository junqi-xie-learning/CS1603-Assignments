#include <iomanip>

class SavingAccount
{
private:
    static int number_of_account;
    int id;
    double money, rate;
public:
    SavingAccount(double init);

    void changerate(double new_rate) { rate = new_rate; }
    void calculate();
    void display() const;
};

int SavingAccount::number_of_account = 0;

SavingAccount::SavingAccount(double init)
    :id{ number_of_account + 1 }, money{ init }, rate{ 0.05 }
{
    ++number_of_account;
}

void SavingAccount::calculate()
{
    money *= 1 + rate;
}

void SavingAccount::display() const
{
    cout << id << ' '
        << fixed << setprecision(2)
        << money << ' '
        << rate << endl;
}