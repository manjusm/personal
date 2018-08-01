#include <iostream>
#include <string>
#include "person.h"

using namespace std;

person::person() {
    /* Default construcor */
    cout<<"In person() default constructor"<<endl;
}

person::person(string name, int age) {
    this->name = name;
    this->age = age;
    cout<<"In Person(string, int) constructor"<<endl;
}

void person::setAge(int age) {
    this->age = age;
}

void person::getNameAge() const {
    cout<<"Name : "<<this->name<<endl;
    cout<<"age : "<<this->age<<endl;
}
