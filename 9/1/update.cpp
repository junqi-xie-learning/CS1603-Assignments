#include "management.h"

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