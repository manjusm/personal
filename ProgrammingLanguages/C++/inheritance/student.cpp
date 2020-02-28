#include "student.h"
#include <string>
#include <iostream>

using namespace std;

student::student(){
    /* Default constructor */
    cout<<"In student() default constructor"<<endl;
}

student::student(string name, int age, string course, int roll_number) : person(name, age) {
    this->course = course;
    this->roll_number = roll_number;

    cout<<"In student(string, int) constructor"<<endl;
}

void student::getDetails() const {
    cout<<"Course : " <<this->course<<endl;
    cout<<"Roll number : "<<this->roll_number<<endl;
}
