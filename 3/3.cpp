#include <iostream>
using namespace std;

int main()
{
    int num1 = 0, num2 = 0;
    cin >> num1 >> num2;

    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl
        << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    if (num2 != 0)
        cout << num1 << " / " << num2 << " = " << num1 / num2 << endl
            << num1 << " % " << num2 << " = " << num1 % num2 << endl;
    else
        cout << num1 << " / " << num2 << ": Error!" << endl
            << num1 << " % " << num2 << ": Error!" << endl;
    return 0;
}