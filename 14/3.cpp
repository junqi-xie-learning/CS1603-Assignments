#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Student
{
private:
    char name[20];
    char birth[7];
    char phone[12];
public:
    Student(const char *n, const char *b, const char *p);

    const char *get_name() const { return name; }
    const char *get_birth() const { return birth; }
    const char *get_phone() const { return phone; }

    void set_birth(const char *new_birth) { strcpy(birth, new_birth); }
    void set_phone(const char *new_phone) { strcpy(phone, new_phone); }
};

Student::Student(const char *n, const char *b, const char *p)
{
    strcpy(name, n);
    strcpy(birth, b);
    strcpy(phone, p);
}

ostream &operator<<(ostream &os, const Student &s)
{
    os.fill('\0');
    os << left << setw(20) << s.get_name()
        << left << setw(7) << s.get_birth()
        << left << setw(12) << s.get_phone();
    return os;
}

class Management
{
private:
    fstream ifs;
    ofstream ofs;
    long long int max_student_no;

    static int offset;

    void find_pos(long long int student_no);
public:
    Management(const char *file);
    ~Management() { ifs.close(); ofs.close(); }
    
    Student find(long long int student_no);
    void replace(long long int student_no, const Student &new_student);
    void append(const Student &new_student);
};

int Management::offset = 1 + 20 + 7 + 12;

void Management::find_pos(long long int student_no)
{
    ifs.clear();
    ifs.seekg(0, ios_base::beg);
    for (long long int i; ifs >> i; ifs.seekg(offset, ios_base::cur))
        if (student_no == i)
        {
            ifs.seekg(1, ios_base::cur);
            return;
        }
}

Management::Management(const char *file)
    :ifs{ file }, ofs{ file, ostream::app }, max_student_no{ 0 }
{
    for (long long int i; ifs >> i; ifs.seekg(offset, ios_base::cur))
        max_student_no = max(max_student_no, i);
}

Student Management::find(long long int student_no)
{
    find_pos(student_no);
    char name[20], birth[7], phone[12];
    ifs.get(name, 20);
    ifs.seekg(1, ios_base::cur);
    ifs.get(birth, 7);
    ifs.seekg(1, ios_base::cur);
    ifs.get(phone, 12);

    return Student{ name, birth, phone };
}

void Management::replace(long long int student_no, const Student &new_student)
{
    find_pos(student_no);
    ifs.seekp(ifs.tellg());
    ifs << new_student;
}

void Management::append(const Student &new_student)
{
    ++max_student_no;
    ofs.fill('0');
    ofs << setw(11) << max_student_no << '\0' << new_student;
}

void find_append(Management &management)
{
    long long int student_no;
    cin >> student_no;
    Student temp = management.find(student_no);
    management.append(temp);
}

void modify(Management &management)
{
    long long int student_no;
    char domain[6], new_value[12];
    cin >> domain >> student_no >> new_value;
    Student temp = management.find(student_no);
    if (!strcmp(domain, "phone"))
        temp.set_phone(new_value);
    else if (!strcmp(domain, "birth"))
        temp.set_birth(new_value);
    management.replace(student_no, temp);
}

void append(Management &Management)
{
    char name[12], birth[7], phone[12];
    cin >> name >> birth >> phone;
    Management.append(Student{ name, birth, phone });
}

int main()
{
    Management management{ "output.txt" };

    for (int i = 0; cin >> i; )
        switch (i)
        {
        case 1:
            find_append(management);
            break;
        case 2:
            modify(management);
            break;
        case 3:
            append(management);
            break;
        }
}