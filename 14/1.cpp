#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student
{
private:
    char student_id[13];
    int chinese, math, english;

public:
    Student(const char *si, int c, int m, int e);

    const char *get_student_id() const { return student_id; }
    int get_chinese() const { return chinese; }
    int get_math() const { return math; }
    int get_english() const { return english; }
    int get_total() const { return chinese + math + english; }
};

Student::Student(const char *si, int c, int m, int e)
    : chinese{ c }, math{ m }, english{ e }
{
    strcpy(student_id, si);
}

int main()
{
    Student *list[10000] = { };

    // input from file
    ifstream ifs{ "score.txt" };

    int total = 0;
    char student_id[13] = { };
    int chinese = 0, math = 0, english = 0;
    while (ifs >> student_id >> chinese >> math >> english)
    {
        list[total] = new Student{ student_id, chinese, math, english };
        ++total;
    }
    ifs.close();

    // sort by total
    for (int i = 1; i < total; ++i)
    {
        bool flag = false;
        for (int j = 0; j < total - i ; ++j)
            if (list[j + 1]->get_total() > list[j]->get_total())
            {
                Student *tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
                flag = true;
            }
        if (!flag)
            break;
    }
    
    // output the result
    ofstream ofs{ "final.txt" };
    for (int i = 0; i < total; ++i)
        ofs << list[i]->get_student_id() << ' '
            << list[i]->get_chinese() << ' '
            << list[i]->get_math() << ' '
            << list[i]->get_english() << ' '
            << list[i]->get_total() << endl;
    ofs.close();
    
    // clean up
    for (int i = 0; i < total; ++i)
        delete list[i];
    return 0;
}