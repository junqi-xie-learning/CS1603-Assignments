#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
    char *first_name;
    char *last_name;
    char *social_security_number;

public:
    Employee(const char *first, const char *last, const char *ssn);
    ~Employee() { delete[] first_name; delete[] last_name; delete[] social_security_number; }
    virtual void print() const;
    virtual int earnings() const = 0;
};

Employee::Employee(const char *first, const char *last, const char *ssn)
    :first_name{ new char[strlen(first) + 1] },
    last_name{ new char[strlen(last) + 1] },
    social_security_number{ new char[strlen(ssn) + 1] }
{
    strcpy(first_name, first);
    strcpy(last_name, last);
    strcpy(social_security_number, ssn);
}

void Employee::print() const
{
    cout << "employee: " << first_name << ' ' << last_name << endl;
    cout << "social security number: " << social_security_number << endl;
}


class SalariedEmployee : public Employee
{
private:
    int salary;

public:
    SalariedEmployee(const char *first, const char *last, const char *ssn, int s);
    virtual void print() const;
    virtual int earnings() const { return salary; }
};

SalariedEmployee::SalariedEmployee(const char *first, const char *last, const char *ssn, int s)
    :Employee{ first, last, ssn }, salary{ s } { }

void SalariedEmployee::print() const
{
    cout << "salaried ";
    Employee::print();
    cout << "weekly salary: " << salary;
}


class HourlyEmployee : public Employee
{
private:
    double wage;
    int hours;

public:
    HourlyEmployee(const char *first, const char *last, const char *ssn, double w, int h);
    virtual void print() const;
    virtual int earnings() const;
};

HourlyEmployee::HourlyEmployee(const char *first, const char *last, const char *ssn, double w, int h)
    :Employee{ first, last, ssn }, wage{ w }, hours{ h } { }

void HourlyEmployee::print() const
{
    cout << "hourly ";
    Employee::print();
    cout << "hourly wage: " << wage << "; hours worked: " << hours;
}

int HourlyEmployee::earnings() const
{
    if (hours <= 40)
        return wage * hours;
    else
        return wage * 40 + 2 * wage * (hours - 40);
}


class CommissionEmployee : public Employee
{
private:
    int sales;
    double rate;

public:
    CommissionEmployee(const char *first, const char *last, const char *ssn, int s, double r);
    virtual void print() const;
    virtual int earnings() const { return sales * rate; }
};

CommissionEmployee::CommissionEmployee(const char *first, const char *last, const char *ssn, int s, double r)
    :Employee{ first, last, ssn }, sales{ s }, rate{ r } { }

void CommissionEmployee::print() const
{
    cout << "commission ";
    Employee::print();
    cout << "gross sales: " << sales << "; commission rate: " << rate;
}


class BasePlusCommissionEmployee : public CommissionEmployee
{
private:
    int base;

public:
    BasePlusCommissionEmployee(const char *first, const char *last, const char *ssn, int s, double r, int b);
    virtual void print() const;
    virtual int earnings() const { return base + CommissionEmployee::earnings(); }
};

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const char *first, const char *last, const char *ssn, int s, double r, int b)
    :CommissionEmployee{ first, last, ssn, s, r }, base{ b } { }

void BasePlusCommissionEmployee::print() const
{
    cout << "base-salaried ";
    CommissionEmployee::print();
    cout << "; base salary: " << base;
}


void virtualViaPointer(const Employee *e)
{
    e->print();
    cout << "\nearned $" << e->earnings() << "\n\n";
}

void virtualViaReference(const Employee &e)
{
    e.print();
    cout << "\nearned $" << e.earnings() << "\n\n";
}