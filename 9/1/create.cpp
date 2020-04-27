#include "management.h"

Student *student_list;
int student_size = 0;

void create_list(int size)
{
    student_list = new Student[size];
}

void delete_list()
{
    delete[] student_list;
}