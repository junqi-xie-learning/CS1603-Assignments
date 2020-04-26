#include "admin.h"

int total(const Student &s)
{
    return s.chinese + s.math + s.english;
}

int comp_by_id(const Student &s1, const Student &s2)
{
    return s1.student_id - s2.student_id;
}

void read_student(Student &s)
{
    cin >> s.student_id >> s.name >> s.chinese >> s.math >> s.english;
}

void output_student(const Student &s)
{
    cout << setw(4) << s.student_id
         << setw(16) << s.name
         << setw(4) << s.chinese
         << setw(4) << s.math
         << setw(4) << s.english << endl;
}

Student *get_by_id(int id)
{
    for (Student *p = student_list; p != student_list + student_size; ++p)
        if (p->student_id == id)
            return p;
    return nullptr;
}

void add_student(const Student &s)
{
    if (get_by_id(s.student_id))
    {
        cout << "Duplicate detected." << endl;
        return;
    }
    student_list[student_size] = s;
    ++student_size;
}

void sort(int (*comp)(const Student&, const Student&))
{
    for (Student *p = student_list; p != student_list + student_size; ++p)
        for (Student *q = student_list; q != p; ++q)
            if (comp(*q, *p) > 0)
            {
                Student temp = *p;
                *p = *q;
                *q = temp;
            }
}

void output_all()
{
    for (Student *p = student_list; p != student_list + student_size; ++p)
        output_student(*p);
}