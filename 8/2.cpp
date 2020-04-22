#include <iostream>
#include <cstring>
using namespace std;

struct Score
{
    char name[20] = { };
    int chinese = 0;
    int math = 0;
    int english = 0;
};

int total(const Score &s)
{
    return s.chinese + s.math + s.english;
}

int comp(const Score &s1, const Score &s2)
{
    if (total(s1) != total(s2))
        return total(s1) - total(s2);
    else if (s1.chinese != s2.chinese)
        return s1.chinese - s2.chinese;
    else if (s1.math != s2.math)
        return s1.math - s2.math;
    else if (s1.english != s2.english)
        return s1.english - s2.english;
    else
        return -strcmp(s1.name, s2.name);
}

int main()
{
    int n = 0;
    cin >> n;
    Score *students = new Score[n]{};
    for (int i = 0; i < n; ++i)
        cin >> students[i].name >> students[i].chinese >> students[i].math >> students[i].english;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (comp(students[j], students[i]) < 0)
            {
                Score temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
    
    int k = 0;
    cin >> k;
    cout << students[k - 1].name << ' ' << total(students[k - 1]);
    delete[] students;
    return 0;
}