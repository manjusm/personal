#pragma once

#include "person.h"

class student:public person
{
    private:
        string course;
        int roll_number;

    public:
        student();
        student(string name, int age, string course, int roll_number);
        void getDetails() const;
};
