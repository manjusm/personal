#include "constructors.h"

Person::Person() {
    //Default constructor
    cout<<"In default constructor"<<endl;
    this->age = 0;
    this->name = "";
}

Person::Person(int age, string name) {
    //parameterized constructor
    cout<<"Parameterized constructor"<<endl;
    this->age = age;
    this->name = name;
}

void Person::showPerson(void) {
    cout<<"in showConstructor"<<endl;
    cout<<this->age<<endl;
    cout<<this->name<<endl;
}

Person::~Person() {
    //Destructor
    cout<<"In destructor"<<endl;
}
