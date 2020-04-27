#ifndef MANAGEMENT
#define MANAGEMENT

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Student
{
    int student_id = 0;
    char name[16] = {};
    int chinese = 0;
    int math = 0;
    int english = 0;
};

// Create
extern Student *student_list;
extern int student_size;
void create_list(int size);
void delete_list();

// Query
Student *get_by_id(int id);

// Update
void add_student(const Student &s);
// The rest of the modifications can be achieved using assignment operator.

// Utils
int total(const Student &s);
int comp_by_id(const Student &s1, const Student &s2);
void read_student(Student &s);
void output_student(const Student &s);

void sort(int (*comp)(const Student&, const Student&));
void output_all();

#endif