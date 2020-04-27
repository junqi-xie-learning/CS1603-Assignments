#include "management.h"

Student *get_by_id(int id)
{
    for (Student *p = student_list; p != student_list + student_size; ++p)
        if (p->student_id == id)
            return p;
    return nullptr;
}