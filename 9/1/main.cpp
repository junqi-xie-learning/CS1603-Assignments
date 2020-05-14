#include "management.h"

// Functions for the specific program
// Mostly the functions involving input and output

void read_add_student()
{
    Student temp{ };
    read_student(temp);
    add_student(temp);
}

void modify_student()
{
    int student_id = 0;
    cin >> student_id;
    Student *temp = get_by_id(student_id);
    if (!temp)
    {
        cout << "Not found." << endl;
        cin.ignore(20, '\n');
        return;
    }

    char op[3] = { };
    cin >> op;
    if (strcmp(op, "ID") == 0)
        cin >> temp->student_id;
    else if (strcmp(op, "N") == 0)
        cin >> temp->name;
    else if (strcmp(op, "C") == 0)
        cin >> temp->chinese;
    else if (strcmp(op, "M") == 0)
        cin >> temp->math;
    else if (strcmp(op, "E") == 0)
        cin >> temp->english;
}

void output_by_id()
{
    int student_id = 0;
    cin >> student_id;
    Student *output = get_by_id(student_id);
    if (output)
        output_student(*output);
    else
        cout << "Not found." << endl;
}

void output_by_name()
{
    sort(comp_by_id);
    char name[16] = { };
    cin >> name;
    bool found = false;
    for (Student *p = student_list; p != student_list + student_size; ++p)
        if (strcmp(p->name, name) == 0)
        {
            found = true;
            output_student(*p);
        }
    if (!found)
        cout << "Not found." << endl;
}

int comp_by_total_decending(const Student &s1, const Student &s2)
{
    if (total(s2) - total(s1) != 0)
        return total(s2) - total(s1);
    else
        return comp_by_id(s1, s2);
}

int main()
{
    int T = 0;
    cin >> T;
    create_list(T);

    for (int i = 0; i < T; ++i)
    {
        int op = 0;
        cin >> op;
        switch (op)
        {
        case 1:
            read_add_student();
            break;
        case 2:
            modify_student();
            break;
        case 3:
            output_by_id();
            break;
        case 4:
            output_by_name();
            break;
        case 5:
            sort(comp_by_id);
            output_all();
            break;
        case 6:
            sort(comp_by_total_decending);
            output_all();
            break;
        }
    }

    delete_list();
    return 0;
}