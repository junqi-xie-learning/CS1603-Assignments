#include <iostream>
using namespace std;

int main()
{
    long long int num1 = 0, num2 = 0;
    char op = 0;
    cin >> num1 >> op >> num2;

    long long int result = 0;
    switch (op)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    }

    cout << result << endl;
    return 0;
}