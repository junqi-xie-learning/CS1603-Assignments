#include <iostream>
using namespace std;

int main()
{
    constexpr int first_papers[] = { 50, 20, 10, 5, 1 };
    constexpr int second_papers[] = { 33, 23, 16, 5, 1 };

    int amount = 0;
    cin >> amount;

    // The first system: using greedy algorithm
    int number1 = 0, remains = amount;
    for (int i = 0; i < 5; ++i)
    {
        if (first_papers[i] <= remains)
        {
            int number_of_paper = remains / first_papers[i];
            number1 += number_of_paper;
            remains -= first_papers[i] * number_of_paper;
        }
    }
    
    // The second system: using enumeration
    int number2 = amount;
    for (int i = amount / second_papers[0]; i >= 0; --i)
    {
        int amount1 = amount - second_papers[0] * i;
        for (int j = amount1 / second_papers[1]; j >= 0; --j)
        {
            int amount2 = amount1 - second_papers[1] * j;
            for (int k = amount2 / second_papers[2]; k >= 0; --k)
            {
                int amount3 = amount2 - second_papers[2] * k;
                for (int l = amount3 / second_papers[3]; l >= 0; --l)
                {
                    int amount4 = amount3 - second_papers[3] * l;
                    int new_number = i + j + k + l + amount4;
                    if (new_number < number2)
                        number2 = new_number;
                }
            }
        }
    }

    cout << number1 << ' ' << number2 << endl;
    return 0;
}