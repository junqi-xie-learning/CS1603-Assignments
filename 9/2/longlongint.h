#ifndef LONGLONGINT
#define LONGLONGINT

#include <iostream>
#include <cstring>
using namespace std;

struct Long_long_int
{
    char int_rep[200] = { };
};

void read_int(Long_long_int &li);
Long_long_int add_int(const Long_long_int &li1, const Long_long_int &li2);
void output_int(const Long_long_int &li);

#endif